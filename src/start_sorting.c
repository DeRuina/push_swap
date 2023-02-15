/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:36:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/15 10:14:02 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	iterations_until_bottom(stack *temp)
{
	int	iterations;

	iterations = 0;
	while (temp->next != NULL)
	{
		iterations++;
		temp = temp->next;
	}
	iterations++;
	return (iterations);
}

int	iterations_until_top(stack *temp, stack *a)
{
	int	iterations;

	iterations = 0;
	while (a->data != temp->data)
	{
		iterations++;
		a = a->next;
	}
	if (iterations != 0)
		iterations++;
	return (iterations);
}

int	find_location_in_stack(stack *a, int position)
{
	int		location;
	stack	*temp;

	temp = a;
	location = 1;
	while (temp->next != NULL)
	{
		if (position == temp->position)
			return (location);
		location++;
		temp = temp->next;
	}
	return (location);
}

int	stack_size(stack *a)
{
	int	i;

	i = 1;
	while (a->next != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
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
				rotate(&a, "ra");
			push(&a, &b, "pb");
		}
		else
		{
			while (++i <= down)
				reverse_rotate(&a, "rra");
			push(&a, &b, "pb");
		}
		temp = a;
		i = 0;
		position++;
	}
	len = stack_size(b);
	while (len-- != 0)
		push(&b, &a, "pa");
	return (a);
}
