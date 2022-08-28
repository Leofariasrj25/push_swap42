/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:42:47 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/27 21:33:24 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"

void	push_to_a(t_stk *stk_b, t_stk *stk_a)
{
	if (!stk_b || !stk_b)
		return ;
	if (stk_b->size == 0)
		return ;
	stk_add(stk_pop(stk_b), stk_a);
	print_op(STACK_PA);
}

void	swap_a(t_stk *stk_a)
{
	if (!stk_a)
		return ;
	if (stk_a->size <= 1)
		return ;
	stk_swap(stk_a);
	print_op(STACK_SA);
}

void	rot_up_a(t_stk *stk_a)
{
	if (!stk_a)
		return ;
	if (stk_a->size <= 1)
		return ;
	stk_rot_up(stk_a);
	print_op(STACK_RA);
}

void	rot_down_a(t_stk *stk_a)
{
	if (!stk_a)
		return ;
	if (stk_a->size <= 1)
		return ;
	stk_rot_down(stk_a);
	print_op(STACK_RRA);
}
