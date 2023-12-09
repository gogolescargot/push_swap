/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:13:24 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:35:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_sorted(t_stack *stack)
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

int	stack_some_sorted(t_stack *stack)
{
	t_stack	*start;
	t_stack	*current;

	if (!stack)
		return (-1);
	start = find_min(stack);
	if (!(start->next) && start->data < stack->data)
		current = stack;
	else if (start->next && start->data < start->next->data)
		current = start->next;
	else
		return (0);
	while (current != start)
	{
		if (!(current->next) && stack == start)
			return (1);
		if (!(current->next) && current->data < stack->data)
			current = stack;
		else if (!(current->next) || (current->data > current->next->data && current->next != start))
			return (0);
		else
			current = current->next;
	}
	return (1);
}

size_t	stack_size(t_stack *stack)
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
