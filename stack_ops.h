/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:24:29 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/27 21:27:38 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_OPS_H
# define STACK_OPS_H

# include "stack.h"

# define STACK_SA 1
# define STACK_SB 2
# define STACK_SS 3
# define STACK_PA 4
# define STACK_PB 5
# define STACK_RA 6
# define STACK_RB 7
# define STACK_RR 8
# define STACK_RRA 9
# define STACK_RRB 10
# define STACK_RRR 11
# define FLUSH_OP 12

void	print_op(const int OP);
void	push_to_a(t_stk *stk_b, t_stk *stk_a);
void	push_to_b(t_stk *stk_a, t_stk *stk_b);
void	swap_a(t_stk *stk_a);
void	swap_b(t_stk *stk_b);
void	rot_up_a(t_stk *stk_a);
void	rot_up_b(t_stk *stk_b);
void	rot_down_a(t_stk *stk_a);
void	rot_down_b(t_stk *stk_b);
#endif
