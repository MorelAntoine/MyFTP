/*
** is_logged.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/core
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 17 11:17:38 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 13:09:03 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"bool.h"
#include		"core.h"

int			is_logged(const socket_t csock,
				  t_config_user *config)
{
  if (config->logged)
    return (TRUE);
  dprintf(csock, "530 Not logged in.%s", CRLF);
  return (FALSE);
}
