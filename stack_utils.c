/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:59:57 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/21 12:15:45 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

t_stk_nd *stk_new_node(void *element)
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

t_stk *stk_create()
{
	t_stk	*stk;

	stk = malloc(sizeof(t_stk));
	if (!stk)
		return (NULL);
	stk->top_node = NULL;
	stk->bottom_node = NULL;
	stk->size = 0;
	return (stk);
}
