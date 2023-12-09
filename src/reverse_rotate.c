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

bool	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	last = find_last_list(*stack);
	second_last = find_second_last_list(*stack);
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (true);
}

void	rra(t_list **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		return ;
	write(1, "rra\n", 4);
}

void	rrb(t_list **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		return ;
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		return ;
	write(1, "rrr\n", 4);
}
