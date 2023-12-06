/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 07:56:49 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:35:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	reverse_rotate(t_node **stack)
{
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->prev = NULL;
	(*stack)->prev = last;
	last->next = *stack;
	*stack = last;
	return (true);
}

void	rra(t_node **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		return ;
	write(1, "rra\n", 4);
}

void	rrb(t_node **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		return ;
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		return ;
	write(1, "rrr\n", 4);
}
