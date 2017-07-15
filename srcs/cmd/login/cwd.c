/*
** cwd.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Sun May 14 16:49:01 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 16:44:18 2017 DESKTOP-DHNB9O5
*/

#include		<string.h>
#include		<sys/stat.h>
#include		<stdio.h>
#include		"core.h"

void			cwd(const socket_t csock,
			    t_config_user *config)
{
  char			*dir;
  struct stat		st;

  if (!is_logged(csock, config))
    return ;
  dir = strtok(NULL, SP);
  if (dir)
    {
      if (stat(dir, &st) == 0)
	{
	  if (S_ISDIR(st.st_mode))
	    {
	      if (chdir(dir) == 0)
		{
		  dprintf(csock,
			  "250 Requested file action okay, completed.%s",
			  CRLF);
		  return ;
		}
	    }
	}
    }
  dprintf(csock, "550 Requested file action not taken.%s", CRLF);
}
