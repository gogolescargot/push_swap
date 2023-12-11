/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 00:37:29 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:49:58 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	atol(const char *nptr)
{
	size_t	i;
	size_t	r;
	int		s;

	i = 0;
	r = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == 45)
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == 43)
		i++;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		r = nptr[i++] - 48 + (r * 10);
		if ((r > 2147483647 && s == 1) || (r > 2147483648 && s == -1))
			return (2147483649);
	}
	return (r * s);
}

static void	append_node(int n, t_stack **stack)
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
		temp = f_last(*stack);
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
