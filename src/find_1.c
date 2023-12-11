/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:37:45 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/11 15:34:28 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*f_min(t_stack *stack)
{
	int		min;
	t_stack	*min_node;

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

t_stack	*f_max(t_stack *stack)
{
	int		max;
	t_stack	*max_node;

	if (!stack)
		return (0);
	max = stack->data;
	max_node = stack;
	while (stack)
	{
		if (stack->data > max)
		{
			max = stack->data;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*f_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*f_s_last(t_stack *stack)
{
	t_stack	*temp;

	if (!stack)
		return (NULL);
	temp = stack;
	while (stack->next)
	{
		temp = stack;
		stack = stack->next;
	}
	return (temp);
}
