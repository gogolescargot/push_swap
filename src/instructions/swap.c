/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:19:19 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 06:19:19 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool swap(t_node **stack)
{
	int temp;
	if (!stack || !*stack || !(*stack)->next)
		return (false);
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
	return (true);
}

void	sa(t_node **a, bool print)
{
	swap(a);
	if (!print)
		return ;
	write(1, "sa\n", 3);
}

void	sb(t_node **a, bool print)
{
	swap(a);
	if (!print)
		return ;
	write(1, "sb\n", 3);
}

void ss(t_node **a, t_node **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		return ;
	write(1, "ss\n", 3);
}