/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:03:26 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/11 16:26:41 by lfarias-         ###   ########.fr       */
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

void	stck_add(t_stk_nd *new_node, t_stack *stk)
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


