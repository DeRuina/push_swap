# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druina <druina@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:45:54 by druina            #+#    #+#              #
#    Updated: 2023/02/06 11:02:08 by druina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror

HEADER = ./src/push_swap.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MANPATH)
	@cd libft && make
	@cd libft && mv libft.a ..
	@cc $(FLAGS) -o $(NAME) $(MANPATH) libft.a -I $(HEADER)

clean:
	@cd libft && make clean
	@rm -f libft.a



fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean



re: fclean all


