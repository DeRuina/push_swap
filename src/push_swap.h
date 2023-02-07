/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:58:25 by druina            #+#    #+#             */
/*   Updated: 2023/02/07 14:46:11 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

typedef struct stack
{
	void			*data;
	struct stack	*next;
}					stack;

int	check_arguments(char **argv);
int	check_argument_content(char *argv);
int	check_duplicate(char **temp, char *argv, int count);
int	check_error(void);

#endif
