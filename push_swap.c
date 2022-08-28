/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 00:44:16 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "stack_ops.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

int	is_in_range(int number, int start, int end, int *val_list)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if (number == val_list[i])
			return (i);
		else
			i++;
	}	
	return (-1);
}

int		is_chunk_sent(int *range, int start, int end)
{
	int	i;

	i = start;
	while (i <= end)
	{
		if(range[i] == 1)
			i++;
		else
			return (0);
	}
	return (1);
}

void	send_chunks_to(t_stk *stk_b, t_stk *stk_a, int *val_list, int stk_size)
{
	int	*number_sent;
	int	middle;
	int	start;
	int	end;

/*	middle = stk_size / 2;
	offset = stk_size / get_const(stk_size);
	start = middle - offset;
	end = middle + offset; */
	set_values(&start, &end, &middle, stk_size);
	number_sent = ft_calloc(stk_size, sizeof(int)); 
	while (stk_a->size)
	{
		while (!is_chunk_sent(number_sent, start, end) && stk_a->size)
		{
			int number = stk_a->top_node->value;
			int n_index = is_in_range(number, start, end, val_list);
			if (n_index != -1 && number_sent[n_index] != 1)
			{
				number_sent[n_index] = 1;
				push_to_b(stk_a, stk_b);
				if (number < middle)
					rot_up_b(stk_b);
			}
			else
				rot_up_a(stk_a);
		}	
		update_range(&start, &end, stk_size);
	}
	free(number_sent);
}

void get_chunks_from(t_stk *stk_b, t_stk *stk_a, int *val_list, int stk_size)
{
	int	next_big;
	int	next_big_i;
	int	i;
	int down;

	i = stk_size - 1;
	down = 0;
	while (stk_b->size || down)
	{
		next_big = val_list[i];
		next_big_i = is_on_stack(stk_b, next_big);
		if (next_big_i != -1 && stk_b->size)
		{
			if (next_big == stk_b->top_node->value)
			{
				push_to_a(stk_b, stk_a);
				i--;
			}
			else if (down == 0
				|| (stk_a->size && stk_b->top_node->value > stk_a->bottom_node->value))
			{
				push_to_a(stk_b, stk_a);
				rot_up_a(stk_a);
				down++;
			}
			if (next_big_i < (((int) stk_b->size) / 2))
			{
				rot_up_b(stk_b);
				next_big_i--;
			}
			else
			{
				rot_down_b(stk_b);
				next_big_i++;
			}
		}
		else
		{
			if (next_big == stk_a->bottom_node->value)
			{
				rot_down_a(stk_a);
				i--;
				down--;
			}
		}
	}
}

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
	send_chunks_to(stack_b, stack_a, vals, stack_a->size);		
	get_chunks_from(stack_b, stack_a, vals, stack_b->size);
	print_op(FLUSH_OP);
}
