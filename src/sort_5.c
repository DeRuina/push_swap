/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:41:42 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:49:41 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_stack **a, t_stack **b, int position)
{
	int		iterations;
	int		iterations_2;
	int		i;
	t_stack	*temp;

	i = 1;
	temp = (*a);
	position = find_min_position((*a)) + 1;
	while (i != 0)
	{
		i = 0;
		while (++i < find_location_in_t_stack((*a), position))
			temp = temp->next;
		iterations = iterations_until_top(temp, (*a));
		if (iterations > iterations_until_bottom(temp))
			iterations = iterations_until_bottom(temp);
		iterations_2 = iterations;
		if (iterations_2)
			i = 0;
		position--;
		temp = (*a);
	}
	push_2_before_sort_3(iterations_2, iterations, a, b);
}

void	push_2_before_sort_3(int iterations_2, int iterations, t_stack **a,
		t_stack **b)
{
	int	position;

	position = find_min_position((*a)) + 1;
	if (iterations_2 < iterations)
	{
		check_iterations_and_push(a, b, position);
		check_iterations_and_push(a, b, (position - 1));
		swap(b, "sb");
	}
	else
	{
		check_iterations_and_push(a, b, (position - 1));
		check_iterations_and_push(a, b, position);
	}
	sort_3(a);
	push_t_stack_b_back_to_a(a, b, 2);
}
