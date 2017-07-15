##
## Makefile for myftp in /mnt/d/Projects/C/PSU_2017_myftp
## 
## Made by DESKTOP-DHNB9O5
## Login   <antoine.morel@epitech.eu>
## 
## Started on  Tue May  9 11:36:19 2017 DESKTOP-DHNB9O5
## Last update Fri May 19 16:36:39 2017 DESKTOP-DHNB9O5
##

NAME		=		server

SRCS		=		srcs/main.c					\
				srcs/args/check.c				\
				srcs/cmd/file_action/dele.c			\
				srcs/cmd/file_action/list.c			\
				srcs/cmd/file_action/pwd.c			\
				srcs/cmd/file_action/retr.c			\
				srcs/cmd/file_action/stor.c			\
				srcs/cmd/informational/help.c			\
				srcs/cmd/login/cdup.c				\
				srcs/cmd/login/cwd.c				\
				srcs/cmd/login/pass.c				\
				srcs/cmd/login/user.c				\
				srcs/cmd/logout/quit.c				\
				srcs/cmd/miscellaneous/noop.c			\
				srcs/cmd/transfer_parameters/pasv.c		\
				srcs/cmd/transfer_parameters/port.c		\
				srcs/cmd/transfer_parameters/port_set_socket.c	\
				srcs/core/get_next_line.c			\
				srcs/core/is_logged.c				\
				srcs/core/mainloop.c				\
				srcs/socket/initialize.c			\
				srcs/socket/multi_clients.c

OBJS		=		$(SRCS:.c=.o)

CC		=		gcc

CFLAGS		=		-W -Wall -Wextra

CFLAGS		+=		-I ./includes/

RM		=		rm -rf

all		:		$(NAME)

$(NAME)		:		$(OBJS)
				$(CC) -o $(NAME) $(OBJS)

clean		:
				$(RM) $(OBJS)

fclean		:		clean
				$(RM) $(NAME)

re		:		fclean all

.PHONY		:		all clean fclean re
