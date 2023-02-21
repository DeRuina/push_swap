/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_rotate_operations.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/02/21 15:38:13 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*get_end_node(stack *a)
{
	stack	*end;
	stack	*temp;

	if (a->next == NULL)
		return (a);
	temp = a;
	while (a->next != NULL)
		a = a->next;
	end = a;
	a = temp;
	return (end);
}

void	reverse_rotate(stack **a_or_b, char *rule)
{
	stack	*end;
	stack	*temp;

	end = get_end_node((*a_or_b));
	temp = (*a_or_b);
	while (temp->next->data != end->data)
		temp = temp->next;
	temp->next = NULL;
	end->next = (*a_or_b);
	(*a_or_b) = end;
	if (rule)
		ft_printf("%s\n", rule);
}

void	reverse_rotate_both(stack **a, stack **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_printf("rrr");
}

void	rotate_both(stack **a, stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_printf("rr");
}

void	rotate(stack **a_or_b, char *rule)
{
	stack	*temp;
	stack	*end;

	if ((*a_or_b)->next == NULL)
		return;
	end = get_end_node((*a_or_b));
	temp = (*a_or_b)->next;
	if (temp == NULL)
		return ;
	(*a_or_b)->next = NULL;
	end->next = (*a_or_b);
	(*a_or_b) = temp;
	if (rule)
		ft_printf("%s\n", rule);
}
