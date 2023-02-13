/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:16:53 by druina            #+#    #+#             */
/*   Updated: 2023/02/13 15:05:20 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_debug(stack *a, stack *b)
{
	stack *temp;
	stack *tempb;
	temp = a;
	tempb = b;
	ft_printf("\n");
	ft_printf("\033[0;36m--------------------------------------------------\033[0m\n");
	ft_printf("\033[0;36mSTACK A\n\033[0m");
	ft_printf("\n");
	ft_printf("\033[31;1mhead  \033[0m\033[0;32m%d\033[0m\033[0;35m -> \033[0m", a->data);
	a = a->next;
	if (a != NULL)
	{
		while (a->next != NULL)
		{
			ft_printf("\033[0;33m%d\033[0m\033[0;35m -> \033[0m", a->data);
			a = a->next;
		}
		ft_printf("\033[0;34m%d  \033[0m\033[31;1mend\033[0m\n", a->data);
	}
	a = temp;
	ft_printf("\033[31;1mpos   \033[0m\033[0;32m%d    ", a->position);
	a = a->next;
	if (a != NULL)
	{
		while (a->next != NULL)
		{
			ft_printf("\033[0;33m%d\033[0m\033[0;35m    \033[0m", a->position);
			a = a->next;
		}
		ft_printf("\033[0;34m%d  \033[0m\033[31;1mend\033[0m\n", a->position);
	}

	ft_printf("\n\n");
	ft_printf("\033[0;36mSTACK B\n\033[0m");
	ft_printf("\n");
	if (b)
	{
		ft_printf("\033[31;1mhead  \033[0m\033[0;32m%d\033[0m\033[0;35m -> \033[0m", b->data);
		b = b->next;
		if (b != NULL)
		{
			while (b->next != NULL)
			{
				ft_printf("\033[0;33m%d\033[0m\033[0;35m -> \033[0m", b->data);
				b = b->next;
			}
			ft_printf("\033[0;34m%d  \033[0m\033[31;1mend\033[0m\n", b->data);
		}
		else
			ft_printf("\n");
	}
	else
		ft_printf("\033[31;1mNULL\033[0m\n");
	ft_printf("\033[0;36m--------------------------------------------------\033[0m\n");
	ft_printf("\n");

}
