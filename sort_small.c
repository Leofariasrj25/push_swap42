/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 17:43:16 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/28 18:00:48 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack_ops.h"

void sort_three(t_stk *stk_a)
{
	int	num_a;
	int	num_b;
	int	num_c;

	num_a = stk_a->top_node->value;
	num_b = stk_a->top_node->previous->value;
	num_c = stk_a->bottom_node->value;
	if (num_a > num_b && num_a < num_c)
		swap_a(stk_a);
	else if (num_a > num_b && num_b > num_c)
	{
		swap_a(stk_a);
		rot_down_a(stk_a);
	}
	else if (num_a > num_b && num_b < num_c)
		rot_up_a(stk_a);
	else if (num_a < num_b && num_b > num_c)
	{
		swap_a(stk_a);	
		rot_up_a(stk_a);
	}
	else if (num_a < num_b && num_b > num_c);
		rot_down_a(stk_a);
}
