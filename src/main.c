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

void	print_stack(t_node *a, t_node *b)
{
	ft_printf("a  |  b\n=======\n");
	while (1)
	{
		if (a)
			ft_printf("%d", a->data);
		else
			ft_printf(" ");
		ft_printf("  |  ");
		if (b)
			ft_printf("%d", b->data);
		else
			ft_printf(" ");
		ft_printf("\n");
		if (a && a->next)
			a = a->next;
		else
			a = NULL;
		if (b && b->next)
			b = b->next;
		else
			b = NULL;
		if (!a && !b)
			break ;
	}
	ft_printf("\n\n");
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (ft_putstr_fd("Error\n", 2), 1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	if (check_syntax(argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	a = init_stack(argv);
	if (!a)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (!stack_sorted(a))
	{
		if (stack_size(a) == 2)
			sa(&a, true);
		else if (stack_size(a) == 3)
			sort_three(&a);
		else if (stack_size(a) > 5)
			sort_big(a, b);
		else
			sort_big(a, b);
	}
	return (0);
}
