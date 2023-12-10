/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 09:15:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/09 09:15:59 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack *a)
{
	t_stack	*current;

	if (a)
	{
		current = a;
		while (current)
		{
			a = a->next;
			free(current);
			current = a;
		}
	}
}

void	free_argv(char **argv, int argc)
{
	size_t	i;

	i = 1;
	if (argc != 2)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
