/*
** port.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/cmd
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 17 14:56:53 2017 DESKTOP-DHNB9O5
** Last update Sun May 21 08:11:54 2017 DESKTOP-DHNB9O5
*/

#define			_GNU_SOURCE
#include		<ctype.h>
#include		<malloc.h>
#include		<stdio.h>
#include		<stdlib.h>
#include		<string.h>
#include		"bool.h"
#include		"cmd.h"
#include		"core.h"

static int		is_nbr(char *str)
{
  size_t		idx;

  idx = 0;
  while (str[idx] != '\0')
    {
      if (!isdigit(str[idx]))
	return (FALSE);
      idx++;
    }
  return (TRUE);
}

static int		host_port_is_valid(char *host_port)
{
  char			*ip[4];
  char			*port[2];

  ip[0] = strtok(host_port, ",");
  ip[1] = strtok(NULL, ",");
  ip[2] = strtok(NULL, ",");
  ip[3] = strtok(NULL, ",");
  port[0] = strtok(NULL, ",");
  port[1] = strtok(NULL, SP);
  if (!ip[0] || !ip[1] || !ip[2] || !ip[3]
      || !port[0] || !port[1])
    return (FALSE);
  if (!is_nbr(ip[0]) || !is_nbr(ip[1])
      || !is_nbr(ip[2]) || !is_nbr(ip[3])
      || !is_nbr(port[0]) || !is_nbr(port[1]))
    return (FALSE);
  return (TRUE);
}

static char		*get_ip(char *host_port)
{
  char			*ip;
  char			*token[4];

  token[0] = strtok(host_port, ",");
  token[1] = strtok(NULL, ",");
  token[2] = strtok(NULL, ",");
  token[3] = strtok(NULL, ",");
  asprintf(&ip, "%s.%s.%s.%s", token[0],
	   token[1], token[2], token[3]);
  return (ip);
}

static int		get_port(void)
{
  int			port;
  char			*token[2];

  token[0] = strtok(NULL, ",");
  token[1] = strtok(NULL, SP);
  port = atoi(token[0]) * 256 + atoi(token[1]);
  return (port);
}

void			port(const socket_t csock,
			     t_config_user *config)
{
  char			*host_port;
  char			*s_host_port;
  char			*ip;
  int			port;
  
  if (!is_logged(csock, config))
    return ;
  host_port = strtok(NULL, SP);
  if (host_port)
    s_host_port = strdup(host_port);
  if (!host_port || !host_port_is_valid(host_port))
    {
      dprintf(csock, "500 Syntax error.%s", CRLF);
      return ;
    }
  ip = get_ip(s_host_port);
  port = get_port();
  if (!port_set_socket(csock, config, ip, port))
    dprintf(csock, "425 Can't open data connection.%s", CRLF);
  free(ip);
  free(s_host_port);
}
