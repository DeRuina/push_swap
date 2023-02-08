/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: druina <druina@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:58:25 by druina            #+#    #+#             */
/*   Updated: 2023/02/08 13:43:57 by druina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/src/libft.h"

typedef struct stack
{
	int				data;
	struct stack	*next;
}					stack;

int					check_arguments(char **argv, int argc);
int					check_argument_content(char *argv);
int					check_duplicate(char **temp, char *argv, int count);
int					check_arguments_as_one_string(char *argv);
int					check_error(void);
stack				*push(stack *top, char *data);
stack				*insert_argv_to_stack_a(char **argv, int argc);
void				free_list(stack *top);
stack				*one_argument_into_stack_a(char *argv);

#endif
