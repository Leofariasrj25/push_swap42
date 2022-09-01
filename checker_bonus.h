/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:41:00 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/01 11:49:45 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "stack_bonus.h"
# include <stdlib.h>

long int	*parse_input(char **input, int input_size, int *n_size);
long int	*parse_int(const char *str);
long int	*merge_sort(long int *val_list, int length);
int			check_dups(long int *values, int n_size);
void		exec_op(char *op_str, t_stk *stk_a, t_stk *stk_b);
#endif
