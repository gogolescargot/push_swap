/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:22:13 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/12 19:43:39 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	**init_variables(void)
{
	char	**move;

	move = malloc(sizeof(char *) * 11);
	move[0] = "sa";
	move[1] = "sb";
	move[2] = "ss";
	move[3] = "pa";
	move[4] = "pb";
	move[5] = "ra";
	move[6] = "rb";
	move[7] = "rr";
	move[8] = "rra";
	move[9] = "rrb";
	move[10] = "rrr";
	return (move);
}

void	*init_functions(void)
{
	void	**functions;

	functions = malloc(sizeof(void *) * 11);
	functions[0] = sa;
	functions[1] = sb;
	functions[2] = ss;
	functions[3] = pa;
	functions[4] = pb;
	functions[5] = ra;
	functions[6] = rb;
	functions[7] = rr;
	functions[8] = rra;
	functions[9] = rrb;
	functions[10] = rrr;
	return (functions);
}

bool	call_functions(char *s, t_stack **a, t_stack **b)
{
	char	**move;
	void	*functions;
	int		i;

	move = init_variables();
	functions = init_functions();
	i = 10;
	if (!s || !s[0])
		return (free(move), free(functions), false);
	while (i >= 0)
	{
		if (ft_strnstr(s, move[i], ft_strlen(move[i]))
			&& (s[ft_strlen(move[i])] == '\n' || !s[ft_strlen(move[i])]))
		{
			((void (*)(t_stack **, t_stack **, bool))
				((void **)functions)[i])(a, b, false);
			return (free(move), free(functions), true);
		}
		i--;
	}
	return (free(move), free(functions), false);
}

int	main(int argc, char **argv)
{
	char	*move;
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
	while (1)
	{
		move = get_next_line(1);
		if (!move)
			break ;
		if (!call_functions(move, &a, &b))
			(ft_putstr_fd("Error\n", 2), free(move),
				free_stack(a, b), get_next_line(-1), exit(1));
		free(move);
	}
	check_end(a, b, move);
	return (0);
}
