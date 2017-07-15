/*
** socket.h for myftp in /mnt/d/Projects/C/PSU_2017_myftp/includes/socket
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May  9 15:28:34 2017 DESKTOP-DHNB9O5
** Last update Wed May 17 20:35:34 2017 DESKTOP-DHNB9O5
*/

#ifndef				SOCKET_H_
# define			SOCKET_H_

/*
** INCLUDES
*/

# include 			<arpa/inet.h>
# include			<sys/types.h>
# include			<sys/socket.h>
# include			<unistd.h>

/*
** DEFINES
*/

# ifndef			INVALID_SOCKET
#  define			INVALID_SOCKET -1
# endif				/* !INVALID_SOCKET */

# ifndef			SOCKET_ERROR
#  define			SOCKET_ERROR -1
# endif				/* !SOCKET_ERROR */

# ifndef			CLOSE_SOCKET
#  define			close_socket(int) close(int)
# endif				/* !CLOSE_SOCKET */

# ifndef			SP
#  define			SP " "
# endif				/* !SP */

# ifndef			CRLF
#  define			CRLF "\r\n"
# endif				/* !CRLF */

# ifndef			DPORT
#  define			DPORT 1203
# endif				/* !DPORT */

/*
** TYPEDEFS
*/

typedef				struct protoent		protoent;
typedef				int			socket_t;
typedef				struct sockaddr_in	sockaddr_in;
typedef				struct sockaddr		sockaddr;
typedef				struct in_addr		in_addr;

/*
** PROTOTYPES
*/

int				socket_initialize(socket_t *sock,
						  socket_t *csock,
						  const int port);
int				socket_create(socket_t *sock);
int				socket_bind(socket_t *sock, const int port);
int				socket_listen(socket_t *sock);
int				socket_accept(socket_t *sock,
					      socket_t *csock);
int				socket_multi_clients(socket_t *sock,
						     socket_t *csock);

#endif				/* !SOCKET_H_ */
