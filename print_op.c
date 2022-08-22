/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:24:24 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/21 18:27:52 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>

void	print_op(const int OP)
{
	if (OP == STACK_SA)
		printf("sa");
	else if (OP == STACK_SB)
		printf("sb");
	else if (OP == STACK_SS)
		printf("ss");
	else if (OP == STACK_PA)
		printf("pa");
	else if (OP == STACK_PB)
		printf("pb");
	else if (OP == STACK_RA)
		printf("ra");
	else if (OP == STACK_RB)
		printf("rb");
	else if (OP == STACK_RR)
		printf("rr");
	else if (OP == STACK_RRA)
		printf("rra");
	else if (OP == STACK_RRB)
		printf("rrb");
	else if (OP == STACK_RRR)
		printf("rrr");
	printf("\n");
}
