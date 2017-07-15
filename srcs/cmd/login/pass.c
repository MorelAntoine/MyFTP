/*
** pass.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 12 21:14:44 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 14:38:16 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		"bool.h"
#include		"core.h"

void			pass(const socket_t csock,
			     t_config_user *config)
{
  char			*passwd;

  if (config->username)
    {
      passwd = strtok(NULL, SP);
      if (!passwd && strcmp(config->username, "Anonymous") == 0)
	{
	  config->logged = TRUE;
	  dprintf(csock, "230 User logged in, proceed.%s", CRLF);
	}
      else
	dprintf(csock, "530 Not logged in.%s", CRLF);
    }
  else
    dprintf(csock, "332 Need account for login.%s", CRLF);
}
