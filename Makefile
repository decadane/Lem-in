# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/18 17:04:30 by marvin            #+#    #+#              #
#    Updated: 2019/01/31 18:18:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

vpath %.c srcs
vpath %.h includes
vpath %.o bin

FLAGS = -Wall -Wextra -Werror

OBJ = $(addprefix bin/,$(notdir $(patsubst %.c,%.o,$(wildcard srcs/*.c))))

HEADERS = $(wildcard includes/*.h)

LIB = libft/libft.a

all: makedir make_lib $(NAME)

makedir:
	@mkdir -p bin

make_lib:
	make -C libft/

$(NAME): $(OBJ) $(LIB)
	gcc $(FLAGS) $^ -o $@ -Iincludes -Ilibft/includes -Llibft -lft

bin/%.o: %.c $(HEADERS)
	gcc $(FLAGS) -c $< -o $@ -Iincludes -Ilibft/includes

clean:
	rm -rf bin/
	rm -rf libft/bin/

fclean: clean
	rm -f $(NAME)
	rm -f $(LIB)

re: fclean all

.PHONY: all clean fclean re make_lib
