/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:58:25 by druina            #+#    #+#             */
/*   Updated: 2023/02/22 14:39:19 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

typedef struct stack
{
	int				data;
	int				position;
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
stack				*sort_the_stack(stack *a, stack *b);
stack				*get_end_node(stack *a);
void				swap(stack **a_or_b, char *rule);
void				swap_both(stack **a, stack **b);
void				push(stack **push_from, stack **push_to, char *rule);
void				rotate(stack **a_or_b, char *rule);
void				rotate_both(stack **a, stack **b);
void				reverse_rotate(stack **a_or_b, char *rule);
void				reverse_rotate_both(stack **a, stack **b);
void				sort_position(stack **top);
int					stack_size(stack *a);
int					find_location_in_stack(stack *a, int position);
int					iterations_until_top(stack *temp, stack *a);
int					iterations_until_bottom(stack *temp);
void				sort_3(stack **a);
int					is_stack_sorted(stack *a);
void				check_iterations_and_push(stack **a, stack **b,
						int position);
void				sort_5(stack **a, stack **b, int position);
void				push_stack_b_back_to_a(stack **a, stack **b, int len);
int					find_min_position(stack *a_or_b);
void				sorting(stack **a, stack **b);

#endif
