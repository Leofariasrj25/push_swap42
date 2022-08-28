/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:25:33 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 00:15:48 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack.h"

int	*mergesort(int *list_val, int size);

// push_swap utils
int	get_const(int stack_size);
int	is_on_stack(t_stk *stk, int value);
void	set_values(int *start, int *end, int *middle, int stk_size);
void	update_range(int *start, int *end, int stk_size);
#endif
