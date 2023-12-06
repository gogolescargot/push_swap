/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:13:24 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 05:13:24 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	stack_sorted(t_node *stack)
{
	if (!stack)
		return (-1);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

size_t	stack_size(t_node *stack)
{
	size_t	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}
