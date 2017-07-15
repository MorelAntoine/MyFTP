/*
** main.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May  9 11:40:57 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 12:56:33 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<stdlib.h>
#include		"myftp.h"

static void		display_usage(const char * const binary_name)
{
  printf("Usage : %s port path\n", binary_name);
}

static int		close_communication(socket_t sock, socket_t csock)
{
  if (close_socket(csock) == -1)
    {
      perror("myftp : close_socket()");
      if (close_socket(sock) == -1)
	perror("myftp : close_socket()");
      return (FALSE);
    }
  if (close_socket(sock) == -1)
    {
      perror("myftp : close_socket()");
      return (FALSE);
    }
  return (TRUE);
}

static int		myftp(const int port, const char * const path)
{
  socket_t		sock;
  socket_t		csock;

  sock = 0;
  csock = 0;
  if (!socket_initialize(&sock, &csock, port))
    return (FALSE);
  if (chdir(path) == -1)
    {
      perror("myftp : chdir()");
      close_communication(sock, csock);
      return (FALSE);
    }
  dprintf(csock, "220 Connection Establishment.%s", CRLF);
  mainloop(csock);
  if (!close_communication(sock, csock))
    return (FALSE);
  return (TRUE);
}

int			main(int argc, char **argv)
{
  if (!check_args(argc, argv))
    {
      display_usage(argv[0]);
      return (EXIT_FAILURE);
    }
  if (!myftp(atoi(argv[1]), argv[2]))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
