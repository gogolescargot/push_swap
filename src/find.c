/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:11:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/08 16:04:55 by ggalon           ###   ########.fr       */
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

t_node	*find_second_last_node(t_node *stack)
{
	t_node	*temp;

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

int	find_median(t_node *stack, t_node *node)
{
	size_t	i;
	t_node	*current;

	if (!stack)
		return (0);
	i = 1;
	current = stack;
	while (current != node && current->next)
	{
		current = current->next;
		i++;
	}
	if (i <= (stack_size(stack) + 1) / 2)
		return (1);
	else
		return (-1);
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

t_node	*find_max(t_node *stack)
{
	int		max;
	t_node	*max_node;

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

t_node	*find_target(t_node *stack, t_node *node, bool mode)
{
	t_node	*closest;
	t_node	*current;

	closest = NULL;
	current = stack;
	if (mode == true)
	{
		while (current)
		{
			if (node->data > current->data && !closest)
				closest = current;
			else if (node->data > current->data && closest && node->data - current->data < node->data - closest->data)
				closest = current;
			current = current->next;
		}
		if (!closest || node->data < closest->data)
			closest = find_max(stack);
		return (closest);
	}
	while (current)
	{
		if (node->data < current->data && !closest)
			closest = current;
		else if (node->data < current->data && closest && current->data - node->data < closest->data - node->data)
			closest = current;
		current = current->next;
	}
	if (!closest || node->data > closest->data)
		closest = find_min(stack);
	return (closest);
}

size_t	find_cost(t_node *a, t_node *b, t_node *target_a, t_node *target_b)
{
	size_t	i;
	size_t	j;
	t_node	*current;

	i = 0;
	j = 0;
	current = a;
	while (current != target_a)
	{
		i++;
		current = current->next;
	}
	current = b;
	while (current != target_b)
	{
		j++;
		current = current->next;
	}
	if (find_median(a, target_a) == -1)
		i = stack_size(a) - i;
	if (find_median(b, target_b) == -1)
		j = stack_size(b) - j;
	return (i + j);
}
