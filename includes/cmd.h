/*
** cmd.h for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 12 18:12:22 2017 DESKTOP-DHNB9O5
** Last update Fri May 19 16:07:49 2017 DESKTOP-DHNB9O5
*/

#ifndef				CMD_H_
# define			CMD_H_

/*
** INCLUDES
*/

# include			"core.h"

/*
** PROTORYPES
*/

void				cdup(const socket_t csock,
				     t_config_user *config);
void				cwd(const socket_t csock,
				    t_config_user *config);
void				dele(const socket_t csock,
				     t_config_user *config);
void				help(const socket_t csock,
				     t_config_user *config);
void				list(const socket_t csock,
				     t_config_user *config);
void				noop(const socket_t csock,
				     t_config_user *config);
void				pass(const socket_t csock,
				     t_config_user *config);
void				pasv(const socket_t csock,
				     t_config_user *config);
void				port(const socket_t csock,
				     t_config_user *config);
int				port_set_socket(const socket_t csock,
						t_config_user *config,
						char *ip, int port);
void				pwd(const socket_t csock,
				    t_config_user *config);
void				quit(const socket_t csock,
				     t_config_user *config);
void				retr(const socket_t csock,
				     t_config_user *config);
void				stor(const socket_t csock,
				     t_config_user *config);
void				user(const socket_t csock,
				     t_config_user *config);

#endif				/* !CMD_H_ */
