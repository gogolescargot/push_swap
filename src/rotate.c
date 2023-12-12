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

bool	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	first = (*stack);
	last = f_last(*stack);
	*stack = (*stack)->next;
	first->next = NULL;
	last->next = first;
	return (true);
}

void	ra(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	if (!print)
		return ;
	if (ft_printf("ra\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	rb(t_stack **a, t_stack **b, bool print)
{
	rotate(b);
	if (!print)
		return ;
	if (ft_printf("rb\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	rr(t_stack **a, t_stack **b, bool print)
{
	rotate(a);
	rotate(b);
	if (!print)
		return ;
	if (ft_printf("rr\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}
