/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:58:25 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:51:50 by druina           ###   ########.fr       */
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
}					t_stack;

void				print_debug(t_stack *a, t_stack *b);
int					check_arguments(char **argv, int argc);
int					check_argument_content(char *argv);
int					check_duplicate(char **temp, char *argv, int count);
int					check_arguments_as_one_string(char *argv);
int					check_error(void);
t_stack				*insert(t_stack *top, char *data);
t_stack				*insert_argv_to_t_stack_a(char **argv, int argc);
t_stack				*sort_the_t_stack(t_stack *a, t_stack *b);
t_stack				*get_end_node(t_stack *a);
void				swap(t_stack **a_or_b, char *rule);
void				swap_both(t_stack **a, t_stack **b);
void				push(t_stack **push_from, t_stack **push_to, char *rule);
void				rotate(t_stack **a_or_b, char *rule);
void				rotate_both(t_stack **a, t_stack **b);
void				reverse_rotate(t_stack **a_or_b, char *rule);
void				reverse_rotate_both(t_stack **a, t_stack **b);
void				sort_position(t_stack **top);
int					t_stack_size(t_stack *a);
int					find_location_in_t_stack(t_stack *a, int position);
int					iterations_until_top(t_stack *temp, t_stack *a);
int					iterations_until_bottom(t_stack *temp);
void				sort_3(t_stack **a);
int					is_t_stack_sorted(t_stack *a);
void				check_iterations_and_push(t_stack **a, t_stack **b,
						int position);
void				sort_5(t_stack **a, t_stack **b, int position);
void				push_t_stack_b_back_to_a(t_stack **a, t_stack **b, int len);
int					find_min_position(t_stack *a_or_b);
void				sorting(t_stack **a, t_stack **b);
void				sort_position_part_1(t_stack **temp, t_stack **end,
						t_stack **smallest);
void				sort_position_part_2(t_stack **temp, t_stack **top,
						t_stack **end, t_stack **smallest);
void				masking(t_stack **temp, int mask, t_stack **a, t_stack **b);
void				up_or_down(int up, int down, t_stack **a, t_stack **b);
void				sort_3_else(t_stack **a);
void				push_2_before_sort_3(int iterations_2, int iterations,
						t_stack **a, t_stack **b);

#endif
