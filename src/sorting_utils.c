/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:13:30 by druina            #+#    #+#             */
/*   Updated: 2023/02/15 11:14:05 by druina           ###   ########.fr       */
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
