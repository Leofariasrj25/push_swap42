/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunks_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:32:00 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/30 17:20:50 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"

static int	is_in_range(int number, int start, int end, long int *sorted);
static int	is_chunk_sent(int *range, int start, int end);
//static void	rotnext_chunk_val(t_stk *stk, int start, int end, long int *sorted);

void	send_chunks(t_stk *stk_b, t_stk *stk_a, long int *sorted, int size)
{
	int	*number_sent;
	int	start;
	int	end;
	int	n_index;

	set_chunk_rng(&start, &end, size);
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
		update_chunk_rng(&start, &end, size);
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

/*static void	rotnext_chunk_val(t_stk *stk, int start, int end, long int *sorted)
{
	if (is_in_range(stk->bottom_node->value, start, end, sorted) != -1)
		rot_down_a(stk);
	else
		rot_up_a(stk);
}*/
