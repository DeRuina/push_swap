/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/08 13:53:06 by druina           ###   ########.fr       */
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
}

stack	*push(stack *top, char *data)
{
	stack	*new_node;
	stack	*temp;

	new_node = (stack *)malloc(sizeof(stack));
	new_node->data = ft_atoi(data);
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

	temp = NULL;
	top = NULL;
	one_arg = NULL;
	argv++;
	if (argc == 2)
	{
		one_arg = ft_split(*argv, ' ');
		temp = one_arg;
		argv = one_arg;
	}
	while (*argv)
	{
		top = push(top, *argv);
		argv++;
	}
	if (temp)
		free_2d(temp);
	return (top);
}
