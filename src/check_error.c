/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 01:09:49 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 01:09:49 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	check_syntax(char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (true);
			j++;
		}
		j = 0;
		i++;
	}
	return (false);
}

bool	check_duplicate(t_node *stack, int n)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->data == n)
			return (true);
		stack = stack->next;
	}
	return (false);
}
