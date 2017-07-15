/*
** check.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/args
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Tue May  9 14:05:28 2017 DESKTOP-DHNB9O5
** Last update Tue May  9 14:19:04 2017 DESKTOP-DHNB9O5
*/

#include		<ctype.h>
#include		<stdio.h>
#include		<sys/stat.h>
#include		"bool.h"

static int		check_port(const char * const port)
{
  int			index;

  index = 0;
  while (port[index] != '\0')
    {
      if (!isdigit(port[index]))
	return (FALSE);
      index++;
    }
  return (TRUE);
}

static int		check_path(const char * const path)
{
  struct stat		st;

  if (stat(path, &st) != 0)
    return (FALSE);
  if (!S_ISDIR(st.st_mode))
    return (FALSE);
  return (TRUE);
}

int			check_args(int argc, char **argv)
{
  if (argc != 3)
    return (FALSE);
  if (!check_port(argv[1]))
    return (FALSE);
  if (!check_path(argv[2]))
    return (FALSE);
  return (TRUE);
}
