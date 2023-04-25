#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  nuo  <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: ____/__/__ __:__:__ by nuo               #+#    #+#              #
#    Updated: ____/__/__ __:__:__ by nuo              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= libftprintf.a		#HEADER	= ft_printf.h

SRC	= $(wildcard *.c)	#SRC	= *.c	# Crucial fix
OBJ	= $(SRC:.c=.o)

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra
AR	= ar rcs
RM	= /bin/rm -f

BIG	= \e[1;3;32m
BW	= \e[1;97m
R	= \e[0;0m

all:		$(NAME)

$(NAME):	$(OBJ)			# $(HEADER) # Crucial fix
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@printf "$(BW)$@$(R)$(BIG) successfully built. $(R)\n"

%.o : %.c
		@$(CC) $(CFLAGS) $< -c	# silence gcc msg in stdout

clean	:
		@$(RM) *.o
		@printf "$(BW)$@$(R)$(BIG) all .o files gone $(R)\n"

fclean	:	clean
		@$(RM) $(NAME)
		@printf "$(BW)$@$(R)$(BIG) all binaries gone $(R)\n"

re	:	fclean all

.PHONY	:	all clean fclean re
