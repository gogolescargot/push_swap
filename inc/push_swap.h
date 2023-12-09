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

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}				t_stack;

char	**split(char const *s, char c);
long	atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

bool	check_duplicate(t_stack *stack, int n);
bool	check_syntax(char **argv);

t_stack	*find_last_stack(t_stack *stack);
t_stack	*find_second_last_stack(t_stack *stack);
int		find_median(t_stack *stack, t_stack *node);
t_stack	*find_target(t_stack *stack, t_stack *node, bool mode);
size_t	find_cost(t_stack *a, t_stack *b, t_stack *target_a, t_stack *target_b);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
t_stack	*init_stack(char **argv);
int		stack_sorted(t_stack *stack);
size_t	stack_size(t_stack *stack);

void	sort_three(t_stack **stack);
void	sort_mid(t_stack *a, t_stack *b);
void	sort_big(t_stack *a, t_stack *b);

bool	swap(t_stack **head);
void	sa(t_stack **a, bool print);
void	sb(t_stack **a, bool print);
void	ss(t_stack **a, t_stack **b, bool print);

bool	push(t_stack **dst, t_stack **src);
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);

bool	rotate(t_stack **stack);
void	ra(t_stack **a, bool print);
void	rb(t_stack **a, bool print);
void	rr(t_stack **a, t_stack **b, bool print);

bool	reverse_rotate(t_stack **stack);
void	rra(t_stack **a, bool print);
void	rrb(t_stack **a, bool print);
void	rrr(t_stack **a, t_stack **b, bool print);

int		stack_some_sorted(t_stack *stack);
void	print_stack(t_stack *a, t_stack *b);

#endif