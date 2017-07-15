/*
** port_set_socket.c for myftp in /mnt/d/Projects/C/PSU_2016_myftp/srcs/cmd/transfer_parameters
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 19 15:59:55 2017 DESKTOP-DHNB9O5
** Last update Fri May 19 18:38:15 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"bool.h"
#include		"cmd.h"
#include		"core.h"

int			port_set_socket(const socket_t csock,
					t_config_user *config,
					char *ip, int port)
{
  sockaddr_in		sin;
  
  if (!socket_create(&config->dsock))
    return (FALSE);
  sin.sin_addr.s_addr = inet_addr(ip);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  dprintf(csock, "200 PORT command successful.%s", CRLF);
  config->active_mode = TRUE;
  config->dsin = sin;
  return (TRUE);
}
