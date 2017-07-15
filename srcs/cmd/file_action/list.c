/*
** list.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 17 14:43:07 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 07:58:28 2017 DESKTOP-DHNB9O5
*/

#define			_GNU_SOURCE
#include		<stdio.h>
#include		<string.h>
#include		<malloc.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"bool.h"
#include		"core.h"

static void		list_passive(const socket_t csock,
				     t_config_user *config,
				     char *cmd)
{
  socket_t		dcsock;
  FILE			*file;
  char			buff[4096];

  if (!socket_accept(&config->dsock, &dcsock))
    {
      dprintf(csock, "425 Can't open data connection.%s", CRLF);
      return ;
    }
  file = popen(cmd, "r");
  if (!file)
    {
      dprintf(csock, "425 Failed to open file.%s", CRLF);
      return ;
    }
  dprintf(csock,
	  "150 Here comes the directory listing.%s", CRLF);
  dprintf(csock, "226%s", CRLF);
  while (fgets(buff, 4095, file))
    dprintf(dcsock, "%s", buff);
  pclose(file);
  close_socket(dcsock);
  close_socket(config->dsock);
}

static void		list_active(const socket_t csock,
				    t_config_user *config,
				    char *cmd)
{
  FILE			*file;
  char			buff[4096];

  if (connect(config->dsock, (const sockaddr *)(&config->dsin),
	      sizeof(config->dsin)) == SOCKET_ERROR)
    {
      dprintf(csock, "425 Can't open data connection.%s", CRLF);
      close_socket(config->dsock);
      return ;
    }
  file = popen(cmd, "r");
  if (!file)
    {
      dprintf(csock, "425 Failed to open file.%s", CRLF);
      return ;
    }
  dprintf(csock,
	  "150 Here comes the directory listing.%s", CRLF);
  dprintf(csock, "226%s", CRLF);
  while (fgets(buff, 4095, file))
    dprintf(config->dsock, "%s", buff);
  pclose(file);
  close_socket(config->dsock);
}

static char		*get_cmd_pathname(char *pathname,
					  const socket_t csock,
					  t_config_user *config)
{
  char			*cmd;
  int			fd;

  fd = open(pathname, O_RDONLY);
  if (fd == -1)
    {
      config->passive_mode = FALSE;
      config->active_mode = FALSE;
      close_socket(config->dsock);
      dprintf(csock, "425 Failed to open file.%s", CRLF);
      return (NULL);
    }
  asprintf(&cmd, "ls -la %s", pathname);
  close(fd);
  return (cmd);
}

void			list(const socket_t csock,
			     t_config_user *config)
{
  char			*pathname;
  char			*cmd;

  cmd = NULL;
  if (!is_logged(csock, config))
    return ;
  pathname = strtok(NULL, SP);
  if (pathname)
    cmd = get_cmd_pathname(pathname, csock, config);
  else
    asprintf(&cmd, "ls -la");
  if (!cmd)
    return ;
  if (config->passive_mode)
    list_passive(csock, config, cmd);
  else if (config->active_mode)
    list_active(csock, config, cmd);
  else
    dprintf(csock, "425 Can't open data connection.%s", CRLF);
  config->passive_mode = FALSE;
  config->active_mode = FALSE;
  if (cmd)
    free(cmd);
}
