/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunks_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:32:00 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/02 15:09:18 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"

#define SET_RNG 0
#define UPDT_RNG 1

static int	is_in_range(int number, int start, int end, long int *sorted);
static int	is_chunk_sent(int *range, int start, int end);
static int	get_const(int stack_size);
void		update_chunk_range(int *start, int *end, int stk_size, int *number_sent);
void		set_chunk_range(int *start, int *end, int stk_size);

void	send_chunks(t_stk *stk_b, t_stk *stk_a, long int *sorted, int size)
{
	int	*number_sent;
	int	start;
	int	end;
	int	n_index;

	number_sent = ft_calloc(size, sizeof(int));
	set_chunk_range(&start, &end, size);
	while (stk_a->size != 3)
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
		update_chunk_range(&start, &end, size, number_sent);
		}	
	}
	sort_three(stk_a);
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

	n = 1;
	if (stack_size <= 10)
		n = 5;
	else if (stack_size <= 150)
		n = 8;
	else if (stack_size > 150)
		n = 18;
	return (n);
}

void	set_chunk_range(int *start, int *end, int stk_size)
{
	int	offset;

	offset = stk_size / get_const(stk_size);
	*start = (stk_size / 2) - offset;
	*end = (stk_size / 2) + offset;
	if (*end >= (stk_size - 3))
		*end = stk_size - 4;
}

void	update_chunk_range(int *start, int *end, int stk_size, int *number_sent)
{
	int	i;

	i = *start;
	while (i < (stk_size / 2))
	{
		if (number_sent[i] != 1)
			break ;
		i++;
	}
	if (i == stk_size / 2)
		*start = *start - (stk_size / get_const(stk_size));
	i = stk_size / 2;
	while (i < *end)
	{
		if (number_sent[i] != 1)
			break ;
		i++;
	}
	if (i == *end && number_sent[i] == 1)
		*end = *end + (stk_size / get_const(stk_size));
	if (*start < 0)
		*start = 0;
	if (*end >= (stk_size - 3))
		*end = (stk_size - 4);
}
