/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:50:33 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 14:10:14 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

#ifndef INT_MIN
# define INT_MIN -2147483648
#endif

static char		*get_str_values(char **input, int size);
static long int	*get_lngint_values(char *str_values, int *n_size, int arg_size);
static void		destroy(char **matrix, long int *arr1, long int *arr2);
static char		**get_holder(char *str_values, int *num_qtty, int args_size);

long int	*parse_input(char **input, int input_size, int *n_size)
{
	long int	*int_values;
	char		*str_values;

	str_values = get_str_values(input, input_size);
	if (!str_values)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	int_values = get_lngint_values(str_values, n_size, input_size);
	free(str_values);
	if (!int_values)
	{
		ft_putendl_fd("Error", 2);
		exit(127);
	}
	return (int_values);
}

static char	*get_str_values(char **input, int size)
{
	char		*aux1;
	char		*aux2;
	char		*str_values;
	int			i;

	if (size == 0)
		return (NULL);
	aux1 = ft_strjoin(*input, " ");
	aux2 = NULL;
	str_values = aux1;
	i = 1;
	while (i < size && input[i])
	{
		aux1 = ft_strjoin(input[i], " ");
		aux2 = str_values;
		str_values = ft_strjoin(str_values, aux1);
		free(aux1);
		free(aux2);
		i++;
	}
	return (str_values);
}

static long int	*get_lngint_values(char *str_values, int *num_qtty, int ag_size)
{
	char		**holder;
	long int	*lngint_values;
	long int	*temp;
	int			i;

	holder = get_holder(str_values, num_qtty, ag_size);
	lngint_values = malloc(sizeof(long int) * *num_qtty);
	i = 0;
	while (i < *num_qtty)
	{
		temp = parse_int(holder[i]);
		if (!temp || *temp < INT_MIN || *temp > INT_MAX)
		{
			destroy(holder, temp, lngint_values);
			return (NULL);
		}
		lngint_values[i++] = *temp;
		free(temp);
	}
	destroy(holder, NULL, NULL);
	return (lngint_values);
}

static char	**get_holder(char *str_values, int *num_qtty, int args_size)
{
	int		i;
	char	**holder;

	holder = ft_split(str_values, ' ');
	i = 0;
	*num_qtty = 0;
	while (holder[i++])
		*num_qtty = *num_qtty + 1;
	if (*num_qtty < args_size)
	{
		destroy(holder, NULL, NULL);
		return (NULL);
	}
	return (holder);
}

static void	destroy(char **matrix, long int *temp, long int *values)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	if (temp)
		free(temp);
	if (values)
		free(values);
}
