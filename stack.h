/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:17:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/20 15:51:41 by lfarias-         ###   ########.fr       */
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
	t_stk_nd			*top_node;
	t_stk_nd			*bottom_node;
	unsigned int		size;
} t_stk;

t_stk_nd	*stk_create_node(void *element);
void		stk_add(t_stk_nd *new_node, t_stk *stk);
t_stk_nd	*stk_pop(t_stk *stk);
void		stk_swap(t_stk *stk);
void		stk_clean(t_stk *stk);
void		stk_rot_up(t_stk *stk);
void		stk_rot_down(t_stk *stk);
# endif
