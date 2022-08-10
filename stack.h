/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 19:17:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/09 21:43:43 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_stack_node
{
	struct s_stack_node	previous;
	struct s_stack_node	next;
	void				*content;
} t_stk_nd;

typedef struct s_stack
{
	struct s_stack_node first_node;
	struct s_stack_node last_node;
} t_stack;

void	stck_add(void *element, t_stack stack);
void	*stck_pop(t_stack_stack);
void	clean_stack(t_stack stack);
# endif
