/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:58:25 by druina            #+#    #+#             */
/*   Updated: 2023/02/10 10:53:22 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

typedef struct stack
{
	int				data;
	struct stack	*next;
}					stack;

void				print_debug(stack *a, stack *b);
int					check_arguments(char **argv, int argc);
int					check_argument_content(char *argv);
int					check_duplicate(char **temp, char *argv, int count);
int					check_arguments_as_one_string(char *argv);
int					check_error(void);
stack				*insert(stack *top, char *data);
stack				*insert_argv_to_stack_a(char **argv, int argc);
void				free_list(stack *top);
stack				*sort_the_stack(stack *a, stack *b);
stack				*get_end_node(stack *a);
void				swap(stack **a_or_b, char *rule);
void				swap_both(stack **a, stack **b);
void				push(stack **push_from, stack **push_to, char *rule);
void				rotate(stack **a_or_b, stack *end, char *rule);
void				rotate_both(stack **a, stack **b, stack *end_a,
						stack *end_b);

#endif
