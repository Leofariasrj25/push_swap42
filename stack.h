/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:17:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/29 20:20:26 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# include <stdlib.h>

typedef struct s_stack_node
{
	struct s_stack_node	*previous;
	struct s_stack_node	*next;
	int					value;
}	t_stk_nd;

typedef struct s_stack
{
	t_stk_nd			*top_node;
	t_stk_nd			*bottom_node;
	unsigned int		size;
}	t_stk;

t_stk		*stk_create(void);
t_stk		*stk_create_from(long int *vals, int size);
t_stk_nd	*stk_new_node(int value);
void		stk_add(t_stk_nd *new_node, t_stk *stk);
t_stk_nd	*stk_pop(t_stk *stk);
void		stk_swap(t_stk *stk);
void		stk_rot_up(t_stk *stk);
void		stk_rot_down(t_stk *stk);
void		stk_clean(t_stk *stk);
#endif
