/*
** get_next_line.h for myftp in /mnt/d/Projects/C/PSU_2017_myftp/includes
** 
** Made by DESKTOP-DHNB9O5
** Login   <antoine.morel@epitech.eu>
** 
** Started on  Wed May 10 16:52:30 2017 DESKTOP-DHNB9O5
** Last update Wed May 10 16:52:58 2017 DESKTOP-DHNB9O5
*/

#ifndef		GET_NEXT_LINE_H_
# define	GET_NEXT_LINE_H_

# ifndef	READ_SIZE
#  define	READ_SIZE 4096
# endif		/* !READ_SIZE */

char		*get_next_line(const int fd);

typedef	struct	s_gnl
{
  char		*str;
  int		i;
  int		j;
  int		final;
}		t_gnl;

typedef	struct	s_read
{
  int		ret;
  char		buffer[READ_SIZE];
  int		i;
  int		stop;
}		t_read;

#endif		/* !GET_NEXT_LINE_H_ */
