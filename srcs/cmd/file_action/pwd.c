/*
** pwd.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 12 21:36:44 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 15:00:17 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"core.h"

void			pwd(const socket_t csock,
			    t_config_user *config)
{
  char			*cwd;
  
  if (!is_logged(csock, config))
    return ;
  cwd = getcwd(NULL, 0);
  dprintf(csock, "257 %s%s", cwd, CRLF);
}
