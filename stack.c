/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:03:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/20 22:49:49 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stk_nd *stk_create_node(void *element)
{
	t_stk_nd	*new_node;

	if (!element)
		return (NULL);
	new_node = malloc(sizeof(t_stk_nd));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->content = element;
	return (new_node);
}

void	stk_add(t_stk_nd *new_node, t_stk *stk)
{
	t_stk_nd *c_node;

	c_node = NULL;
	if (!new_node || !stk)
		return ;
	if (!(stk->top_node) && !(stk->bottom_node))
	{
		stk->bottom_node = new_node;
		c_node = new_node;
		while (c_node->next)
		{
			c_node = c_node->next;
			stk->size = stk->size + 1;
		}
		stk->size = stk->size + 1;
		stk->top_node = c_node;
		return ;
	}
	stk->top_node->next = new_node;
	new_node->previous = stk->top_node;
	c_node = new_node;
	while (c_node->next)
	{
		c_node = c_node->next;
		stk->size = stk->size + 1;
	}
	stk->size = stk->size + 1;
	stk->top_node = c_node;
}

t_stk_nd	*stk_pop(t_stk *stk)
{
	t_stk_nd *pop_node;

	if (!stk)
		return (NULL);
	if (!(stk->top_node) && !(stk->bottom_node))
		return (NULL);
	if (stk->top_node == stk->bottom_node)
	{
		pop_node = stk->top_node;
		stk->top_node = NULL;
		stk->bottom_node = NULL;
		stk->size = stk->size - 1;
		return (pop_node);
	}
	pop_node = stk->top_node;
	stk->top_node = pop_node->previous;
	stk->top_node->next = NULL;
	pop_node->previous = NULL;	
	stk->size = stk->size - 1;
	return(pop_node);	
}

// sa, sb
void	stk_swap(t_stk *stack)
{
	t_stk_nd *top_node;
	t_stk_nd *previous_node;
	
	if (stack->top_node == stack->bottom_node)
		return ;
	top_node = stk_pop(stack);
	previous_node = stk_pop(stack);
	stk_add(top_node, stack);
	stk_add(previous_node, stack);
}

/*static t_stk_nd	*stk_pop_bottom(t_stk *stack)
{
	
	t_stk_nd	*bottom_node;
	t_stk_nd	*second_to_bottom;

	if (!stack || (stack->top_node == NULL && stack->bottom_node == NULL))
		return (NULL);
	if (stack->size == 1)
		return (stk_pop(stack));
	bottom_node = stack->bottom_node;
	stack->bottom_node = bottom_node->next;
	stack->bottom_node->previous = NULL;
	bottom_node->next = NULL;
	bottom_node->previous = NULL;
	return (bottom_node);	
}*/

// ra, rb
void 	stk_rot_up(t_stk *stack)
{
	t_stk_nd	*popped_node;

	if (!stack || stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		stk_swap(stack);
		return ;
	}
	popped_node = stk_pop(stack);	
	stack->bottom_node->previous = popped_node;
	popped_node->next = stack->bottom_node;
	popped_node->previous = NULL;
	stack->bottom_node = popped_node;
	stack->size = stack->size + 1;
}

// rra, rrb
void	stk_rot_down(t_stk *stack)
{
	t_stk_nd	*bottom_node;

	if (!stack || stack->size <= 1)
		return ;
	if (stack->size == 2)
	{
		stk_swap(stack);
		return ;
	}
	bottom_node = stack->bottom_node;
	stack->bottom_node = stack->bottom_node->next;
	stack->bottom_node->previous = NULL;
	bottom_node->next = NULL;
	bottom_node->previous = NULL;
	stack->size = stack->size - 1;
	stk_add(bottom_node, stack);
}
