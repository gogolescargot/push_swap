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

bool	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	last = f_last(*stack);
	second_last = f_s_last(*stack);
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
	return (true);
}

void	rra(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	if (!print)
		return ;
	if (ft_printf("rra\n") < 4)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	rrb(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		return ;
	if (ft_printf("rrb\n") < 4)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	rrr(t_stack **a, t_stack **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		return ;
	if (ft_printf("rrr\n") < 4)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}
