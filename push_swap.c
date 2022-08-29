/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/29 19:36:31 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"
#include "libft/libft.h"
#include <stdlib.h>

#ifndef INT_MAX
# define INT_MAX 2147483647
#endif

#ifndef INT_MIN
# define INT_MIN -2147483648
#endif
#include <stdio.h>

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

long int	check_vals(long int *values, int size)
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

int	main(int argc, char *argv[])
{
	long int	*vals;
	long int	*sorted;
	int			input_size;
	t_stk		*stack_a;
	t_stk		*stack_b;

	input_size = argc - 1;
	if (input_size == 0)
		return (0);
	if (input_size == 1)
		return (0);
	vals = parse_input(&argv[1], input_size);
	if (is_already_sort(vals, input_size))
	{
		free(vals);
		return(0);
	}
	sorted = dup_val_lst(vals, input_size);
	sorted = mergesort(sorted, input_size);
	if (!check_vals(sorted, input_size))
	{
		free(vals);
		free(sorted);
		ft_putendl_fd("Error!", 1);
		exit(1);
	}
	stack_a = stk_create_from(vals, argc - 1); 
	stack_b = stk_create();
	// *this is working as intended!*
	if (stack_a->size == 2)
		swap_a(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		send_chunks(stack_b, stack_a, sorted, stack_a->size);
		get_chunks(stack_b, stack_a, sorted, stack_b->size);
	}
	print_op(FLUSH_OP);
}
