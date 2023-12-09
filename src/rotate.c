/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 07:45:35 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:35:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	first = (*stack);
	last = find_last_list(*stack);
	*stack = (*stack)->next;
	first->next = NULL;
	last->next = first;
	return (true);
}

void	ra(t_list **a, bool print)
{
	rotate(a);
	if (!print)
		return ;
	write(1, "ra\n", 3);
}

void	rb(t_list **b, bool print)
{
	rotate(b);
	if (!print)
		return ;
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		return ;
	write(1, "rr\n", 3);
}
