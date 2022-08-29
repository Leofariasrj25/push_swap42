/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:25:33 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 18:16:41 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack.h"

int		*mergesort(int *list_val, int size);

void	sort_three(t_stk *stk_a);
void	sort_five(t_stk *stk_a, t_stk *stk_b);
void	send_chunks_to(t_stk *stk_b, t_stk *stk_a, int *sorted, int stk_size);
void	get_chunks_from(t_stk *stk_b, t_stk *stk_a, int *sorted, int stk_size);

// send_chunks_to utils
int		get_const(int stack_size);
void	set_chunk_rng(int *start, int *end, int stk_size);
void	update_chunk_rng(int *start, int *end, int stk_size);
#endif
