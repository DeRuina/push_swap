/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:58 by druina            #+#    #+#             */
/*   Updated: 2023/02/09 08:46:59 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack *a;
	stack *b;
	stack *temp;
	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		if (check_arguments(argv, argc) == -1)
			exit(EXIT_FAILURE);
		a = insert_argv_to_stack_a(argv, argc);
		temp = a;
		ft_printf(" top a is: %d\n", temp->data);
		while(temp->next != NULL)
		{
			ft_printf("a data is: %d\n", temp->data);
			temp = temp->next;
		}
		ft_printf("a data is: %d\n", temp->data);
		a = sort_the_stack(a, b);
	}
	else
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
