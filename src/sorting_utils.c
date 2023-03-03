/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:13:30 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:49:54 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *a_or_b)
{
	int		min;
	int		len;
	t_stack	*temp;

	temp = a_or_b;
	len = t_stack_size(a_or_b);
	min = 0;
	while (len != 0)
	{
		if (min == 0)
			min = temp->position;
		if (temp->position < min)
			min = temp->position;
		temp = temp->next;
		len--;
	}
	return (min);
}

int	iterations_until_bottom(t_stack *temp)
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

int	iterations_until_top(t_stack *temp, t_stack *a)
{
	int	iterations;

	iterations = 0;
	while (a->data != temp->data)
	{
		iterations++;
		a = a->next;
	}
	return (iterations);
}

int	find_location_in_t_stack(t_stack *a, int position)
{
	int		location;
	t_stack	*temp;

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

int	t_stack_size(t_stack *a)
{
	int	i;

	i = 1;
	if (!a)
		return (0);
	while (a->next != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}
