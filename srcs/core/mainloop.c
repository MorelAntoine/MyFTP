/*
** mainloop.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/core
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 10 15:23:44 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 14:27:29 2017 DESKTOP-DHNB9O5
*/

#include		<malloc.h>
#include		<string.h>
#include		"bool.h"
#include		"cmd.h"
#include		"core.h"
#include		"get_next_line.h"

static const t_ftp_cmd	ftp_cmds[] =
  {
    { "CDUP", &cdup },
    { "CWD", &cwd },
    { "DELE", &dele },
    { "HELP", &help },
    { "LIST", &list },
    { "NOOP", &noop },
    { "PASS", &pass },
    { "PASV", &pasv },
    { "PORT", &port },
    { "PWD", &pwd },
    { "QUIT", &quit },
    { "RETR", &retr },
    { "STOR", &stor },
    { "USER", &user },
    { NULL, NULL }
  };

static void		set_config(t_config_user *config)
{
  config->active_mode = FALSE;
  config->dsock = -1;
  config->logged = FALSE;
  config->logout = FALSE;
  config->passive_mode = FALSE;
  config->username = NULL;
}

static void		dispatcher(const socket_t csock,
				   const char * const token,
				   t_config_user *config)
{
  size_t		idx;

  idx = 0;
  //printf("%s\n", token);
  while (ftp_cmds[idx].func)
    {
      if (strcmp(ftp_cmds[idx].name, token) == 0)
	break;
      idx++;
    }
  if (ftp_cmds[idx].func)
    ftp_cmds[idx].func(csock, config);
  else
    dprintf(csock, "500 Command not implemented.%s", CRLF);
}

void			mainloop(socket_t csock)
{
  char			*cmd;
  char			*token;
  t_config_user		config;

  set_config(&config);
  while (!config.logout)
    {
      cmd = get_next_line(csock);
      if (!cmd)
	quit(csock, &config);
      cmd[strlen(cmd) - 1] = '\0';
      token = strtok(cmd, SP);
      if (token)
	dispatcher(csock, token, &config);
      else
	dprintf(csock, "500 command not implemented.%s", CRLF);
      free(cmd);
    }
}
