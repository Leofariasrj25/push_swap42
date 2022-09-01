/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:21:19 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 21:31:10 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_dups(long	int *values, int n_size)
{
	int			i;
	long int	*sorted;		

	if (!values)
		return (1);
	i = 0;
	sorted = malloc(sizeof(long int) * n_size);
	while (i < n_size)
	{
		sorted[i] = values[i];
		i++;
	}
	sorted = mergesort(sorted, n_size);
	i = 1;
	while (i < n_size)
	{
		if (sorted[i] == sorted[i - 1])
		{
			free(sorted);
			return (1);
		}
		i++;
	}
	free(sorted);
	return (0);
}
