/*
** stor.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 17 14:53:28 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 08:03:35 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"bool.h"
#include		"core.h"

static int		get_fd(socket_t csock)
{
  int			fd;
  char			*filename;
  
  filename = strtok(NULL, SP);
  if (!filename)
    {
      dprintf(csock, "550 Failed to open file.%s", CRLF);
      return (-1);
    }
  fd = open(filename, O_RDWR | O_CREAT);
  if (fd == -1)
    {
      dprintf(csock, "550 Failed to open file.%s", CRLF);
      return (-1);
    }
  return (fd);
}

static void		passive(const socket_t csock,
				t_config_user *config,
				socket_t dcsock)
{
  char			buff[4096];
  int			ret;
  int			fd;
  
  if (!socket_accept(&config->dsock, &dcsock))
    {
      dprintf(csock, "425 Can't open data connection.%s", CRLF);
      close_socket(config->dsock);
      return ;
    }
  fd = get_fd(csock);
  if (fd == -1)
    return ;
  dprintf(csock, "150 Here comes the directory listing.%s", CRLF);
  config->passive_mode = FALSE;
  bzero(buff, 4096);
  while ((ret = read(dcsock, buff, 4095)) != 0)
    {
      write(fd, buff, ret);
      bzero(buff, 4095);
    }
  dprintf(csock, "226 Directory send OK.%s", CRLF);
  close_socket(dcsock);
  close_socket(config->dsock);
  close(fd);
}

static void		active(const socket_t csock,
			       t_config_user *config)
{
  char			buff[4096];
  int			ret;
  int			fd;

  fd = get_fd(csock);
  if (fd == -1)
    return ;
  dprintf(csock, "150 Here comes the directory listing.%s", CRLF);
  config->active_mode = FALSE;
  bzero(buff, 4096);
  while ((ret = read(config->dsock, buff, 4095)) != 0)
    {
      write(fd, buff, ret);
      bzero(buff, 4095);
    }
  dprintf(csock, "226 Directory send OK.%s", CRLF);
  close_socket(config->dsock);
  close(fd);
}

void			stor(const socket_t csock,
			     t_config_user *config)
{
  int			dcsock;

  dcsock = 0;
  if (!is_logged(csock, config))
    return ;
  if (config->passive_mode)
    passive(csock, config, dcsock);
  else if (config->active_mode)
    {
      if (connect(config->dsock, (const sockaddr *)(&config->dsin),
		  sizeof(config->dsin)) == SOCKET_ERROR)
	{
	  dprintf(csock, "425 Can't open data connection.%s", CRLF);
	  close_socket(config->dsock);
	  return ;
	}
      active(csock, config);
    }
  else
    dprintf(csock, "425 Can't open data connection.%s", CRLF);
}
