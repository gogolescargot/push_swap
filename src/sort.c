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

void	sort_five(t_node **a, t_node **b)
{
	if (stack_some_sorted(*a))
	{
		if (find_max_pos(*a) >= 2)
			while (!stack_sorted(*a))
				rra(a, true);
		else
			while (!stack_sorted(*a))
				ra(a, true);
		return ;
	}
	while (stack_size(*a) > 3)
		pb(a, b, true);
	sort_three(a);
	if (stack_sorted(*b))
		sb(b, true);
	while (stack_size(*b) > 0)
		pa(a, b, true);
	if (find_max_pos(*a) <= 2)
	return ;
	while (!stack_sorted(*a))
		{
			print_stack(*a, *b);
			rra(a, true);
		}
	else
		while (!stack_sorted(*a))
			ra(a, true);
}
