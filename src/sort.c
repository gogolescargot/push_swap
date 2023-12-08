/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:54:40 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 19:06:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_node **stack)
{
	if ((*stack)->data > (*stack)->next->data
		&& (*stack)->data > (*stack)->next->next->data)
		ra(stack, true);
	else if ((*stack)->data < (*stack)->next->data
		&& (*stack)->data < (*stack)->next->next->data)
		rra(stack, true);
	else if ((*stack)->data > (*stack)->next->data)
		sa(stack, true);
	else
		rra(stack, true);
	if (!stack_sorted(*stack))
		sort_three(stack);
}

// void	sort_mid(t_node *a, t_node *b)
// {
// 	if (stack_some_sorted(a))
// 	{
// 		if (find_median(a, find_min(a)) == 1)
// 			while (!stack_sorted(a))
// 				ra(&a, true);
// 		else
// 			while (!stack_sorted(a))
// 				rra(&a, true);
// 		return ;
// 	}
// 	while (a != find_max(a) && stack_size(a) > 1)
// 	{
// 		if (find_median(a, find_min(a)) == 1)
// 			while (find_min(a) != a)
// 				ra(&a, true);
// 		else
// 			while (find_min(a) != a)
// 				rra(&a, true);
// 		pb(&a, &b, true);
// 	}
// 	while (stack_size(b) > 0)
// 		pa(&a, &b, true);
// 	print_stack(a, b);
// }

void	sort_big(t_node *a, t_node *b)
{
	t_node	*current;
	t_node	*target_a;
	t_node	*target_b;
	size_t	cost;

	if (stack_some_sorted(a))
	{
		if (find_median(a, find_max(a)) == 1)
			while (!stack_sorted(a))
				ra(&a, false);
		else
			while (!stack_sorted(a))
				rra(&a, true);
		return ;
	}
	pb(&a, &b, true);
	pb(&a, &b, true);
	while (stack_size(a) > 3)
	{
		current = a;
		cost = find_cost(a, b, current, find_target(b, current, true));
		target_b = find_target(b, current, true);
		target_a = current;
		while (current && cost != 0)
		{
			if (find_cost(a, b, current, find_target(b, current, true)) < cost)
			{
				cost = find_cost(a, b, current, find_target(b, current, true));
				target_b = find_target(b, current, true);
				target_a = current;
			}
			current = current->next;
		}
		if (find_median(a, target_a) == 1 && find_median(b, target_b) == 1 && a != target_a && b != target_b)
			rr(&a, &b, true);
		else if (find_median(a, target_a) == -1 && find_median(b, target_b) == -1 && a != target_a && b != target_b)
			rrr(&a, &b, true);
		else
		{
			while (a != target_a || b != target_b)
			{
				if (find_median(a, target_a) == 1 && a != target_a)
					ra(&a, true);
				else if (find_median(a, target_a) == -1 && a != target_a)
					rra(&a, true);
				if (find_median(b, target_b) == 1 && b != target_b)
					rb(&b, true);
				else if (find_median(b, target_b) == -1 && b != target_b)
					rrb(&b, true);
			}
		}
		pb(&a, &b, true);
	}
	if (stack_size(a) == 3)
		sort_three(&a);
	else if (stack_size(a) == 2 && !stack_sorted(a))
		sa(&a, true);
	while (stack_size(b) > 0)
	{
		current = b;
		cost = find_cost(a, b, find_target(a, current, false), current);
		target_b = current;
		target_a = find_target(a, current, false);
		while (current && cost != 0)
		{
			if (find_cost(a, b, find_target(a, current, false), current) < cost)
			{
				cost = find_cost(a, b, find_target(a, current, false), current);
				target_b = current;
				target_a = find_target(a, current, false);
			}
			current = current->next;
		}
		if (find_median(a, target_a) == 1 && find_median(b, target_b) == 1 && a != target_a && b != target_b)
			rr(&a, &b, true);
		else if (find_median(a, target_a) == -1 && find_median(b, target_b) == -1 && a != target_a && b != target_b)
			rrr(&a, &b, true);
		else
		{
			while (a != target_a || b != target_b)
			{
				if (find_median(a, target_a) == 1 && a != target_a)
					ra(&a, true);
				else if (find_median(a, target_a) == -1 && a != target_a)
					rra(&a, true);
				if (find_median(b, target_b) == 1 && b != target_b)
					rb(&b, true);
				else if (find_median(b, target_b) == -1 && b != target_b)
					rrb(&b, true);
			}
		}
		pa(&a, &b, true);
	}
	if (stack_some_sorted(a))
	{
		if (find_median(a, find_max(a)) == 1)
			while (!stack_sorted(a))
				ra(&a, true);
		else
			while (!stack_sorted(a))
				rra(&a, true);
	}
	print_stack(a, b);
}
