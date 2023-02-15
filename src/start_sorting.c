/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:36:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/15 16:58:35 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_5(stack **a)
{
	if ()
}

void sort_3(stack **a)
{
	if ((*a)->data > (*a)->next->data)
	{
		if (((*a)->data > (*a)->next->next->data) && ((*a)->next->data < (*a)->next->next->data))
			rotate(a, "ra");
		else if (((*a)->data > (*a)->next->next->data) && ((*a)->next->data > (*a)->next->next->data))
		{
			swap(a, "sa");
			reverse_rotate(a, "rra");
		}
		else
			swap(a, "sa");
	}
	else
	{
		if ((*a)->data > (*a)->next->next->data)
			reverse_rotate(a, "rra");
		else
		{
			reverse_rotate(a, "rra");
			swap(a, "sa");
		}
	}
}

stack	*sort_the_stack(stack *a, stack *b)
{
	int		position;
	stack	*temp;
	int		i;
	int		len;
	int		up;
	int		down;

	len = stack_size(a);
	temp = a;
	position = 1;
	i = 0;
	if (len == 3)
	{
		sort_3(&a);
		return (a);
	}
	while (len-- != 0)
	{
		while (++i < find_location_in_stack(a, position))
			temp = temp->next;
		i = 0;
		up = iterations_until_top(temp, a);
		down = iterations_until_bottom(temp);
		if (up <= down)
		{
			while (++i <= up)
			{
				rotate(&a, "ra");
				// print_debug(a, b);
			}
			push(&a, &b, "pb");
			// print_debug(a, b);
		}
		else
		{
			while (++i <= down)
			{
				reverse_rotate(&a, "rra");
				// print_debug(a, b);
			}
			push(&a, &b, "pb");
			// print_debug(a, b);
		}
		temp = a;
		i = 0;
		position++;
	}
	len = stack_size(b);
	while (len-- != 0)
	{
		push(&b, &a, "pa");
		// print_debug(a, b);
	}
	return (a);
}
