/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/15 22:15:15 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

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

	t_stack *stack_a = malloc(sizeof(t_stack));
	stack_a->top_node = NULL;
	stack_a->bottom_node = NULL;
	i = argc - 1;
	while (i)
	{
		t_stk_nd *node = NULL;
		int *n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		node = create_stk_node(n);
		stck_add(node, stack_a);
		//printf("top_node = %s \n", (char *)	stack_a->top_node->content);
		//printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
		i--;
	}	
	/*printing to see if this shit works
	t_stk_nd *curr_elemen = stack_pop(stack_a);
	while (curr_elemen != NULL)
	{
		printf("%d\n", *((int *) curr_elemen->content));
		if (stack_a->top_node == NULL && stack_a->bottom_node == NULL)
			break;
		//printf("top_node = %s \n", (char *)	stack_a->top_node->content);
		//printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
		curr_elemen = stack_pop(stack_a);
	}*/
	// BUBBLE SORT LOGIC
	t_stack *stack_b = malloc(sizeof(t_stack));
	int	is_stka_sort = 0;
	//int is_stkb_sort = 1;
	while (!is_stka_sort)
	{
		is_stka_sort = 1;
		//is_stkb_sort = 1;
		t_stk_nd *node = NULL;
		node = stack_a->top_node;
		while (node && node != stack_a->bottom_node)
		{
			node = stack_a->top_node;
			if (!node->previous)
			{
				t_stk_nd *b_node = stack_pop(stack_b);
				while (b_node)
				{
					printf("pa\n");
					stck_add(b_node, stack_a);
					b_node = stack_pop(stack_b);
				}
				/*t_stk_nd *curr_elemen = stack_a->top_node;
				while (curr_elemen != NULL)
				{
					printf("%d\n", *((int *) curr_elemen->content));
					if (stack_a->top_node == NULL && stack_a->bottom_node == NULL)
						break;
					//printf("top_node = %s \n", (char *)	stack_a->top_node->content);
					//printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
					curr_elemen = stack_pop(stack_a);
				}*/
				return (0);
			}
			int curr_value = *((int *) node->content);
			int next_value = *((int *) node->previous->content);
			//printf("c value: %d n value: %d\n", curr_value, next_value);
			if (curr_value <= next_value)
			{
				printf("pb\n");
				t_stk_nd *aux = stack_pop(stack_a);
				stck_add(aux, stack_b);
				is_stka_sort = 0;
				// stk_b check
				if (stack_b->top_node->previous 
					&& (*((int *) stack_b->top_node->content) < *((int *) stack_b->top_node->previous->content)))
				{
					printf("sb\n");
					t_stk_nd *aux = stack_pop(stack_b);
					t_stk_nd *aux2 = stack_pop(stack_b);
					stck_add(aux, stack_b);
					stck_add(aux2, stack_b);
				}
				continue;
			}
			else
			{
				printf("sa\n");
				t_stk_nd *aux = stack_pop(stack_a);
				t_stk_nd *aux2 = stack_pop(stack_a);
				stck_add(aux, stack_a);
				stck_add(aux2, stack_a);
				is_stka_sort = 0;
				continue;
			}
			break;
		}
	}













}
