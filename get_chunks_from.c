/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks_from.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:44:05 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/29 19:45:08 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_ops.h"

static int	is_on_stack(t_stk *stk, int value);
static void	rot_to_biggest(t_stk *stk_b, int *next_big_i);
static void	rev_rot_bottom(t_stk *stk, int next_big, int *i, int *down);
static void	send_to_bottom_a(t_stk *stk_a, t_stk *stk_b, int *down);

void	get_chunks(t_stk *stk_b, t_stk *stk_a, long int *sorted, int size)
{
	int	next_big;
	int	next_big_i;
	int	i;
	int	down;

	i = size - 1;
	down = 0;
	while (stk_b->size || down)
	{
		next_big = sorted[i];
		next_big_i = is_on_stack(stk_b, next_big);
		if (next_big_i != -1 && stk_b->size)
		{
			if (next_big == stk_b->top_node->value)
			{
				push_to_a(stk_b, stk_a);
				i--;
			}
			else
				send_to_bottom_a(stk_a, stk_b, &down);
			rot_to_biggest(stk_b, &next_big_i);
		}
		else
			rev_rot_bottom(stk_a, next_big, &i, &down);
	}
}

static int	is_on_stack(t_stk *stk, int value)
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

static void	send_to_bottom_a(t_stk *stk_a, t_stk *stk_b, int *down)
{
	int	top_b;
	int	bottom_a;

	top_b = 0;
	bottom_a = 0;
	if (stk_b->size != 0)
		top_b = stk_b->top_node->value;
	if (stk_a->size != 0)
		bottom_a = stk_a->bottom_node->value;
	if (*down == 0 || (stk_a->size && top_b > bottom_a))
	{
		push_to_a(stk_b, stk_a);
		rot_up_a(stk_a);
		*down = *down + 1;
	}
}

static void	rot_to_biggest(t_stk *stk_b, int *next_big_i)
{
	if (*next_big_i < (((int) stk_b->size) / 2))
	{
		rot_up_b(stk_b);
		*next_big_i = *next_big_i - 1;
	}
	else if (*next_big_i < ((int) stk_b->size))
	{
		rot_down_b(stk_b);
		*next_big_i = *next_big_i + 1;
	}
}

static void	rev_rot_bottom(t_stk *stk_a, int next_big, int *i, int *down)
{
	if (next_big == stk_a->bottom_node->value)
	{
		rot_down_a(stk_a);
		*i = *i - 1;
		*down = *down - 1;
	}
}
