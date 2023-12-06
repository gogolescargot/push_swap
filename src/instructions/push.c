/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 06:19:36 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 06:19:36 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

bool	push(t_node **src, t_node **dst)
{
	t_node *first;
	t_node *second;

	if (!src || !*src || !dst)
		return (false);
	first = (*src);
	second = (*src)->next;
	first->next = NULL;
	if (second)
		second->prev = NULL;
	*src = second;

	if (!*dst)
		*dst = first;
	else
	{
		first->next = *dst;
		(*dst)->prev = first;
		*dst = first;
	}
	return (true);
}

void	pa(t_node **a, t_node **b, bool print)
{
	push(b, a);
	if (!print)
		return ;
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b, bool print)
{
	push(a, b);
	if (!print)
		return ;
	write(1, "pb\n", 3);
}
