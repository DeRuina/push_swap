/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:36:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/21 11:04:51 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(stack **a, stack **b, int reverse_flag, int position)
{
	stack	*temp;
	int		iterations;
	int		iterations_1;
	stack	*top;
	int		iterations_2;
	int		j;
	int		i;

	i = 0;
	j = 2;
	top = (*a);
	temp = (*a);
	position = find_min_position((*a)) + 1;
	while (j != 0)
	{
		while (++i < find_location_in_stack((*a), position))
			temp = temp->next;
		iterations = iterations_until_top(temp, (*a));
		(*a) = top;
		if (iterations > iterations_until_bottom(temp))
			iterations = iterations_until_bottom(temp);
		if (j == 2)
			iterations_2 = iterations;
		else
			iterations_1 = iterations;
		j--;
		position--;
		i = 0;
		temp = (*a);
	}
	position = find_min_position((*a)) + 1;
	if (reverse_flag == 1)
	{
		push_stack_b_back_to_a(a, b, 2);
		reverse_sort_3(b);
		push_stack_b_back_to_a(a, b, 3);
		return ;
	}
	else if (iterations_2 < iterations_1)
	{
		check_iterations_and_push(a, b, position);
		check_iterations_and_push(a, b, (position - 1));
		swap(b, "sb");
	}
	else
	{
		check_iterations_and_push(a, b, (position - 1));
		check_iterations_and_push(a, b, position);
	}
	if (reverse_flag == 0)
	{
		sort_3(a);
		push_stack_b_back_to_a(a, b, 2);
		return ;
	}
	push_stack_b_back_to_a(a, b, stack_size((*b)));
}

void	check_iterations_and_push(stack **a, stack **b, int position)
{
	int		i;
	int		up;
	int		down;
	stack	*temp;
	stack	*top;

	top = (*a);
	temp = (*a);
	i = 0;
	while (++i < find_location_in_stack((*a), position))
		temp = temp->next;
	i = 0;
	up = iterations_until_top(temp, (*a));
	(*a) = top;
	down = iterations_until_bottom(temp);
	if (up <= down)
	{
		while (++i <= up)
			rotate(a, "ra");
		push(a, b, "pb");
	}
	else
	{
		while (++i <= down)
			reverse_rotate(a, "rra");
		push(a, b, "pb");
	}
}

void	reverse_sort_3(stack **a)
{
	if (is_stack_reverse_sorted((*a)) == 0)
		return ;
	if ((*a)->data < (*a)->next->data)
	{
		if (((*a)->data < (*a)->next->next->data)
			&& ((*a)->next->data < (*a)->next->next->data))
		{
			swap(a, "sb");
			reverse_rotate(a, "rrb");
		}
		else if (((*a)->data < (*a)->next->next->data)
				&& ((*a)->next->data > (*a)->next->next->data))
			rotate(a, "rb");
		else
			swap(a, "sb");
	}
	else
	{
		if ((*a)->data > (*a)->next->next->data)
		{
			swap(a, "sb");
			rotate(a, "rb");
		}
		else
			reverse_rotate(a, "rrb");
	}
}

void	sort_3(stack **a)
{
	if (is_stack_sorted(*a) == 0)
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
	{
		if ((*a)->data > (*a)->next->next->data)
			reverse_rotate(a, "rra");
		else
		{
			reverse_rotate(a, "rra");
			swap(a, "sa");
		}
	}
}

void	sort_10(stack **a, stack **b, int position)
{
	stack	*temp;

	temp = (*a);
	while (stack_size((*a)) != 7)
	{
		if (temp->position >= 1 && temp->position <= 3)
		{
			check_iterations_and_push(a, b, temp->position);
			temp = (*a);
		}
		else
			temp = temp->next;
	}
	check_iterations_and_push(a, b, 4);
	check_iterations_and_push(a, b, 5);
	sort_5(a, b, 0, (position + 1));
	sort_5(a, b, 1, 0);
}

void	push_stack_b_back_to_a(stack **a, stack **b, int len)
{
	while (len-- != 0)
		push(b, a, "pa");
}

stack	*sort_the_stack(stack *a, stack *b)
{
	int		position;
	stack	*temp;
	int		i;
	int		len;

	len = stack_size(a);
	temp = a;
	position = 1;
	i = 0;
	while (len != 0)
	{
		// if (len > 10)
		// 	sorting(&a, &b);
		if (len == 5)
		{
			sort_5(&a, &b, 0, (position + 1));

			len = 0;
			continue;
		}
		if (len == 3)
		{
			sort_3(&a);
			len = 0;
			continue;
		}
		check_iterations_and_push(&a, &b, position);
		temp = a;
		i = 0;
		position++;
		len--;
	}
	push_stack_b_back_to_a(&a, &b, stack_size(b));
	return (a);
}
