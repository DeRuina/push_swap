/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:25:41 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:48:38 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_stack **a, t_stack **b)
{
	int		max_num;
	int		bits;
	t_stack	*temp;
	int		mask;

	mask = 1;
	bits = 0;
	temp = (*a);
	max_num = t_stack_size((*a));
	while (max_num)
	{
		bits++;
		max_num = max_num >> 1;
	}
	max_num = t_stack_size((*a));
	while (bits != 0)
	{
		while (max_num-- != 0)
			masking(&temp, mask, a, b);
		push_t_stack_b_back_to_a(a, b, t_stack_size((*b)));
		temp = (*a);
		mask = mask << 1;
		bits--;
		max_num = t_stack_size((*a));
	}
}

void	masking(t_stack **temp, int mask, t_stack **a, t_stack **b)
{
	if (((*temp)->position & mask) == 0)
	{
		(*temp) = (*temp)->next;
		push(a, b, "pb");
	}
	else
	{
		(*temp) = (*temp)->next;
		rotate(a, "ra");
	}
}
