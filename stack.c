/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:03:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/17 15:32:16 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stk_nd *create_stk_node(void *element)
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
	//	what happens if stk is null?
	//NULL should be returned 
	//	what happens if new_node is null?
	//No operations on stack and return NULL
	//	what happens if stk is empty?
	//the new node should be the top node
	// what happens if the new node already points to a new element
	// that element should be the top of the stack
	t_stk_nd *c_node;

	c_node = NULL;
	if (!new_node || !stk)
		return ;
	if (!(stk->top_node) && !(stk->bottom_node))
	{
		stk->bottom_node = new_node;
		c_node = new_node;
		while (c_node->next)
			c_node = c_node->next;
		stk->top_node = c_node;
		return ;
	}
	stk->top_node->next = new_node;
	new_node->previous = stk->top_node;
	c_node = new_node;
	while (c_node->next)
		c_node = c_node->next;
	stk->top_node = c_node;
}

t_stk_nd	*stack_pop(t_stk *stk)
{
	// what happens if the stk is null?
	//	NULL should be returned 
	// what happens if the stk is empty?
	//	No operations should be done, NULL is returned
	// what happens if the poped element is the last element of the stk?
	//	the stk, top and bottom node should point to null
	// algo
	// access the stk top node
	// store the address value of the top node on an auxialiary var
	// update stack top_node to be the previous node.
	// update the new top_node next to be null
	// update the popped nod to point to NULL on previous and next attributes
	
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
		return (pop_node);
	}
	pop_node = stk->top_node;
	stk->top_node = pop_node->previous;
	stk->top_node->next = NULL;
	pop_node->previous = NULL;	
	//if (stack_len(stk) == 1)
		//stk->bottom_node = stk->top_node;
	return(pop_node);	
}

void	stk_swap(t_stk *stack)
{
	// don't let the stk do this if it's empty
	// or has only one element
	//
	// swp the top elements with its previous element
	// ERROR TREATMENT
	
	t_stk_nd *top_node;
	t_stk_nd *previous_node;
	
	top_node = stk_pop(stack);
	previous_node = stk_pop(stack);
	stk_add(top_node, stack);
	stk_add(previous_node, stack);
}


