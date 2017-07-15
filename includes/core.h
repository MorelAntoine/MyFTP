/*
** core.h for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 10 15:52:18 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 07:49:04 2017 DESKTOP-DHNB9O5
*/

#ifndef				CORE_H_
# define			CORE_H_

/*
** INCLUDES
*/

#include			"socket.h"

/*
** STRUCT
*/

typedef struct			s_config_user
{
  int				active_mode;
  sockaddr_in			dsin;
  socket_t			dsock;
  int				logged;
  int				logout;
  int				passive_mode;
  char				*username;
}				t_config_user;

typedef struct			s_ftp_cmd
{
  char				*name;
  void				(*func)(const socket_t csock,
					t_config_user *config);
}				t_ftp_cmd;

/*
** PROTOTYPES
*/

int				is_logged(const socket_t csock,
					  t_config_user *config);
void				mainloop(socket_t csock);

#endif				/* !CORE_H_ */
