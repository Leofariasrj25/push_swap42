/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 18:16:13 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
	int i;

	int *vals = malloc(sizeof(int) * (argc - 1));
	t_stk *stack_a = malloc(sizeof(t_stk));
	stack_a->top_node = NULL;
	stack_a->bottom_node = NULL;
	i = argc - 1;
	while (i)
	{
		t_stk_nd *node = NULL;
		int n = ft_atoi(argv[i]);
		node = stk_new_node(n);
		stk_add(node, stack_a);
		vals[--i] = n;
	}	
	vals = mergesort(vals, argc - 1);
	t_stk *stack_b = stk_create();
	if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size == 5)
		sort_five(stack_a, stack_b);
	else
	{
		send_chunks_to(stack_b, stack_a, vals, stack_a->size);
		get_chunks_from(stack_b, stack_a, vals, stack_b->size);
	}
	print_op(FLUSH_OP);
}
