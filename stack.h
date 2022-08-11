/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:17:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/11 19:23:56 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack_node
{
	struct	s_stack_node	*previous;
	struct	s_stack_node	*next;
	void					*content;
} t_stk_nd;

typedef struct s_stack
{
	t_stk_nd	*top_node;
	t_stk_nd	*bottom_node;
} t_stack;

t_stk_nd	*create_stk_node(void *element);
void		stck_add(t_stk_nd *new_node, t_stack *stk);
void		*stck_pop(t_stack *stk);
void		clean_stack(t_stack *stk);
# endif
