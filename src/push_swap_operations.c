/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:48:09 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **push_from, t_stack **push_to, char *rule)
{
	t_stack	*temp;

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

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a, NULL);
	swap(b, NULL);
	ft_printf("ss\n");
}

void	swap(t_stack **a_or_b, char *rule)
{
	t_stack	*temp;

	if ((*a_or_b) == NULL || (*a_or_b)->next == NULL)
		return ;
	temp = (*a_or_b)->next;
	(*a_or_b)->next = (*a_or_b)->next->next;
	temp->next = (*a_or_b);
	(*a_or_b) = temp;
	if (rule)
		ft_printf("%s\n", rule);
}
