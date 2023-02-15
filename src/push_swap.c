/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:58 by druina            #+#    #+#             */
/*   Updated: 2023/02/15 16:02:39 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_stack_sorted(stack *a)
{
	int counter;

	counter = 1;
	while (a->next != NULL)
	{
		if (counter != a->position)
			return (1);
		counter++;
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
		// print_debug(a, b);
		a = sort_the_stack(a, b);
		// print_debug(a, b);
	}
	else
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
