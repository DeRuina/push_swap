/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:36:48 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:50:09 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_iterations_and_push(t_stack **a, t_stack **b, int position)
{
	int		i;
	int		up;
	int		down;
	t_stack	*temp;
	t_stack	*top;

	top = (*a);
	temp = (*a);
	i = 0;
	while (++i < find_location_in_t_stack((*a), position))
		temp = temp->next;
	up = iterations_until_top(temp, (*a));
	(*a) = top;
	down = iterations_until_bottom(temp);
	up_or_down(up, down, a, b);
}

void	up_or_down(int up, int down, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (up <= down)
	{
		while (++i <= up)
			rotate(a, "ra");
		push(a, b, "pb");
	}
	else
	{
		while (++i <= down)
			reverse_rotate(a, "rra");
		push(a, b, "pb");
	}
}

void	push_t_stack_b_back_to_a(t_stack **a, t_stack **b, int len)
{
	while (len-- != 0)
		push(b, a, "pa");
}

t_stack	*sort_the_t_stack(t_stack *a, t_stack *b)
{
	int	position;
	int	len;

	len = t_stack_size(a);
	position = 1;
	if (len > 5)
		sorting(&a, &b);
	if (len == 5)
		sort_5(&a, &b, (position + 1));
	if (len == 4)
	{
		check_iterations_and_push(&a, &b, position);
		len = 3;
	}
	if (len == 3)
		sort_3(&a);
	push_t_stack_b_back_to_a(&a, &b, t_stack_size(b));
	return (a);
}
