/*
** quit.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/cmd/logout
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 12 18:14:15 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 13:16:18 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<malloc.h>
#include		"bool.h"
#include		"core.h"

void			quit(const socket_t csock,
			     t_config_user *config)
{
  config->logout = TRUE;
  config->logged = FALSE;
  if (config->username)
    free(config->username);
  dprintf(csock, "221 Service closing control connection%s", CRLF);
}
