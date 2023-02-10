/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 15:36:48 by druina            #+#    #+#             */
/*   Updated: 2023/02/10 15:41:23 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack	*sort_the_stack(stack *a, stack *b)
{

	b = NULL;

	swap(&a, "sa");
	print_debug(a, b);
	push(&a, &b, "pb");
	print_debug(a, b);
	push(&a, &b, "pb");
	print_debug(a, b);
	swap_both(&a, &b);
	print_debug(a, b);
	rotate_both(&a, &b);
	print_debug(a, b);
	reverse_rotate(&a, "rra");
	print_debug(a, b);
	reverse_rotate(&b, "rrb");
	print_debug(a, b);
	reverse_rotate_both(&a, &b);
	print_debug(a, b);
	return (a);
}


