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

void	free_stack(t_list *a, t_list *b)
{
	t_list	*current;

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
	if (b)
	{
		current = b;
		while (current)
		{
			b = b->next;
			free(current);
			current = b;
		}
	}
}
