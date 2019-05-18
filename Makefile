# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/05/18 13:48:35 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SOURCES =  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
		   ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
		   ft_strncpy.c	ft_strcat.c	ft_strncat.c ft_strlcat.c ft_strchr.c\
		   ft_strrchr.c ft_strstr.c	ft_strnstr.c ft_strcmp.c ft_strncmp.c\
		   ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c\
		   ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c	ft_memdel.c\
		   ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c\
		   ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c\
		   ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c\
		   ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c\
		   ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c\
		   ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_del_mem.c\
		   ft_free_arr.c ft_isspace.c ft_strsplit_sp.c ft_int_len.c\
		   get_next_line.c ft_max.c ft_min.c ft_abs.c ft_putchar_utf8.c\
		   ft_putchar_utf8_fd.c

OBJ = $(addprefix ./, $(SOURCES:.c=.o))

all: $(NAME)

bin:
	@$(CC) $(CFLAGS) -c $(SOURCES)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SOURCES)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:
	@rm -f $(OBJ) $(NAME)

re: fclean all
