# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffahey <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 19:04:47 by ffahey            #+#    #+#              #
#    Updated: 2019/02/05 17:48:39 by ffahey           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH=srcs
HEAD_PATH=includes
BIN_PATH=bin
LIB_PATH=libft

LIB_INC:=-L$(LIB_PATH) -lft

CFLAGS=#-Wall -Wextra -Werror

NAME=lem-in
LIB_NAME=libft.a

SRC=allocation_functions.c free_functions.c ft_error_output.c \
	ft_init_farm.c lem_in.c ft_read_rooms.c \
	modifer_commands.c modifer_functions.c ft_print_farm_structure.c \
	ft_rooms_reverse.c modifer_commands2.c
OBJ=$(addprefix $(BIN_PATH)/,$(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN_PATH) $(LIB_NAME) $(OBJ)
	gcc -o $@ $(OBJ) $(LIB_INC)

$(LIB_NAME):
	make -C $(LIB_PATH)

$(BIN_PATH):
	mkdir -p $(BIN_PATH)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD_PATH)/lem_in.h
	gcc $(CFLAGS) -o $@ -c $< -Iincludes -Ilibft

clean:
	@make -C libft fclean
	rm -rf bin

fclean: clean
	rm -f $(NAME)

re: fclean all
