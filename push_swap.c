/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 13:02:43 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

static void	push_swap(long int *vals, long int *sorted_vals, int size);
static void	destroy(t_stk *stka, t_stk *stkb, long int *arr1, long int *arr2);

int	main(int argc, char *argv[])
{
	long int	*vals;
	long int	*sorted;
	int			input_size;
	int			n_size;

	input_size = argc - 1;
	if (input_size == 0)
		return (0);
	n_size = 0;
	vals = parse_input(&argv[1], input_size, &n_size);
	if (n_size == 1 || check_is_sort(vals, n_size))
	{
		free(vals);
		return (0);
	}
	sorted = dup_val_lst(vals, n_size);
	sorted = mergesort(sorted, n_size);
	if (!check_no_dups(sorted, n_size))
	{
		destroy(NULL, NULL, vals, sorted);
		ft_putendl_fd("Error", 2);
		exit(127);
	}
	push_swap(vals, sorted, n_size);
}

static void	push_swap(long int *input_vals, long int *sorted_vals, int size)
{
	t_stk		*stack_a;
	t_stk		*stack_b;

	stack_a = stk_create_from(input_vals, size);
	stack_b = stk_create();
	if (stack_a->size == 2
		&& stack_a->top_node->value > stack_a->bottom_node->value)
	{
		swap_a(stack_a);
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		send_chunks(stack_b, stack_a, sorted_vals, stack_a->size);
		get_chunks(stack_b, stack_a, sorted_vals, stack_b->size);
	}
	print_op(FLUSH_OP);
	destroy(stack_a, stack_b, input_vals, sorted_vals);
}

static void	destroy(t_stk *stk1, t_stk *stk2, long int *input, long int *sort)
{
	stk_clean(stk1);
	stk_clean(stk2);
	free(input);
	free(sort);
}
