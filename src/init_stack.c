/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:37:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:49:58 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	append_node(int n, t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->data = n;
	if (!*stack)
		*stack = node;
	else
	{
		temp = find_last_stack(*stack);
		temp->next = node;
	}
}

bool	init_stack(t_stack **stack, char **argv)
{
	long	n;
	size_t	i;

	i = 1;
	while (argv[i])
	{
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN || check_duplicate(*stack, (int)n))
			return (false);
		append_node(n, stack);
		i++;
	}
	return (true);
}
