/*
** get_next_line.c for myftp in /mnt/d/Projects/C/PSU_2017_myftp/srcs/core
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 10 16:53:49 2017 DESKTOP-DHNB9O5
** Last update Wed May 10 16:53:50 2017 DESKTOP-DHNB9O5
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"get_next_line.h"

static	int	my_strlen(char *str)
{
  int		i;

  i = 0;
  if (str != NULL)
    {
      while (str[i] != '\0')
	{
	  i = i + 1;
	}
    }
  return (i);
}

static	int	clear_save(char **save, int begin)
{
  char		*tmp;
  int		i;

  if ((*save) != NULL && (*save)[begin] == '\0')
    {
      free((*save));
      (*save) = NULL;
    }
  else
    {
      tmp = malloc((my_strlen((*save)) - begin + 1) * sizeof(char));
      if (tmp == NULL)
	return (-1);
      i = 0;
      while ((*save)[++begin] != '\0')
	{
	  tmp[i] = (*save)[begin];
	  i++;
	}
      tmp[i] = '\0';
      free((*save));
      (*save) = tmp;
    }
  return (0);
}

static	char	*my_strcat(char *dest, char *src, int rd)
{
  int		i;
  int		j;
  char		*tmp;
  int		f;

  j = 0;
  f = 0;
  if ((tmp = malloc((my_strlen(dest) + 1 + rd) * sizeof(char)))
      == NULL)
    return (NULL);
  i = my_strlen(dest);
  while (dest != NULL && dest[f])
    {
      tmp[f] = dest[f];
      f++;
    }
  f = 0;
  while (f < rd)
    {
      tmp[i++] = src[j++];
      f++;
    }
  tmp[i] = '\0';
  free(dest);
  return (tmp);
}

static	int	read_me(const int fd, char **save)
{
  t_read	me;

  me.stop = 0;
  me.ret = 1;
  while (me.stop == 0 && me.ret != 0)
    {
      if ((me.ret = read(fd, me.buffer, READ_SIZE)) != 0)
	{
	  if (me.ret == -1)
	    return (-1);
	  me.buffer[me.ret] = '\0';
	  if (((*save) = my_strcat((*save), me.buffer, me.ret)) == NULL)
	    return (-1);
	  me.i = 0;
	  if ((*save)[0] == '\n' || (*save)[0] == '\0')
	    return (1);
	  while ((*save)[me.i] != '\n' && (*save)[me.i] != '\0')
	    {
	      me.i++;
	      if ((*save)[me.i] == '\n')
		return (1);
	    }
	}
    }
  return (0);
}

char		*get_next_line(const int fd)
{
  static char	*save = NULL;
  t_gnl		gnl;

  if (fd < 0)
    return (NULL);
  if ((gnl.final = read_me(fd, &save)) == -1)
    return (NULL);
  gnl.i = 0;
  if (save == NULL)
    return (NULL);
  while (save[gnl.i] != '\n' && save[gnl.i] != '\0')
    gnl.i++;
  gnl.str = malloc((gnl.i + 1) * sizeof(char));
  if (gnl.str == NULL)
    return (NULL);
  gnl.str[gnl.i] = '\0';
  gnl.j = -1;
  while (save != NULL && ++gnl.j < gnl.i)
    gnl.str[gnl.j] = save[gnl.j];
  if (clear_save(&save, gnl.i) == -1)
    return (NULL);
  if (gnl.final == 0 && gnl.str[0] == '\0' && save == NULL)
    return (NULL);
  return (gnl.str);
}
