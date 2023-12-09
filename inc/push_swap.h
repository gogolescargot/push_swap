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

typedef struct s_list
{
	int				data;
	struct s_list	*next;
}				t_list;

char	**split(char const *s, char c);
long	atol(const char *nptr);
void	ft_putstr_fd(char *s, int fd);

bool	check_duplicate(t_list *stack, int n);
bool	check_syntax(char **argv);

t_list	*find_last_list(t_list *stack);
t_list	*find_second_last_list(t_list *stack);
int		find_median(t_list *stack, t_list *node);
t_list	*find_target(t_list *stack, t_list *node, bool mode);
size_t	find_cost(t_list *a, t_list *b, t_list *target_a, t_list *target_b);
t_list	*find_min(t_list *stack);
t_list	*find_max(t_list *stack);
t_list	*init_stack(char **argv);
int		stack_sorted(t_list *stack);
size_t	stack_size(t_list *stack);

void	sort_three(t_list **stack);
void	sort_mid(t_list *a, t_list *b);
void	sort_big(t_list *a, t_list *b);

bool	swap(t_list **head);
void	sa(t_list **a, bool print);
void	sb(t_list **a, bool print);
void	ss(t_list **a, t_list **b, bool print);

bool	push(t_list **dst, t_list **src);
void	pa(t_list **a, t_list **b, bool print);
void	pb(t_list **a, t_list **b, bool print);

bool	rotate(t_list **stack);
void	ra(t_list **a, bool print);
void	rb(t_list **a, bool print);
void	rr(t_list **a, t_list **b, bool print);

bool	reverse_rotate(t_list **stack);
void	rra(t_list **a, bool print);
void	rrb(t_list **a, bool print);
void	rrr(t_list **a, t_list **b, bool print);

int		stack_some_sorted(t_list *stack);
void	print_stack(t_list *a, t_list *b);

#endif