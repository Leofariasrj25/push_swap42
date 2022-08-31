/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:04:11 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 00:56:21 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_no_dups(long int *values, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i > 0 && values[i] == values[i - 1])
			return (0);
		i++;
	}
	return (1);
}

long int	*dup_val_lst(long int *values, int size)
{
	int			i;
	long int	*dup;

	i = 0;
	dup = malloc(sizeof(long int) * size);
	while (i < size)
	{
		dup[i] = values[i];
		i++;
	}
	return (dup);
}

int	check_is_sort(long int *vals, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (vals[i] < vals[i + 1])
			i++;
		else
			return (0);
	}
	return (1);
}
