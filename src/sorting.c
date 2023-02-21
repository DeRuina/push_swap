/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 10:09:44 by druina            #+#    #+#             */
/*   Updated: 2023/02/21 11:03:26 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	check_iterations(stack *a, stack *b, int position)
// {
// 	int		i;
// 	int		up;
// 	int		down;
// 	stack	*temp;
// 	stack	*top;

// 	top = a;
// 	temp = a;
// 	i = 0;
// 	while (++i < find_location_in_stack(a, position))
// 		temp = temp->next;
// 	i = 0;
// 	up = iterations_until_top(temp, a);
// 	a = top;
// 	down = iterations_until_bottom(temp);
// 	if (up > down)
// 		return (down);
// 	else
// 		return (up);
// }

// void min_to_top_b(stack **b, int position)
// {
// 	stack *temp;
// 	int min;
// 	int size;
// 	int times;

// 	temp = (*b);
// 	min = find_location_in_stack((*b), position);
// 	size = stack_size((*b));
// 	times = size - min;
// 	if ((*b)->position = position)
// 		return;
// 	if (times >= (size / 2))
// 	{
// 		while ((times-- - 1) != 0)
// 			rotate(b, "rb");
// 	}
// 	else
// 	{
// 		times = size - min;
// 		while ((times-- + 1) != 0)
// 			reverse_rotate(b, "rrb");
// 	}
// }

// void check_postion_and_adjust_before_push(stack **a, stack **b, int position)
// {
// 	int flag;
// 	stack *temp;
// 	int min;
// 	int max;

// 	temp = (*b);
// 	if ((*b) == NULL)
// 		return ;
// 	min = temp->position;
// 	max = temp->position;
// 	while (temp->next != NULL)
// 	{
// 		if (temp->position < min)
// 			min = temp->position;
// 		if (temp->position > max)
// 			max = temp->position;
// 		temp = temp->next;
// 	}
// 	if (temp->position < min)
// 		min = temp->position;
// 	if (temp->position > max)
// 		max = temp->position;
// 	if ((*a)->position > max || (*a)->position < min)
// 		min_to_top_b(b, min);
// 	else
// 		number_in_between_to_top_b(b, position);



// }

// void number_in_between_to_top_b(stack **b, int position)
// {
// 	int location;
// 	stack *temp;
// 	int bigger;

// 	temp = (*b);
// 	bigger = 1000;
// 	while (temp->next != NULL)
// 	{
// 		if ((temp->position - position) < bigger)
// 			bigger = temp->position;
// 		temp = temp->next;
// 	}
// 	if ((temp->position - position) < bigger)
// 			bigger = temp->position;
// 	min_to_top_b(b, bigger);

// }

// void sort_by_chunks(stack **a, stack **b, int position_min, int position_max)
// {
// 	stack 	*temp;
// 	int 	count;
// 	int 	num1;
// 	int 	num2;
// 	int 	chunck_len;
// 	int 	*num1_position;
// 	int 	*num2_position;

// 	temp = (*a);
// 	chunck_len = 20;
// 	while (chunck_len != 0)
// 	{
// 		while (temp->next != NULL)
// 		{
// 			if (temp->position >= position_min && temp->position <= position_max)
// 			{
// 				num1 = check_iterations((*a), (*b), temp->position);
// 				num1_position = temp->position;
// 				break;
// 			}
// 			else
// 				temp = temp->next;
// 		}
// 		temp = (*a);
// 		while (temp->next != NULL)
// 		{
// 			if (temp->position >= position_min && temp->position <= position_max)
// 				count++;
// 			if (count == chunck_len)
// 			{
// 				num2 = check_iterations((*a), (*b), temp->position);
// 				num2_position = temp->position;
// 				break;
// 			}
// 			else
// 				temp = temp->next;
// 		}
// 		if (num1 <= num2)
// 		{
// 			check_postion_and_adjust_before_push(a, b, num1_position);
// 			check_iterations_and_push(a, b, num1_position);
// 		}
// 		else
// 		{
// 			check_postion_and_adjust_before_push(a, b, num2_position);
// 			check_iterations_and_push(a, b, num2_position);
// 		}
// 		chunck_len--;
// 		temp = (*a);

// 	}
// }

// void	sorting(stack **a, stack **b)
// {
// 	// stack	*temp;
// 	// int 	count;
// 	// int 	num1;
// 	// int 	num2;
// 	// int 	chunck_len;
// 	// stack 	*num1_temp;
// 	// stack 	*num2_temp;

// 	while (stack_size((*a) != 0))
// 	{
// 		sort_by_chunks(a, b, 1, 20);
// 		sort_by_chunks(a, b, 21, 40);
// 		sort_by_chunks(a, b, 41, 60);
// 		sort_by_chunks(a, b, 61, 80);
// 		sort_by_chunks(a, b, 81, 100);
// 	}
// 	// temp = (*a);
// 	// chunck_len = 20;
// 	// while (stack_size((*a) != 0))
// 	// {
// 	// 	while (temp->next != NULL)
// 	// 	{
// 	// 		if (temp->position >= 1 && temp->position <= 20)
// 	// 		{
// 	// 			num1 = check_iterations((*a), (*b), temp->position);
// 	// 			num1_temp = temp;
// 	// 			break;
// 	// 		}
// 	// 		else
// 	// 			temp = temp->next;
// 	// 	}
// 	// 	temp = (*a);
// 	// 	while (temp->next != NULL)
// 	// 	{
// 	// 		if (temp->position >= 1 && temp->position <= 19)
// 	// 			count++;
// 	// 		if (count == chunck_len)
// 	// 		{
// 	// 			num2 = check_iterations((*a), (*b), temp->position);
// 	// 			num2_temp = temp;
// 	// 			break;
// 	// 		}
// 	// 		else
// 	// 			temp = temp->next;
// 	// 	}
// 	// 	if (num1 <= num2)
// 	// 		check_iterations_and_push(a, b, num1_temp->position);
// 	// 	else
// 	// 		check_iterations_and_push(a, b, num2_temp->position);
// 	// 	chunck_len =- 2;
// 	// 	temp = (*a);
// 	// 	if (chunck_len == 0)

// 	// }
// }
