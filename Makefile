# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/04/04 21:11:17 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_libft

CC = gcc

CFLAGS = -Wall -Wextra -Werror -std=c99

OBJ = *.o

SOURCES = *.c

all: bin d_file clean

d_file:
	@ $(CC) $(CFLAGS) -o $(NAME) $(OBJ)

bin:
	@ $(CC) -c $(SOURCES)

clean:
	@ rm -f $(OBJ)

fclean:
	@ rm -f $(OBJ) $(NAME)

re: fclean all
