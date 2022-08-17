/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/17 16:57:41 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "bubblesort.h"
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

	t_stk *stack_a = malloc(sizeof(t_stk));
	stack_a->top_node = NULL;
	stack_a->bottom_node = NULL;
	i = argc - 1;
	while (i)
	{
		t_stk_nd *node = NULL;
		int *n = malloc(sizeof(int));
		*n = ft_atoi(argv[i]);
		node = stk_create_node(n);
		stk_add(node, stack_a);
		//printf("top_node = %s \n", (char *)	stack_a->top_node->content);
		//printf("bottom_node = %s \n", (char *) stack_a->bottom_node->content);
		i--;
	}	
	bubble_sort(stack_a);
}
