/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:19:36 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:35:42 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

bool	push(t_stack **src, t_stack **dst)
{
	t_stack	*first;
	t_stack	*second;

	if (!src || !*src || !dst)
		return (false);
	first = (*src);
	second = (*src)->next;
	first->next = NULL;
	*src = second;
	if (!*dst)
		*dst = first;
	else
	{
		first->next = *dst;
		*dst = first;
	}
	return (true);
}

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		return ;
	if (ft_printf("pa\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}

void	pb(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		return ;
	if (ft_printf("pb\n") < 3)
		(free_stack(*a, *b), ft_putstr_fd("Error\n", 2), exit(1));
}
