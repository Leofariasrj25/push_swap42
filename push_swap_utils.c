/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:04:11 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 00:39:34 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

int	get_const(int stack_size)
{
	int	n;

	if (stack_size <= 10)
		n = 5;
	else if (stack_size <= 150)
		n = 8;
	else if (stack_size > 150)
		n = 18;
	return (n);
}

int	is_on_stack(t_stk *stk, int value)
{
	t_stk_nd	*node;
	int			number;
	int			i;

	node = stk->top_node;
	number = 0;
	i = 0;
	while (node)
	{
		number = node->value;
		if (number == value)
			return (i);
		i++;
		node = node->previous;
	}
	return (-1);
}

void	set_values(int *start, int *end, int *middle, int stk_size)
{
	int	offset;

	offset = stk_size / get_const(stk_size);
	*middle = stk_size / 2;
	*start = *middle - offset;
	*end = *middle + offset;
	
}

void	update_range(int *start, int *end, int stk_size)
{
		int offset;

		offset = stk_size / get_const(stk_size);
		*start = *start - offset;
		*end = *end + offset;
		if (*start < 0)
			*start = 0;
		if (*end >= stk_size)
			*end = stk_size - 1;
}
