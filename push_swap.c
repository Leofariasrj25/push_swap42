/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:04:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/11 16:03:57 by lfarias-         ###   ########.fr       */
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
	i = argc - 1;
	while (i)
	{
		t_stk_nd node = NULL;
		stck_add(&ft_atoi(argv[i]), stack_a), 					
		i--;
	}	
	//printing to see if this shit works
	t_node curr_elemen = stck_pop(stack_a);
	while (curr_elemen != NULL)
	{
		printf("%d ", curr_elemen->content);
		t_node curr_elemen = stck_pop(stack_a);
	}
}
