/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:33:04 by druina            #+#    #+#             */
/*   Updated: 2023/03/03 03:52:59 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_position(t_stack **top)
{
	static int	place = 1;
	t_stack		*temp;
	t_stack		*end;
	t_stack		*smallest;

	smallest = NULL;
	if (!(*top)->position)
	{
		(*top)->position = 1;
		return ;
	}
	end = get_end_node((*top));
	temp = (*top);
	while (temp->next != NULL)
	{
		sort_position_part_1(&temp, &end, &smallest);
		if (temp->next == NULL)
			end->position = ++place;
	}
	sort_position_part_2(&temp, top, &end, &smallest);
}

void	sort_position_part_1(t_stack **temp, t_stack **end, t_stack **smallest)
{
	if ((*temp)->data > (*end)->data)
	{
		if ((*smallest) != NULL)
		{
			if ((*temp)->data < (*smallest)->data)
				(*smallest) = (*temp);
		}
		else
			(*smallest) = (*temp);
	}
	(*temp) = (*temp)->next;
}

void	sort_position_part_2(t_stack **temp, t_stack **top, t_stack **end,
		t_stack **smallest)
{
	if ((*smallest) != NULL)
		(*end)->position = (*smallest)->position;
	(*temp) = (*top);
	while ((*temp)->next != NULL)
	{
		if ((*end)->position <= (*temp)->position)
			(*temp)->position++;
		(*temp) = (*temp)->next;
	}
}

t_stack	*insert(t_stack *top, char *data)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->data = ft_atoi(data);
	new_node->position = 0;
	new_node->next = NULL;
	if (!top)
		top = new_node;
	else
	{
		temp = top;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
	return (top);
}

t_stack	*insert_argv_to_t_stack_a(char **argv, int argc)
{
	t_stack	*top;
	char	**one_arg;
	char	**temp;

	temp = argv;
	top = NULL;
	one_arg = NULL;
	argv++;
	if (argc == 2)
	{
		one_arg = ft_split(*argv, ' ');
		argv = one_arg;
	}
	while (*argv)
	{
		top = insert(top, *argv);
		sort_position(&top);
		argv++;
	}
	if (one_arg)
		free_2d(one_arg);
	argv = temp;
	return (top);
}
