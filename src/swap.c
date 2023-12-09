/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:19:19 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:35:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	swap(t_stack **stack)
{
	int	temp;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	temp = (*stack)->data;
	(*stack)->data = (*stack)->next->data;
	(*stack)->next->data = temp;
	return (true);
}

void	sa(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		return ;
	write(1, "sa\n", 3);
}

void	sb(t_stack **a, bool print)
{
	swap(a);
	if (!print)
		return ;
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		return ;
	write(1, "ss\n", 3);
}
