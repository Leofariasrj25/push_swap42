/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:50:33 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 00:58:02 by lfarias-         ###   ########.fr       */
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
static long int	*get_lngint_values(char *str_values, int *n_size);
static void		destroy(char **matrix, long int *arr1, long int *arr2);

long int	*parse_input(char **input, int input_size, int *n_size)
{
	long int	*int_values;
	char 		*str_values;
	
	str_values = get_str_values(input, input_size);
	if (!str_values)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
	}
	int_values = get_lngint_values(str_values, n_size);
	free(str_values);
	if (!int_values)
	{
		ft_putendl_fd("Error", 2);
		exit(1);
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
	while(i < size && input[i])
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

static long int	*get_lngint_values(char *str_values, int *size)
{
	char		**holder;
	long int	*lngint_values;
	long int	*temp;
	int			i;

	holder = ft_split(str_values, ' ');	
	i = 0;
	*size = 0;
	while (holder[i++])
		*size = *size + 1;
	lngint_values = malloc(sizeof(long int) * *size);
	i = 0;
	while (i < *size)
	{
		temp = parse_int(holder[i]);
		if (!temp || *temp < INT_MIN || *temp > INT_MAX)
		{
			destroy(holder, temp, lngint_values);
			return (NULL);
		}
		lngint_values[i] = *temp;
		free(temp);
		i++;
	}
	destroy(holder, NULL, NULL);
	return (lngint_values);
}

static void destroy(char **matrix, long int *temp, long int *values)
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

