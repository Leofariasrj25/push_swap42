/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:11:58 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/27 21:34:09 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"

void	push_to_b(t_stk *stk_a, t_stk *stk_b)
{
	if (!stk_a || !stk_a)
		return ;
	if (stk_a->size == 0)
		return ;
	stk_add(stk_pop(stk_a), stk_b);
	print_op(STACK_PB);
}

void	swap_b(t_stk *stk_b)
{
	if (!stk_b)
		return ;
	if (stk_b->size <= 1)
		return ;
	stk_swap(stk_b);
	print_op(STACK_SB);
}

void	rot_up_b(t_stk *stk_b)
{
	if (!stk_b)
		return ;
	if (stk_b->size <= 1)
		return ;
	stk_rot_up(stk_b);
	print_op(STACK_RB);
}

void	rot_down_b(t_stk *stk_b)
{
	if (!stk_b)
		return ;
	if (stk_b->size <= 1)
		return ;
	stk_rot_down(stk_b);
	print_op(STACK_RRB);
}
