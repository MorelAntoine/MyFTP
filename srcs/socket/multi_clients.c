/*
** multi_clients.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 10 14:40:57 2017 DESKTOP-DHNB9O5
** Last update Wed May 10 15:01:34 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"bool.h"
#include		"socket.h"

int			socket_multi_clients(socket_t *sock,
					     socket_t *csock)
{
  while (42)
    {
      if (!socket_accept(sock, csock))
	return (FALSE);
      if (fork() == 0)
	break;
      if (close_socket((*csock)) == -1)
	{
	  perror("socket_multi_client : close_socket()");
	  if (close_socket((*sock)) == -1)
	    perror("socket_multi_client : close_socket()");
	  return (FALSE);
	}
    }
  return (TRUE);
}
