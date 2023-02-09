/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/09 10:04:29 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// stack	*swap_both(stack *a, stack *b)
// {

// }

void	swap(stack **a_or_b, char *rule)
{
	stack	*temp;

	if ((*a_or_b)->next == NULL || !(*a_or_b))
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

	while (a->next != NULL)
		a = a->next;
	end = a;
	return (end);
}

stack	*sort_the_stack(stack *a, stack *b)
{
	stack	*top;
	stack	*end;
	stack	*temp;

	b = NULL;
	top = a;
	temp = a;
	end = get_end_node(a);
	ft_printf("last node in the list is: %p %d\n", end, end->data);
	swap(&temp, "sa");
	ft_printf(" top a is: %d\n", temp->data);
	while (temp->next != NULL)
	{
		ft_printf("a data is: %d\n", temp->data);
		temp = temp->next;
	}
	ft_printf("a data is: %d\n", temp->data);
	return (top);
}
