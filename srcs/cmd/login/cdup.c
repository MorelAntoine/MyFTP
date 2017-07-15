/*
** cdup.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Sun May 14 16:59:17 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 14:55:32 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"core.h"

void			cdup(const socket_t csock,
			     t_config_user *config)
{
  if (!is_logged(csock, config))
    return ;
  if (chdir("..") == 0)
    dprintf(csock, "250 Requested file action okay, completed.%s", CRLF);
  else
    dprintf(csock, "550 Requested file action not taken.%s", CRLF);
}
