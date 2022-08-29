/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:50:33 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/29 20:33:38 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

long int	*parse_input(char **argv, int size)
{
	int	i;
	long int	*values;

	// TO-DO don't assume the input is perfect
	values = malloc(sizeof(long int) * size);
	i = 0;
	while (i < size)
	{
		values[i] = ft_atoi(argv[i]);
		i++;
	}
	return (values);
}

int	check_vals(long int *values, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (values[i] > INT_MAX || values[i] < INT_MIN)
			return (0);
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

int	is_already_sort(long int *vals, int size)
{
	int i;

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
