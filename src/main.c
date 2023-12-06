/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:28:14 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/05 23:28:14 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putstr_fd("Error\n", 2), 1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	if (check_syntax(argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	a = init_stack(argv);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), 1);
	ft_printf("\n======= EXEC =======\n");
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, true);
		else if (stack_size(a) == 3)
			sort_three(&a);
		// else
			//sort turk
	}

// DEBUG

	ft_printf("======= ST A =======\n");
	while (a)
	{
		ft_printf("%d\n", a->data);
		a = a->next;
	}
	ft_printf("======= ST B =======\n");
	while (b)
	{
		ft_printf("%d\n", b->data);
		b = b->next;
	}

// END DEBUG

	return (0);
}
