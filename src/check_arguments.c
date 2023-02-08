/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:41 by druina            #+#    #+#             */
/*   Updated: 2023/02/08 11:24:13 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(void)
{
	ft_printf("Error\n");
	return (-1);
}

int	check_duplicate(char **temp, char *argv, int count)
{
	int	i;

	i = 0;
	while (temp[i] != '\0')
	{
		if (i != count)
			if (ft_atoi(temp[i]) == ft_atoi(argv))
				return (-1);
		i++;
	}
	return (0);
}

int	check_argument_content(char *argv)
{
	char	*temp;

	temp = argv;
	while (*temp)
	{
		if (*temp != '-' && *temp != '+' && (*temp > '9' || *temp < '0'))
			return (-1);
		temp++;
	}
	return (0);
}

int	check_arguments_as_one_string(char *argv)
{
	char	**one_string;
	char	**temp;
	int		count;

	count = 0;
	one_string = ft_split(argv, ' ');
	temp = one_string;
	while (*one_string)
	{
		if (check_argument_content(*one_string) == -1)
			return (free_2d(temp));
		if (ft_atoi(*one_string) < -2147483648 || ft_atoi(*one_string) > 2147483647)
			return (free_2d(temp));
		if (check_duplicate(temp, *one_string, count) == -1)
			return (free_2d(temp));
		count++;
		one_string++;
	}
	free_2d(temp);
	return (0);
}

int	check_arguments(char **argv, int argc)
{
	char	**temp;
	int		count;

	argv++;
	temp = argv;
	count = 0;
	if (argc == 2)
	{
		if (check_arguments_as_one_string(*argv) == -1)
			return (check_error());
	}
	else
	{
		while (*argv)
		{
			if (check_argument_content(*argv) == -1)
				return (check_error());
			if (ft_atoi(*argv) < -2147483648 || ft_atoi(*argv) > 2147483647)
				return (check_error());
			if (check_duplicate(temp, *argv, count) == -1)
				return (check_error());
			count++;
			argv++;
		}
	}
	return (0);
}
