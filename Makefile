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

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJ = *.o

SOURCES = *.c

all: bin $(NAME)

bin:
	@ $(CC) $(CFLAGS) -c $(SOURCES)

$(NAME):
	@ ar rc $(NAME) $(OBJ)

clean:
	@ rm -f $(OBJ)

fclean:
	@ rm -f $(OBJ) $(NAME)

re: fclean all
