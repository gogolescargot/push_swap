/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:11:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/07 20:36:27 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	find_max_pos(t_node *stack)
{
	int	max;
	int	i;
	int	max_i;

	if (!stack)
		return (0);
	i = 0;
	max = stack->data;
	max_i = 0;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_i = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_i);
}

t_node	*find_min(t_node *stack)
{
	int		min;
	t_node	*min_node;

	if (!stack)
		return (0);
	min = stack->data;
	min_node = stack;
	while (stack)
	{
		if (stack->data < min)
		{
			min = stack->data;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}
