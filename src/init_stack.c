/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:37:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 00:37:29 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

void	append_node(int n, t_node **stack)
{
	t_node	*node;
	t_node	*temp;

	if (!stack)
		return ;
	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->next = NULL;
	node->data = n;
	if (!*stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		temp = find_last_node(*stack);
		temp->next = node;
		node->prev = temp;
	}
}

t_node	*init_stack(char **argv)
{
	long	n;
	size_t	i;
	t_node	*stack;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		n = atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN || check_duplicate(stack, (int)n))
		{
			return (NULL);
		}
		append_node(n, &stack);
		i++;
	}
	return (stack);
}
