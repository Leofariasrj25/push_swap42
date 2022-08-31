/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:43:16 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 00:57:28 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_ops.h"

static int		make_space(t_stk *stk_a, t_stk *b, int i);
static int		put_middle(t_stk *stk_a, t_stk *stk_b);
static int		put_top_bottom(t_stk *stk_a, t_stk *stk_b);

void	sort_three(t_stk *stk_a)
{
	int	num_a;
	int	num_b;
	int	num_c;

	num_a = stk_a->top_node->value;
	num_b = stk_a->top_node->previous->value;
	num_c = stk_a->bottom_node->value;
	if (num_a > num_b && (num_a < num_c && num_b < num_c))
		swap_a(stk_a);
	else if (num_a > num_b && (num_a > num_c && num_b > num_c))
	{
		swap_a(stk_a);
		rot_down_a(stk_a);
	}
	else if (num_a > num_b && (num_b < num_c && num_a > num_c))
		rot_up_a(stk_a);
	else if (num_a < num_b && (num_a < num_c && num_b > num_c))
	{
		swap_a(stk_a);
		rot_up_a(stk_a);
	}
	else if (num_a < num_b && (num_a > num_c && num_b > num_c))
		rot_down_a(stk_a);
}

void	sort_five(t_stk *stk_a, t_stk *stk_b)
{
	int	i;

	if (stk_a->size == 5)
		push_to_b(stk_a, stk_b);
	push_to_b(stk_a, stk_b);
	if (stk_b->size == 2
		&& stk_b->top_node->value > stk_b->top_node->previous->value)
		swap_b(stk_b);
	sort_three(stk_a);
	i = stk_b->size;
	while (i)
	{
		if (put_top_bottom(stk_a, stk_b))
			i--;
		else
		{
			put_middle(stk_a, stk_b);
			i--;
		}
	}
}

static int	put_top_bottom(t_stk *stk_a, t_stk *stk_b)
{
	int	top_b;

	top_b = stk_b->top_node->value;
	if (top_b < stk_a->top_node->value)
	{
		push_to_a(stk_b, stk_a);
		return (1);
	}
	else if (top_b > stk_a->bottom_node->value)
	{
		push_to_a(stk_b, stk_a);
		rot_up_a(stk_a);
		return (1);
	}
	return (0);
}

static int	put_middle(t_stk *stk_a, t_stk *stk_b)
{
	int			i;
	t_stk_nd	*node;

	i = 0;
	node = stk_a->top_node;
	while (node && stk_b->size)
	{
		if (node->value < stk_b->top_node->value)
			i++;
		node = node->previous;
	}
	if (i == 1)
	{
		push_to_a(stk_b, stk_a);
		swap_a(stk_a);
		return (1);
	}
	else
		return (make_space(stk_a, stk_b, i));
	return (0);
}

static int	make_space(t_stk *stk_a, t_stk *stk_b, int i)
{
	int	down;

	down = stk_a->size - i;
	while (stk_b->size && down--)
	{
		rot_down_a(stk_a);
	}
	push_to_a(stk_b, stk_a);
	down = (stk_a->size - i);
	while (down--)
	{
		rot_up_a(stk_a);
	}
	return (1);
}
