/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:33:04 by druina            #+#    #+#             */
/*   Updated: 2023/02/15 08:29:01 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(stack *top)
{
	stack	*temp;

	temp = top;
	while (temp->next != NULL)
	{
		temp = temp->next;
		free(top);
		top = temp;
	}
	free(top);
}

void sort_position(stack **top)
{
	static int place = 1;
	stack *temp;
	stack *end;
	stack *smallest;

	smallest = NULL;
	if (!(*top)->position)
	{
		(*top)->position = 1;
		return;
	}
	end = get_end_node((*top));
	temp = (*top);
	while (temp->next != NULL)
	{
		if (temp->data > end->data)
		{
			if (smallest != NULL)
			{
				if (temp->data < smallest->data)
					smallest = temp;
			}
			else
				smallest = temp;
		}
		temp = temp->next;
		if (temp->next == NULL)
			end->position = ++place;
	}
	if (smallest != NULL)
		end->position = smallest->position;
	temp = (*top);
	while (temp->next != NULL)
	{
		if (end->position <= temp->position)
			temp->position++;
		temp = temp->next;
	}


}

stack	*insert(stack *top, char *data)
{
	stack	*new_node;
	stack	*temp;

	new_node = (stack *)malloc(sizeof(stack));
	if (!new_node)
		return(NULL);
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

stack	*insert_argv_to_stack_a(char **argv, int argc)
{
	stack	*top;
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

