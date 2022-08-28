/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:24:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/27 21:44:18 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stack_ops.h"

static char	*get_op_str(const int OP);

void	print_op(const int OP)
{
	static int	stk_op;

	if (stk_op == 0)
		stk_op = OP;
	else if ((stk_op == STACK_SA && OP == STACK_SB)
		|| (stk_op == STACK_SB && OP == STACK_SA))
	{
		stk_op = STACK_SS;
	}
	else if ((stk_op == STACK_RA && OP == STACK_RB)
		|| (stk_op == STACK_RB && OP == STACK_RA))
	{
		stk_op = STACK_RR;
	}
	else if ((stk_op == STACK_RRA && OP == STACK_RRB)
		|| (stk_op == STACK_RRB && OP == STACK_RRA))
	{
		stk_op = STACK_RRR;
	}
	else if (stk_op != 0 || OP == FLUSH_OP)
	{
		ft_putendl_fd(get_op_str(stk_op), 1);
		stk_op = OP;
	}
}

static char	*get_op_str(const int OP)
{
	static char	*op_str[] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	return (op_str[OP - 1]);
}
