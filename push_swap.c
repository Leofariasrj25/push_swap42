/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/26 10:21:30 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"
#include "bubblesort.h"
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

void	send_chunks_to(t_stk *stk_b, t_stk *stk_a, int *val_list, int stack_size)
{
	int	*number_sent;
	int	middle;
	int	offset;
	int	start;
	int	end;

	middle = stack_size / 2;
	offset = stack_size / get_const(stack_size);
	start = middle - offset;
	end = middle + offset;
	number_sent = ft_calloc(stk_a->size, sizeof(int));
	while (((int) stk_a->size))
	{
		while (!is_chunk_sent(number_sent, start, end) && stk_a->size)
		{
			int number = *((int *) stk_a->top_node->content);
			int n_index = is_in_range(number, start, end, val_list);
			if (n_index != -1 && number_sent[n_index] != 1)
			{
				//printf("n_index: %d\n", n_index);
				number_sent[n_index] = 1;
				stk_add(stk_pop(stk_a), stk_b);
				printf("pb\n");
				if (number < middle)
				{
					stk_rot_up(stk_b);
					printf("rb\n");
				}
			}
			else
			{
				/*printf("stack size: %d\n", stk_a->size);
				printf("number is: %d\n", number);
				printf("start: %d\n", start);
				printf("end: %d\n", end);*/
				stk_rot_up(stk_a);
				printf("ra\n");
			}
		}	
		start = start - offset;
		end = end + offset;
	}
	free(number_sent);
}

int	find_next_big(t_stk *stk, int *val_list, int previous_number, int stack_size)
{
	int pnum_i;
	int	next_biggest;
	int	next_biggest_i;
	t_stk_nd	*node;
	int	i;

	i = 0;
	while(i < stack_size)
	{
		if (val_list[i] == previous_number)
			break ;
		i++;
	}
	if (i < (stack_size - 2))
		next_biggest = val_list[i + 1];
	node = stk->top_node;
	next_biggest_i = 0;
	while(node)
	{
		if (next_biggest == *((int *) node->content))
			return (next_biggest_i);
		next_biggest_i++;
		node = node->next;
	}
	return (-1);
}

void get_chunks_from(t_stk *stk_b, t_stk  *stk_a, int *val_list, int stack_size)
{
	int	nbig;
	int nbig_i;
	
	if (stk_a->size == 0)
	{
		printf("");
	}
}

int	main(int argc, char *argv[])
{
	
	// OBJECTIVE: sort a list of numbers using two stacks (a and b) and print all
	// the operations needed to make the stack a be sorted in ascending order.

	// receive a list of numbers from argv
	// convert each number into its integer couterpart
	// store the number into a node
	// place this node into a stack (called a)
	// create another stack (called b)
	// sort the numbers using these two stacks 	
	int i;

	int *vals = malloc(sizeof(int) * (argc - 1));
	t_stk *stack_a = malloc(sizeof(t_stk));
	stack_a->top_node = NULL;
	stack_a->bottom_node = NULL;
	i = argc - 1;
	while (i)
	{
		t_stk_nd *node = NULL;
		int *n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		node = stk_new_node(n);
		stk_add(node, stack_a);
		vals[--i] = *n;
		//printf("top_node = %s \n", (char *)	stack_a->top_node->content);
		//printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
	}	
	vals = mergesort(vals, argc - 1);
	/*for (int j = 0; j < (argc - 1); j++)
		printf("%d ", vals[j]);
	printf("\n"); */
	t_stk *stack_b = stk_create();
	send_chunks_to(stack_b, stack_a, vals, stack_a->size);		
}
