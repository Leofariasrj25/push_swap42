/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_chunks_from.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:44:05 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/03 21:36:11 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_ops.h"

static int	rot_to_biggest(t_stk *stk_b, int next_big_i);
int			sort_stack_a(t_stk *stk_a, int *up, int *down, int next_big);
void		place_ordered(t_stk *stk_a, t_stk *stk_b, int *up, int *down);
int			get_value_from(t_stk *stk_b, t_stk *stk_a, int *up, int *down);

int	get_value_from(t_stk *stk_b, t_stk *stk_a, int *up, int *down)
{
	if (stk_b->size == 0)
		return (0);
	if (stk_b->top_node->value < stk_a->top_node->value
		&& (*down == 0 || stk_b->top_node->value > stk_a->bottom_node->value))
	{
		push_to_a(stk_b, stk_a);
		*up = *up + 1;
		return (1);
	}
	else if (*down == 0 || stk_b->top_node->value > stk_a->bottom_node->value)
	{
		while (*up && stk_b->top_node->value > stk_a->top_node->value)
		{
			rot_up_a(stk_a);
			*up = *up - 1;
			*down = *down + 1;
		}
		push_to_a(stk_b, stk_a);
		*up = *up + 1;
		return (1);
	}
	return (0);
}

void	place_ordered(t_stk *stk_a, t_stk *stk_b, int *up, int *down)
{
	while (*up > 1)
	{
		rot_up_a(stk_a);
		*up = *up - 1;
		*down = *down + 1;
	}
	push_to_a(stk_b, stk_a);
	if (*up == 1)
		swap_a(stk_a);
}

int	sort_stack_a(t_stk *stk_a, int *up, int *down, int next_big)
{
	if (stk_a->size == 0)
		return (0);
	if (is_on_stack(stk_a, next_big, *up) != -1)
	{
		*up = *up - 1;
		return (1);
	}
	else if (stk_a->size && stk_a->bottom_node->value == next_big)
	{
		rot_down_a(stk_a);
		*down = *down - 1;
		return (1);
	}
	return (0);
}

void	get_chunks(t_stk *stk_b, t_stk *stk_a, long int *sorted, int size)
{
	int	i;
	int	down;
	int	up;

	i = size - 1;
	up = 0;
	down = 0;
	while (stk_b->size || down > 0 || up > 0)
	{
		if (sort_stack_a(stk_a, &up, &down, sorted[i]))
				i--;
		else if (stk_b->size && sorted[i] == stk_b->top_node->value)
		{
			place_ordered(stk_a, stk_b, &up, &down);
			i--;
		}
		else if (get_value_from(stk_b, stk_a, &up, &down))
			continue ;
		else if (rot_to_biggest(stk_b, sorted[i]))
			continue ;
		else
			i--;
	}
}

static int	rot_to_biggest(t_stk *stk_b, int next_big)
{
	int	next_big_i;

	if (stk_b->size == 0)
		return (0);
	next_big_i = is_on_stack(stk_b, next_big, (int) stk_b->size);
	if (next_big_i != -1 && next_big_i < (((int) stk_b->size) / 2))
	{
		rot_up_b(stk_b);
		next_big_i--;
		return (1);
	}
	else if (next_big_i != -1 && next_big_i < ((int) stk_b->size))
	{
		rot_down_b(stk_b);
		next_big_i++;
		return (1);
	}
	else
		return (0);
}
