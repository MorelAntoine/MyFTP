/*
** pasv.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/cmd
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 17 14:56:07 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 08:08:58 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"bool.h"
#include		"core.h"

void			pasv(const socket_t csock,
			     t_config_user *config)
{
  if (!is_logged(csock, config))
    return ;
  if (!socket_create(&config->dsock))
    {
      dprintf(csock, "425 Can't open data connection.%s", CRLF);
      return ;
    }
  if (!socket_bind(&config->dsock, DPORT))
    {
      dprintf(csock, "425 Can't open data connection.%s", CRLF);
      close_socket(config->dsock);
      return ;
    }
  if (!socket_listen(&config->dsock))
    {
      dprintf(csock, "425 Can't open data connection.%s", CRLF);
      close_socket(config->dsock);
      return ;
    }
  dprintf(csock,
	  "227 127,0,0,1,%d,%d%s",
	  DPORT / 256, DPORT % 256, CRLF);
  config->passive_mode = TRUE;
}
