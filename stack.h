/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:17:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/21 18:35:12 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H
# define	STACK_SA 0
# define	STACK_SB 1
# define	STACK_SS 2
# define	STACK_PA 3
# define	STACK_PB 4
# define	STACK_RA 5
# define	STACK_RB 6
# define	STACK_RR 7
# define	STACK_RRA 8
# define	STACK_RRB 9
# define	STACK_RRR 10
# define	STACK_A 65
# define	STACK_B 66

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

void		print_op(const int OP);
t_stk		*stk_create();
t_stk_nd	*stk_new_node(void *element);
void		stk_add(t_stk_nd *new_node, t_stk *stk);
t_stk_nd	*stk_pop(t_stk *stk);
void		stk_swap(t_stk *stk);
void		stk_clean(t_stk *stk);
void		stk_rot_up(t_stk *stk);
void		stk_rot_down(t_stk *stk);
# endif
