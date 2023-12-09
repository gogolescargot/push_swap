/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:11:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/09 09:16:50 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_list	*find_last_list(t_list *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_list	*find_second_last_list(t_list *stack)
{
	t_list	*temp;

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

int	find_median(t_list *stack, t_list *node)
{
	size_t	i;
	t_list	*current;

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

t_list	*find_min(t_list *stack)
{
	int		min;
	t_list	*min_node;

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

t_list	*find_max(t_list *stack)
{
	int		max;
	t_list	*max_node;

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

t_list	*find_target(t_list *stack, t_list *node, bool mode)
{
	t_list	*closest;
	t_list	*current;

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
		else if (node->data < current->data && current->data - node->data < closest->data - node->data)
			closest = current;
		current = current->next;
	}
	if (!closest || node->data > closest->data)
		closest = find_min(stack);
	return (closest);
}

size_t	find_cost(t_list *a, t_list *b, t_list *target_a, t_list *target_b)
{
	size_t	i;
	size_t	j;
	t_list	*current;

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
	if (find_median(a, target_a) == find_median(b, target_b) && i == j)
		return (i / 2);
	else if (find_median(a, target_a) == find_median(b, target_b) && i > j)
		return (i);
	else if (find_median(a, target_a) == find_median(b, target_b) && i < j)
		return (j);
	return (i + j);
}
