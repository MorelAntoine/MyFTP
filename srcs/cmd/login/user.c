/*
** user.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Fri May 12 18:40:34 2017 DESKTOP-DHNB9O5
Last update Thu May 18 17:21:12 2017 DESKTOP-DHNB9O5
*/

#include		<malloc.h>
#include		<stdio.h>
#include		<string.h>
#include		"core.h"

void			user(const socket_t csock,
			     t_config_user *config)
{
  char			*username;

  username = strtok(NULL, SP);
  if (config->username)
    free(config->username);
  if (!username)
    config->username = strdup("");
  else
    config->username = strdup(username);
  if (!config->username)
    {
      perror("user : strdup()");
      return ;
    }
  dprintf(csock, "331 User name okay, need password.%s", CRLF);
}
