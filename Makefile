# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: druina <druina@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 10:45:54 by druina            #+#    #+#              #
#    Updated: 2023/02/22 14:15:41 by druina           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c check_arguments.c push_swap_operations.c\
rotate_reverse_rotate_operations.c insert_to_stack_a.c\
start_sorting.c sorting_utils.c radix_sort.c

MANPATH = $(addprefix ./src/, $(SRC))

FLAGS = -Wall -Wextra -Werror

HEADER = ./src/push_swap.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(MANPATH)
	@cd libft && make
	@cd libft && mv libft.a ..
	@cc $(FLAGS) -o $(NAME) $(MANPATH) libft.a -I $(HEADER) -g

clean:
	@cd libft && make clean
	@rm -f libft.a



fclean: clean
	@rm -f $(NAME)
	@cd libft && make fclean



re: fclean all


