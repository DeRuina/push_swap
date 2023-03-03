/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 02:41:00 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:49:25 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack **a)
{
	if (is_t_stack_sorted(*a) == 0)
		return ;
	if ((*a)->data > (*a)->next->data)
	{
		if (((*a)->data > (*a)->next->next->data)
			&& ((*a)->next->data < (*a)->next->next->data))
			rotate(a, "ra");
		else if (((*a)->data > (*a)->next->next->data)
			&& ((*a)->next->data > (*a)->next->next->data))
		{
			swap(a, "sa");
			reverse_rotate(a, "rra");
		}
		else
			swap(a, "sa");
	}
	else
		sort_3_else(a);
}

void	sort_3_else(t_stack **a)
{
	if ((*a)->data > (*a)->next->next->data)
		reverse_rotate(a, "rra");
	else
	{
		reverse_rotate(a, "rra");
		swap(a, "sa");
	}
}
