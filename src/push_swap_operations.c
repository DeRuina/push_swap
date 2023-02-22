/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/22 14:18:16 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(stack **push_from, stack **push_to, char *rule)
{
	stack	*temp;

	temp = (*push_from)->next;
	if ((*push_from) == NULL)
		return ;
	if ((*push_to) == NULL)
	{
		(*push_from)->next = NULL;
		(*push_to) = (*push_from);
		(*push_from) = temp;
	}
	else
	{
		(*push_from)->next = (*push_to);
		(*push_to) = (*push_from);
		(*push_from) = temp;
	}
	ft_printf("%s\n", rule);
}

void	swap_both(stack **a, stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_printf("ss\n");
}

void	swap(stack **a_or_b, char *rule)
{
	stack	*temp;

	if ((*a_or_b) == NULL || (*a_or_b)->next == NULL)
		return ;
	temp = (*a_or_b)->next;
	(*a_or_b)->next = (*a_or_b)->next->next;
	temp->next = (*a_or_b);
	(*a_or_b) = temp;
	if (rule)
		ft_printf("%s\n", rule);
}
