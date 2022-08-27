/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/26 20:43:40 by lfarias-         ###   ########.fr       */
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
	number_sent = ft_calloc(stack_size, sizeof(int));
	while (stk_a->size)
	{
		while (!is_chunk_sent(number_sent, start, end) && stk_a->size)
		{
			int number = *((int *) stk_a->top_node->content);
			int n_index = is_in_range(number, start, end, val_list);
			if (n_index != -1 && number_sent[n_index] != 1)
			{
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
				stk_rot_up(stk_a);
				printf("ra\n");
			}
		}	
		start = start - offset;
		end = end + offset;
	}
	free(number_sent);
}

int	is_on_stack(t_stk *stk, int value)
{
	t_stk_nd	*node;
	int			number;
	int			i;

	node = stk->top_node;
	number = 0;
	i = 0;
	while(node)
	{
		number = *((int *) node->content);
		if (number == value)
			return (i);
		i++;
		node = node->previous;
	}
	return (-1);
}

void get_chunks_from(t_stk *stk_b, t_stk *stk_a, int *val_list, int stack_size)
{
	int	nbig;
	int	nbig_i;
	int	i;
	int down;

	//get the next biggest number, see if it's in stack-b
	//if true, check if its on top of stack-b
	// if above true push it to stack_a
	//if not check if top of stack-b is greater than tail of stack-a OR down = 0
	//if not, calculate, based on the stack size if its better to rotate up or rotate down
	// the next biggest number is always the index of prev_num + 1;
	down = 0;	
	i = stack_size - 1;
	while (stk_b->size || down == 0)
	{
		if (stk_b->size != 0 && i >= 0)
			nbig = val_list[i]; 
		nbig_i = is_on_stack(stk_b, nbig);
		if (nbig_i != -1)
		{
			// if the number is on the stack
			// check if its the top number on top of stack_b
			// if there are down elements, they should go up
			if (*((int *) stk_b->top_node->content) == nbig)
			{
				stk_add(stk_pop(stk_b), stk_a);
				printf("pa\n");
			}
			else if ((*((int *) stk_b->top_node->content) > *((int *) stk_a->bottom_node->content)) || down == 0)
			{
				stk_add(stk_pop(stk_b), stk_a);
				printf("pa\n");
				stk_rot_up(stk_a);
				printf("ra\n");
				down++;
			}
			else
			{
				if (nbig_i < (((int) stk_b->size) / 2))
				{
					while (nbig_i > 0)
					{
						printf("rb\n");
						stk_rot_up(stk_b);
						nbig_i--;
					}
				}
				else
				{
					while (nbig_i < (int) stk_b->size)
					{
						printf("rrb\n");
						stk_rot_down(stk_b);
						nbig_i++;
					}
				}
			}
		}
		else
		{
			if (nbig == *((int *) stk_a->bottom_node->content))	
			{
				printf("rra\n");
				stk_rot_down(stk_a);
				down--;
			}
			i--;
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
		int *n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		node = stk_new_node(n);
		stk_add(node, stack_a);
		vals[--i] = *n;
	}	
	vals = mergesort(vals, argc - 1);
	/*for (int j = 0; j < (argc - 1); j++)
		printf("%d ", vals[j]);
	printf("\n"); */
	t_stk *stack_b = stk_create();
	send_chunks_to(stack_b, stack_a, vals, stack_a->size);		
	get_chunks_from(stack_b, stack_a, vals, stack_b->size);
}
