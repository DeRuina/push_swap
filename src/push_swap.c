/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:58 by druina            #+#    #+#             */
/*   Updated: 2023/02/16 17:28:32 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(stack *a)
{
	while (a->next != NULL)
	{
		if (a->data > a->next->data)
			return (1);
		a = a->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	stack	*a;
	stack	*b;
	stack	*temp;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (check_arguments(argv, argc) == -1)
			exit(EXIT_FAILURE);
		a = insert_argv_to_stack_a(argv, argc);
		if (is_stack_sorted(a) == 0)
			exit(EXIT_SUCCESS);
		temp = a;
		if (stack_size(a) == 2)
			swap(&a, "sa");
		else
			a = sort_the_stack(a, b);

	}
	else
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
