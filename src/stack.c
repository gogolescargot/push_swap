/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 05:13:24 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:35:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	stack_some_sorted(t_stack *stack)
{
	t_stack	*start;
	t_stack	*current;

	if (!stack)
		return (false);
	start = f_min(stack);
	if (!(start->next) && start->data < stack->data)
		current = stack;
	else if (start->next && start->data < start->next->data)
		current = start->next;
	else
		return (false);
	while (current != start)
	{
		if (!(current->next) && stack == start)
			return (true);
		if (!(current->next) && current->data < stack->data)
			current = stack;
		else if (!(current->next)
			|| (current->data > current->next->data && current->next != start))
			return (false);
		else
			current = current->next;
	}
	return (true);
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

void	free_stack(t_stack *a, t_stack *b)
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
