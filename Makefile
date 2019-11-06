# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2019/11/07 00:05:05 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
LIB_HEADER		= libft.h
PRINTF_HEADER	= libftprintf.h

SRC_DIR			= ./src/
SRC_PRINTF_DIR	= ./src/ft_printf/
INC_DIR			= ./inc/
OBJ_DIR			= ./obj/

CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LFLAGS			= -I $(INC_DIR)

SRC_LIB		= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
			ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c\
			ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c\
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
			ft_putchar_utf8_fd.c ft_llitoa.c ft_strjoin_f.c ft_strjoin_s.c\
			ft_putstr_utf8.c ft_putstr_utf8_fd.c ft_to_uppercase.c ft_lstrlen.c\
			ft_putnstr_utf8_fd.c ft_lenwchar.c word_len.c word_count.c\
			ft_isdigitstr.c ft_char_count.c ft_len_arr.c buffer.c\
			ft_atoi_base.c

SRC_PRINTF	= ft_putnbr_f.c print_str.c print_pointer.c utility_func.c\
			print_num.c print_char.c ft_printf.c parse_mod.c print_double.c\
			set_color.c long_arithmetic.c long_arithmetic_2.c count_print.c\
			ft_dtoa.c ft_dtoa_2.c ft_dtoa_3.c ft_fprintf.c set_precision.c\
			print_binary.c ft_dtoe.c print_scientific.c utility_func_2.c

OBJ_L 		= $(SRC_LIB:.c=.o)
OBJ_P		= $(SRC_PRINTF:.c=.o)

vpath %.h $(INC_DIR)
vpath %.c $(SRC_DIR) $(SRC_PRINTF_DIR)
vpath %.o $(OBJ_DIR)

all: $(NAME)

$(NAME): $(OBJ_L) $(OBJ_P)
	ar rc $@ $(addprefix $(OBJ_DIR), $(OBJ_L)) $(addprefix $(OBJ_DIR), $(OBJ_P))
	ranlib $@

$(OBJ_L):%.o:%.c $(LIB_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGC) $(LFLAGS) -c $< -o $(OBJ_DIR)$@

$(OBJ_P):%.o:%.c $(PRINTF_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGC) $(LFLAGS) -c $< -o $(OBJ_DIR)$@

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re

.SILENT: all $(NAME) $(OBJ_P) $(OBJ_L) $(OBJ_DIR) clean fclean re
