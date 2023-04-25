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

SRC	= $(wildcard ./mandatory/*.c)	#SRC	= *.c	# Crucial fix
OBJ	= $(SRC:.c=.o)

CC	= cc
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
		@ printf "\n\n"
		@ printf "\t[en] come on baby break my code\n"
		@ printf "\t[fr] viens, brise mon code\n"
		@ echo ""
		@ printf "\t\"make sure you have downloaded input._txt && data._tar \n\n"
		@ echo ""
		@ echo "you can do [curl -O ] "
		@ echo "you can do [wget ] "
		@ echo "you can do [tar -xvzf ] "
		@ echo ""


%.o : %.c
		@$(CC) $(CFLAGS) $< -c	# silence gcc msg in stdout

clean	:
		@$(RM) *.o
		@printf "$(BW)$@$(R)$(BIG) all .o files gone $(R)\n"

f	:	fclean
r	:	re

fclean	:	clean
		@$(RM) $(NAME)
		@printf "$(BW)$@$(R)$(BIG) all binaries gone $(R)\n"

re	:	fclean all

.PHONY	:	all clean fclean re
