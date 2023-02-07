/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:58 by druina            #+#    #+#             */
/*   Updated: 2023/02/07 14:49:35 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	stack *a;
	stack *b;
	if (argc > 1)
	{
		if (check_arguments(argv) == -1)
			exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
