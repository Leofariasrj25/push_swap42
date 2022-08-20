/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubblesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:38:22 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/19 15:40:19 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void	push_all(t_stk *stack_b, t_stk *stack_a)
{
	t_stk_nd	*node;

	if (stack_b->top_node == NULL && stack_b->bottom_node == NULL)
		return ;
	node = stk_pop(stack_b);
	while (node)
	{
		printf("pa\n");
		stk_add(node, stack_a);
		node = stk_pop(stack_b);
	}
}

void check_and_swap(t_stk *stack)
{
	int num_a;
	int num_b;

	if (stack->top_node == stack->bottom_node)
		return ;
	num_a = *((int *) stack->top_node->content);
	num_b = *((int *) stack->top_node->previous->content);

	if (num_a < num_b)
	{
		printf("sb\n");
		stk_swap(stack);
	}
}

int		check_ordering(t_stk *stack)
{
	t_stk_nd	*node;
	int			num_a;
	int			num_b;

	if (stack->top_node == stack->bottom_node)
		return (1);
	node = stack->top_node;
	while (node->previous)
	{
		num_a = *((int *) node->content);
		num_b = *((int *) node->previous->content);
		if (num_a > num_b)
			return (0);
		node = node->previous;
	}
	return (1);
}

void	bubble_sort(t_stk *stack_a)
{
	t_stk *stack_b;
	int		is_stack_a_sort;
	int		num_a;
	int		num_b;

	is_stack_a_sort = 0;
	stack_b = malloc(sizeof(t_stk));
	while(!is_stack_a_sort)
	{
		if (stack_a->top_node == NULL && stack_a->bottom_node == NULL)
			break ;
		if (stack_a->top_node == stack_a->bottom_node)
		{
			push_all(stack_b, stack_a);
			if (check_ordering(stack_a))
				return ;
		}
		num_a = *((int *) stack_a->top_node->content);
		num_b = *((int *) stack_a->top_node->previous->content);
		if (num_a < num_b && !is_stack_a_sort)
		{
			printf("pb\n");
			stk_add(stk_pop(stack_a), stack_b);
			is_stack_a_sort = 0;
			check_and_swap(stack_b);
		}
		else if (stack_a->top_node != stack_a->bottom_node && !is_stack_a_sort)
		{
			printf("sa\n");
			stk_swap(stack_a);
			is_stack_a_sort = 0;
		}
		if (check_ordering(stack_a)
			&& (stack_b->top_node == NULL && stack_b->bottom_node == NULL))
		{
			is_stack_a_sort = 1;
		}
		else
			is_stack_a_sort = 0;
	}
}
