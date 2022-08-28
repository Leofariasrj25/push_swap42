/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_chunks_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:34:04 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 17:37:27 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	set_chunk_rng(int *start, int *end, int stk_size)
{
	int	offset;
	int	middle;

	offset = stk_size / get_const(stk_size);
	middle = stk_size / 2;
	*start = middle - offset;
	*end = middle + offset;
}

void	update_chunk_rng(int *start, int *end, int stk_size)
{
	int	offset;

	offset = stk_size / get_const(stk_size);
	*start = *start - offset;
	*end = *end + offset;
	if (*start < 0)
		*start = 0;
	if (*end >= stk_size)
		*end = stk_size - 1;
}
