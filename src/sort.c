/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 08:54:40 by ggalon            #+#    #+#             */
/*   Updated: 2023/12/06 19:06:44 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*sort_three(t_stack *stack)
{
	if (stack->data > stack->next->data
		&& stack->data > stack->next->next->data)
		ra(&stack, NULL, true);
	else if (stack->data < stack->next->data
		&& stack->data < stack->next->next->data)
		rra(&stack, NULL, true);
	else if (stack->data > stack->next->data)
		sa(&stack, NULL, true);
	else
		rra(&stack, NULL, true);
	if (!stack_sorted(stack))
		return (sort_three(stack));
	return (stack);
}

void	trg_tp(t_stack ***src, t_stack ***dst, t_stack **t_src, t_stack **t_dst)
{
	while (**src != *t_src || **dst != *t_dst)
	{
		if (f_med(**src, *t_src) && f_med(**dst, *t_dst)
			&& **src != *t_src && **dst != *t_dst)
			rr(*src, *dst, true);
		else if (!f_med(**src, *t_src) && !f_med(**dst, *t_dst)
			&& **src != *t_src && **dst != *t_dst)
			rrr(*src, *dst, true);
		else if (f_med(**src, *t_src) && **src != *t_src)
			ra(*src, *dst, true);
		else if (!f_med(**src, *t_src) && **src != *t_src)
			rra(*src, *dst, true);
		else if (f_med(**dst, *t_dst) && **dst != *t_dst)
			rb(*src, *dst, true);
		else if (!f_med(**dst, *t_dst) && **dst != *t_dst)
			rrb(*src, *dst, true);
	}
}

void	check_rotate(t_stack **src, t_stack **dst, size_t mode, size_t cst)
{
	t_stack	*cur;
	t_stack	*t_src;
	t_stack	*t_dst;

	while (stack_size(*src) > mode)
	{
		cur = *src;
		cst = f_cst(*src, *dst, cur, f_trg(*dst, cur, false));
		t_dst = f_trg(*dst, cur, (mode == 3));
		t_src = cur;
		while (cur && cst != 0)
		{
			if (f_cst(*src, *dst, cur, f_trg(*dst, cur, (mode == 3))) < cst)
			{
				cst = f_cst(*src, *dst, cur, f_trg(*dst, cur, (mode == 3)));
				t_dst = f_trg(*dst, cur, (mode == 3));
				t_src = cur;
			}
			cur = cur->next;
		}
		if (mode == 3)
			(trg_tp(&src, &dst, &t_src, &t_dst), pb(src, dst, true));
		else
			(trg_tp(&dst, &src, &t_dst, &t_src), pa(dst, src, true));
	}
}

bool	sort_rotation(t_stack **a, t_stack **b)
{
	if (stack_some_sorted(*a))
	{
		if (f_med(*a, f_max(*a)))
			while (!stack_sorted(*a))
				ra(a, b, true);
		else
			while (!stack_sorted(*a))
				rra(a, b, true);
		return (true);
	}
	return (false);
}

t_stack	*sort_big(t_stack *a, t_stack *b)
{
	if (sort_rotation(&a, &b))
		return (a);
	pb(&a, &b, true);
	pb(&a, &b, true);
	check_rotate(&a, &b, 3, 0);
	if (stack_size(a) == 3)
		a = sort_three(a);
	else if (stack_size(a) == 2 && !stack_sorted(a))
		sa(&a, &b, true);
	check_rotate(&b, &a, 0, 0);
	sort_rotation(&a, &b);
	return (a);
}
