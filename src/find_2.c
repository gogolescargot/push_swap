/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:11:59 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/09 09:16:50 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	f_med(t_stack *stack, t_stack *node)
{
	size_t	i;
	t_stack	*current;

	if (!stack)
		return (false);
	i = 1;
	current = stack;
	while (current != node && current->next)
	{
		current = current->next;
		i++;
	}
	if (i <= (stack_size(stack) + 1) / 2)
		return (true);
	else
		return (false);
}

t_stack	*f_trg_b(t_stack *stack, t_stack *node)
{
	t_stack	*closest;
	t_stack	*current;

	closest = NULL;
	current = stack;
	while (current)
	{
		if (node->data > current->data && !closest)
			closest = current;
		else if (node->data > current->data
			&& node->data - current->data < node->data - closest->data)
			closest = current;
		current = current->next;
	}
	if (!closest || node->data < closest->data)
		closest = f_max(stack);
	return (closest);
}

t_stack	*f_trg_a(t_stack *stack, t_stack *node)
{
	t_stack	*closest;
	t_stack	*current;

	closest = NULL;
	current = stack;
	while (current)
	{
		if (node->data < current->data && !closest)
			closest = current;
		else if (node->data < current->data
			&& current->data - node->data < closest->data - node->data)
			closest = current;
		current = current->next;
	}
	if (!closest || node->data > closest->data)
		closest = f_min(stack);
	return (closest);
}

t_stack	*f_trg(t_stack *stack, t_stack *node, bool mode)
{
	if (mode)
		return (f_trg_b(stack, node));
	return (f_trg_a(stack, node));
}

size_t	f_cst(t_stack *a, t_stack *b, t_stack *target_a, t_stack *target_b)
{
	size_t	i;
	size_t	j;
	t_stack	*current;

	i = 0;
	j = 0;
	current = a;
	while (current != target_a && ++i)
		current = current->next;
	current = b;
	while (current != target_b && ++j)
		current = current->next;
	if (!f_med(a, target_a))
		i = stack_size(a) - i;
	if (!f_med(b, target_b))
		j = stack_size(b) - j;
	if (f_med(a, target_a) == f_med(b, target_b) && i == j)
		return (i / 2);
	else if (f_med(a, target_a) == f_med(b, target_b) && i > j)
		return (i);
	else if (f_med(a, target_a) == f_med(b, target_b) && i < j)
		return (j);
	return (i + j);
}
