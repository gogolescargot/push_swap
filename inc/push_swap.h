/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:26:05 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 14:48:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/inc/libft.h"

typedef struct s_node
{
	int				data;
	int				min;
	int				max;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

char	**split(char const *s, char c);
long	atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

bool	check_duplicate(t_node *stack, int n);
bool	check_syntax(char **argv);

t_node	*find_last_node(t_node *stack);
int		find_max_pos(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*init_stack(char **argv);
int		stack_sorted(t_node *stack);
size_t	stack_size(t_node *stack);

void	sort_three(t_node **stack);
void	sort_five(t_node **a, t_node **b);
void	big_sort(t_node **a, t_node **b);

bool	swap(t_node **head);
void	sa(t_node **a, bool print);
void	sb(t_node **a, bool print);
void	ss(t_node **a, t_node **b, bool print);

bool	push(t_node **dst, t_node **src);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **a, t_node **b, bool print);

bool	rotate(t_node **stack);
void	ra(t_node **a, bool print);
void	rb(t_node **a, bool print);
void	rr(t_node **a, t_node **b, bool print);

bool	reverse_rotate(t_node **stack);
void	rra(t_node **a, bool print);
void	rrb(t_node **a, bool print);
void	rrr(t_node **a, t_node **b, bool print);

int		stack_some_sorted(t_node *stack);

void	print_stack(t_node *a, t_node *b);

#endif