/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 21:50:20 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/03 21:53:16 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"

int	get_const(int stack_size)
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
