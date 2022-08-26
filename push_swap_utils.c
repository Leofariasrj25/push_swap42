/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 10:04:11 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/26 10:07:34 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

int	get_const(int stack_size)
{
	int	n;

	if (stack_size <= 10)
		n = 5;
	else if (stack_size <= 150)
		n = 8;
	else if (stack_size > 150)
		n = 18;
	return (n);
}
