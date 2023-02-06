/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:58 by druina            #+#    #+#             */
/*   Updated: 2023/02/06 15:31:02 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_2d(char **str)
{
	char	**temp;

	temp = str;
	while (*str)
	{
		free(*str);
		str++;
	}
	free(temp);
}

int check_error(char **temp)
{
	ft_printf("Error\n");
	free_2d(temp);
	return (-1);
}

int check_duplicate(char **temp, char *check, int count)
{
	char **duplicate;

	duplicate = temp;
	while (*duplicate)
	{

		if (ft_atoi(*duplicate) == ft_atoi(check))
			return(-1);
		duplicate++;
	}
	return(0);
	}

int check_arguments(char *argv)
{
	char **check;
	char **temp;
	int count;

	check = ft_split(argv, ' ');
	temp = check;
	count = 0;
	while (*check)
	{
		if (**check != '-' && **check != '+' && **check > '9' && **check < '0')
			return (check_error(temp));
		if (ft_atoi(*check) < -2147483648 || ft_atoi(*check) > 2147483647)
			return (check_error(temp));
		if (check_duplicate(temp, *check, count) == -1)
			return (check_error(temp));
		count++;
		check++;
	}
	free_2d(temp);
	return (0);
}

int	main(int argc, char **argv)

{
	if (argc >= 2)
	{
		check_arguments(argv[1]);

	}
	else if (argc == 1)
		exit(EXIT_FAILURE);
	else
		exit(ft_printf("Error\n"));

	exit (EXIT_SUCCESS);
}
