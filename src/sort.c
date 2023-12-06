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

void	big_sort(t_node **a, t_node **b);