# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffahey <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/29 19:04:47 by ffahey            #+#    #+#              #
#    Updated: 2019/01/30 17:28:00 by ffahey           ###   ########.fr        #
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

SRC=lem-in.c ft_init_farm.c
OBJ=$(addprefix $(BIN_PATH)/,$(SRC:.c=.o))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(BIN_PATH) $(LIB_NAME) $(OBJ)
	gcc -o $@ $(OBJ) $(LIB_INC)

$(LIB_NAME):
	make -C $(LIB_PATH)


$(BIN_PATH):
	mkdir -p $(BIN_PATH)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.c $(HEAD_PATH)/lem-in.h
	gcc $(CFLAGS) -o $@ -c $< -Iincludes -Ilibft

clean:
	rm -rf bin

fclean: clean
	rm -f $(NAME)

re: fclean all
