/*
** dele.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Sun May 14 17:13:54 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 07:55:22 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		<string.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		"core.h"

void			dele(const socket_t csock,
			     t_config_user *config)
{
  char			*file;
  int			fd;

  if (!is_logged(csock, config))
    return ;
  file = strtok(NULL, SP);
  if (file)
    {
      fd = open(file, O_RDONLY);
      if (fd != -1)
	{
	  close(fd);
	  remove(file);
	  dprintf(csock,
		  "250 Requested file action okay, completed.%s",
		  CRLF);
	  return ;
	}
    }
  dprintf(csock, "550 Requested file action not taken.%s", CRLF);
}
