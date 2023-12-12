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
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return (false);
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = *stack;
	*stack = temp;
	return (true);
}

void	sa(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	if (!print)
		return ;
	if (ft_printf("sa\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	sb(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	if (!print)
		return ;
	if (ft_printf("sb\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	ss(t_stack **a, t_stack **b, bool print)
{
	swap(a);
	swap(b);
	if (!print)
		return ;
	if (ft_printf("ss\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}
