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

NAME = test_p

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = *.o

P1 = main_p1.c

P2 = main_p2.c

P3 = main_p3.c

all: libft clean

libft:
	@ $(CC) $(CFLAGS) *.c -L../ -lft -o main_libft

p1:
	@ $(CC) $(CFLAGS) $(P1) -L../ -lft -o $(NAME)1

p2:
	@ $(CC) $(CFLAGS) $(P2) -L../ -lft -o $(NAME)2

p3:
	@ $(CC) $(CFLAGS) $(P3) -L../ -lft -o $(NAME)3

bin:
	@ $(CC) -c $(SOURCES)

clean:
	@ rm -f $(OBJ)

fclean:
	@ rm -f $(OBJ) $(NAME)

re: fclean all
