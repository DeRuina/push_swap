/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/09 11:34:08 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

stack	*get_end_node(stack *a)
{
	stack	*end;
	stack 	*temp;

	temp = a;
	while (a->next != NULL)
		a = a->next;
	end = a;
	a = temp;
	return (end);
}

stack	*sort_the_stack(stack *a, stack *b)
{
	stack	*top;
	stack	*end;

	b = NULL;
	top = a;
	end = get_end_node(a);
	swap(&a, "sa");
	print_debug(a, b);
	swap_both(&a, &b);
	print_debug(a, b);
	return (top);
}
