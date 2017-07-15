/*
** initialize.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May  9 19:52:21 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 08:15:34 2017 DESKTOP-DHNB9O5
*/

#include		<netdb.h>
#include		<stdio.h>
#include		"bool.h"
#include		"socket.h"

int			socket_create(socket_t *sock)
{
  protoent		*pe;

  pe = getprotobyname("TCP");
  if (!pe)
    return (FALSE);
  (*sock) = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if ((*sock) == INVALID_SOCKET)
    {
      perror("socket_create : socket()");
      return (FALSE);
    }
  return (TRUE);
}

int			socket_bind(socket_t *sock, const int port)
{
  sockaddr_in		sin;

  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  if (bind((*sock), (const sockaddr *)(&sin), sizeof(sin))
      == SOCKET_ERROR)
    {
      perror("socket_bind : bind()");
      if (close_socket((*sock)) == -1)
	perror("socket_bind : close_socket()");
      return (FALSE);
    }
  return (TRUE);
}

int			socket_listen(socket_t *sock)
{
  if (listen((*sock), 4) == SOCKET_ERROR)
    {
      perror("socket_listen : listen()");
      if (close_socket((*sock)) == -1)
	perror("socket_listen : close_socket()");
      return (FALSE);
    }
  return (TRUE);
}

int			socket_accept(socket_t *sock, socket_t *csock)
{
  sockaddr_in		csin;
  socklen_t		csinsize;

  csinsize = sizeof(csin);
  (*csock) = accept((*sock), (sockaddr *)&csin, &csinsize);
  if ((*csock) == INVALID_SOCKET)
    {
      perror("socket_accept : accept()");
      if (close_socket((*sock)) == -1)
	perror("socket_accept : close_socket()");
      return (FALSE);
    }
  printf("Connection from %s\n", inet_ntoa(csin.sin_addr));
  return (TRUE);
}

int			socket_initialize(socket_t *sock, socket_t *csock,
					  const int port)
{
  if (!socket_create(sock))
    return (FALSE);
  if (!socket_bind(sock, port))
    return (FALSE);
  if (!socket_listen(sock))
    return (FALSE);
  if (!socket_multi_clients(sock, csock))
    return (FALSE);
  return (TRUE);
}
