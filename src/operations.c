/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/10 10:52:33 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_both(stack **a, stack **b, stack *end_a, stack *end_b)
{
	rotate(a, end_a, NULL);
	rotate(b, end_b, NULL);
	ft_printf("rr");
}

void rotate(stack **a_or_b, stack *end ,char *rule)
{
	stack *temp;

	temp = (*a_or_b)->next;
	(*a_or_b)->next = NULL;
	end->next = (*a_or_b);
	(*a_or_b) = temp;
	if (rule)
		ft_printf("%s\n", rule);
}

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

stack	*get_end_node(stack *a)
{
	stack	*end;
	stack	*temp;

	temp = a;
	while (a->next != NULL)
		a = a->next;
	end = a;
	a = temp;
	return (end);
}

stack	*sort_the_stack(stack *a, stack *b)
{
	stack	*end_a;
	stack 	*end_b;

	b = NULL;
	end_a = get_end_node(a);
	swap(&a, "sa");
	print_debug(a, b);
	push(&a, &b, "pb");
	print_debug(a, b);
	push(&a, &b, "pb");
	print_debug(a, b);
	swap_both(&a, &b);
	print_debug(a, b);
	end_b = get_end_node(b);
	rotate_both(&a, &b, end_a, end_b);
	print_debug(a, b);
	return (a);
}
