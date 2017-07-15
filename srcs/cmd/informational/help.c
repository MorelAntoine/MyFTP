/*
** help.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Sun May 14 17:09:19 2017 DESKTOP-DHNB9O5
** Last update Thu May 18 13:12:10 2017 DESKTOP-DHNB9O5
*/

#include		<stdio.h>
#include		"core.h"

void			help(const socket_t csock,
			     t_config_user *config)
{
  (void)config;
  dprintf(csock, "214 USER, PASS, CWD, CDUP, QUIT, DELE%s%s",
	  ", PWD, PASV, PORT, HELP, NOOP, RETR, STOR, LIST", CRLF);
}
