/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:59:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/08 13:42:19 by druina           ###   ########.fr       */
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

stack	*one_argument_into_stack_a(char *argv)
{
	stack *top;
	char **arg_list;
	char **temp;

	top = NULL;
	arg_list = ft_split(argv, ' ');
	temp = arg_list;
	while (*arg_list)
	{
		top = push(top, *arg_list);
		arg_list++;
	}
	free_2d(temp);
	return(top);
}

stack	*insert_argv_to_stack_a(char **argv, int argc)
{
	stack	*top;

	top = NULL;
	argv++;
	if (argc == 2)
		top = one_argument_into_stack_a(*argv);
	else
	{
		while (*argv)
		{
			top = push(top, *argv);
			argv++;
		}
	}
	return (top);
}
