/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:59:57 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 15:28:27 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stk_nd	*stk_new_node(int value)
{
	t_stk_nd	*new_node;

	new_node = malloc(sizeof(t_stk_nd));
	if (!new_node)
		return (NULL);
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->value = value;
	return (new_node);
}

t_stk	*stk_create(void)
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

t_stk	*stk_create_from(long int *values, int size)
{
	int			i;
	t_stk		*stk;
	t_stk_nd	*node;

	i = size;
	stk = stk_create();
	if (!stk)
		return (NULL);
	while (i--)
	{
		node = stk_new_node(values[i]);
		stk_add(node, stk);
	}
	return (stk);
}

void	stk_clean(t_stk *stk)
{
	t_stk_nd	*node;
	t_stk_nd	*aux;

	node = stk->top_node;
	while (node)
	{
		aux = node;
		node = node->previous;
		free(aux);
	}
	free(stk);
}
