/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:25:33 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/30 23:55:00 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "stack.h"

long int	*mergesort(long int *list_val, int size);
long int	*parse_int(const char *str);
void		sort_three(t_stk *stk_a);
void		sort_five(t_stk *stk_a, t_stk *stk_b);
void		send_chunks(t_stk *stk_b, t_stk *stk_a, long int *vals, int size);
void		get_chunks(t_stk *stk_b, t_stk *stk_a, long int *vals, int size);

// input handling
long int	*parse_input(char **argv, int input_size, int *n_size);
int			check_no_dups(long int *values, int size);
int			check_is_sort(long int *vals, int size);
long int	*dup_val_lst(long int *values, int size);

// send_chunks_to utils
int			get_const(int stack_size);
void		set_chunk_rng(int *start, int *end, int stk_size);
void		update_chunk_rng(int *start, int *end, int stk_size);
#endif
