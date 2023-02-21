/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:25:41 by druina            #+#    #+#             */
/*   Updated: 2023/02/21 15:34:54 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sorting(stack **a, stack **b)
{
	int max_num;
	int i;
	int bits;
	stack *temp;
	int mask;

	mask = 0b000000000000000000000000000000001;
	i = 0;
	bits = 0;
	temp = (*a);
	max_num = stack_size((*a));
	while (max_num)
	{
		bits++;
		max_num = max_num >> 1;
	}
	max_num = stack_size((*a));
	while (bits != 0)
	{
		while (max_num-- != 0)
		{
			if ((temp->position & mask) == 0)
			{
				temp = temp->next;
				push(a, b, "pb");
			}
			else
			{
				temp = temp->next;
				rotate(a, "ra");
			}
		}
		push_stack_b_back_to_a(a, b, stack_size((*b)));
		temp = (*a);
		mask = mask << 1;
		bits--;
		max_num = stack_size((*a));
	}
}
