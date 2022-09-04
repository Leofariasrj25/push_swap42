/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunks_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:32:00 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/03 21:55:59 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"

static int	is_in_range(int number, int start, int end, long int *sorted);
static int	is_chunk_sent(int *range, int start, int end);
void		send_to_b(t_stk *stk_a, t_stk *stk_b, int size);

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
				send_to_b(stk_a, stk_b, size);
			}
			else
				rot_up_a(stk_a);
			update_chunk_range(&start, &end, size, number_sent);
		}	
	}
	sort_three(stk_a);
	free(number_sent);
}

void	send_to_b(t_stk *stk_a, t_stk *stk_b, int size)
{
	push_to_b(stk_a, stk_b);
	if (stk_b->top_node->value < (size / 2))
		rot_up_b(stk_b);
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
