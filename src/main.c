/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:28:14 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:50:21 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!check_syntax(argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!init_stack(&a, argv))
		return (free_stack(a, b), ft_putstr_fd("Error\n", 2), 1);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, &b, true);
		else if (stack_size(a) == 3)
			a = sort_three(a);
		else
			a = sort_big(a, b);
	}
	free_stack(a, b);
	return (0);
}
