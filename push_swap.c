/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/14 22:25:46 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
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
		node = create_stk_node(argv[i]);
		stck_add(node, stack_a);
		printf("top_node = %s \n", (char *)	stack_a->top_node->content);
		printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
		i--;
	}	
	//printing to see if this shit works
	t_stk_nd *curr_elemen = stack_pop(stack_a);
	while (curr_elemen != NULL)
	{
		printf("%s\n", (char *) curr_elemen->content);
		if (stack_a->top_node == NULL && stack_a->bottom_node == NULL)
			break;
		//printf("top_node = %s \n", (char *)	stack_a->top_node->content);
		//printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
		curr_elemen = stack_pop(stack_a);
	}
	// BUBBLE SORT LOGIC
	t_stack *stack_b = malloc(sizeof(t_stack));
	int	is_stka_sort = 0;
	int is_stkb_sort = 0;
	while (!is_stka_sort)
	{
		
	}
















}
