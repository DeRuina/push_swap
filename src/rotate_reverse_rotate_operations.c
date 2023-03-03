/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse_rotate_operations.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:38:45 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:48:53 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_end_node(t_stack *a)
{
	t_stack	*end;
	t_stack	*temp;

	if (a->next == NULL)
		return (a);
	temp = a;
	while (a->next != NULL)
		a = a->next;
	end = a;
	a = temp;
	return (end);
}

void	reverse_rotate(t_stack **a_or_b, char *rule)
{
	t_stack	*end;
	t_stack	*temp;

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

void	reverse_rotate_both(t_stack **a, t_stack **b)
{
	reverse_rotate(a, NULL);
	reverse_rotate(b, NULL);
	ft_printf("rrr");
}

void	rotate_both(t_stack **a, t_stack **b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	ft_printf("rr");
}

void	rotate(t_stack **a_or_b, char *rule)
{
	t_stack	*temp;
	t_stack	*end;

	if ((*a_or_b)->next == NULL)
		return ;
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
