/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunks_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:32:00 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 01:15:23 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"

#define SET_RNG 0
#define UPDT_RNG 1

static int	is_in_range(int number, int start, int end, long int *sorted);
static int	is_chunk_sent(int *range, int start, int end);
static void	set_chunk_rng(int *start, int *end, int stk_size, int flag);
static int	get_const(int stack_size);

void	send_chunks(t_stk *stk_b, t_stk *stk_a, long int *sorted, int size)
{
	int	*number_sent;
	int	start;
	int	end;
	int	n_index;

	set_chunk_rng(&start, &end, size, SET_RNG);
	number_sent = ft_calloc(size, sizeof(int));
	while (stk_a->size)
	{
		while (!is_chunk_sent(number_sent, start, end) && stk_a->size)
		{
			n_index = is_in_range(stk_a->top_node->value, start, end, sorted);
			if (n_index != -1 && number_sent[n_index] != 1)
			{
				number_sent[n_index] = 1;
				push_to_b(stk_a, stk_b);
				if (stk_b->top_node->value < (size / 2))
					rot_up_b(stk_b);
			}
			else
				rot_up_a(stk_a);
		}	
		set_chunk_rng(&start, &end, size, UPDT_RNG);
	}
	free(number_sent);
}

static int	is_in_range(int number, int start, int end, long int *sorted)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (number == sorted[i])
			return (i);
		else
			i++;
	}	
	return (-1);
}

static int	is_chunk_sent(int *range, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (range[i] == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

static int	get_const(int stack_size)
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

static void	set_chunk_rng(int *start, int *end, int stk_size, int flag)
{
	int	offset;

	offset = stk_size / get_const(stk_size);
	if (flag == 0)
	{
		*start = (stk_size / 2) - offset;
		*end = (stk_size / 2) + offset;
	}
	else
	{
		*start = *start - offset;
		*end = *end + offset;
		if (*start < 0)
			*start = 0;
		if (*end >= stk_size)
			*end = stk_size - 1;
	}
}
