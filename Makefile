# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: astripeb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 17:19:04 by astripeb          #+#    #+#              #
#    Updated: 2020/06/03 23:40:11 by astripeb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libft.a
SO 				:= libft.so

SRC_DIR			:= ./src/
SRC_PRINTF_DIR	:= ./src/ft_printf/
SRC_MEM_DIR		:= ./src/memory/
SRC_STR_DIR		:= ./src/strings/
SRC_IO_DIR		:= ./src/io/
SRC_MATH_DIR	:= ./src/math/
SRC_LIST_DIR	:= ./src/lists/
SRC_DYN_DIR		:= ./src/dyn_arr/

INC_DIR			:= ./inc/
OBJ_DIR			:= ./obj/

CC				:= gcc
CFLAGS			:= -Wall -Wextra -Werror -g3
LFLAGS			:= -I $(INC_DIR)

DEPEND			:= -MD -MT

include $(SRC_PRINTF_DIR)ft_printf.mak
include $(SRC_MEM_DIR)memory.mak
include $(SRC_STR_DIR)strings.mak
include $(SRC_IO_DIR)io.mak
include $(SRC_LIST_DIR)lists.mak
include $(SRC_MATH_DIR)math.mak
include $(SRC_DYN_DIR)dyn_arr.mak

OBJ	= $(SRC_PRINTF:.c=.o) $(SRC_IO:.c=.o) $(SRC_LISTS:.c=.o)\
		$(SRC_MATH:.c=.o) $(SRC_MEM:.c=.o) $(SRC_STR:.c=.o)\
		$(SRC_DYN:.c=.o)

vpath %.h	$(INC_DIR)
vpath %.c	$(SRC_PRINTF_DIR) $(SRC_MEM_DIR) $(SRC_STR_DIR)\
			$(SRC_IO_DIR) $(SRC_LIST_DIR) $(SRC_MATH_DIR) $(SRC_DYN_DIR)

vpath %.o	$(OBJ_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(addprefix $(OBJ_DIR), $(OBJ))
	ranlib $@

$(OBJ):%.o:%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $(OBJ_DIR)$@ $(DEPEND) $@

$(OBJ_DIR):
	mkdir -p $@

so: $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) -shared $(addprefix $(OBJ_DIR), $(OBJ)) -o $(SO)

include $(wildcard $(OBJ_DIR)/*.d)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(SO)

re: fclean all

.PHONY: clean fclean re so

.SILENT: all $(NAME) $(OBJ) $(OBJ_DIR) clean fclean re so
