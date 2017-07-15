/*
** noop.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Sun May 14 17:24:28 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 13:16:54 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"core.h"

void			noop(const socket_t csock,
			     t_config_user *config)
{
  if (!is_logged(csock, config))
    return ;
  dprintf(csock, "200 Command okay.%s", CRLF);
}
