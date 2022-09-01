/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ops_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:48:02 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 22:08:44 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	push(char *op_str, t_stk *stk_a, t_stk *stk_b);
static int	swap(char *op_str, t_stk *stk_a, t_stk *stk_b);
static int	rot_up(char *op_str, t_stk *stk_a, t_stk *stk_b);
static int	rot_down(char *op_str, t_stk *stk_a, t_stk *stk_b);

void	exec_op(char *op_str, t_stk *stk_a, t_stk *stk_b)
{
	if (push(op_str, stk_a, stk_b))
		return ;
	if (swap(op_str, stk_a, stk_b))
		return ;
	if (rot_down(op_str, stk_a, stk_b))
		return ;
	if (rot_up(op_str, stk_a, stk_b))
		return ;
}

static int	push(char *op_str, t_stk *stk_a, t_stk *stk_b)
{
	if (ft_strncmp(op_str, "pa", 2) == 0)
	{
		stk_add(stk_pop(stk_b), stk_a);
		return (1);
	}
	else if (ft_strncmp(op_str, "pb", 2) == 0)
	{
		stk_add(stk_pop(stk_a), stk_b);
		return (1);
	}
	return (0);
}

int	swap(char *op_str, t_stk *stk_a, t_stk *stk_b)
{	
	if (ft_strncmp(op_str, "sa", 2) == 0)
	{
		stk_swap(stk_a);
		return (1);
	}
	else if (ft_strncmp(op_str, "sb", 2) == 0)
	{
		stk_swap(stk_b);
		return (1);
	}
	else if (ft_strncmp(op_str, "ss", 2) == 0)
	{
		stk_swap(stk_a);
		stk_swap(stk_b);
		return (1);
	}
	return (0);
}

static int	rot_up(char *op_str, t_stk *stk_a, t_stk *stk_b)
{
	if (ft_strlen(op_str) != 3)
		return (0);
	if (ft_strncmp(op_str, "ra", 2) == 0)
	{
		stk_rot_up(stk_a);
		return (1);
	}
	else if (ft_strncmp(op_str, "rb", 2) == 0)
	{
		stk_rot_up(stk_b);
		return (1);
	}
	else if (ft_strncmp(op_str, "rr", 2) == 0)
	{
		stk_rot_up(stk_a);
		stk_rot_up(stk_b);
		return (1);
	}
	return (0);
}

static int	rot_down(char *op_str, t_stk *stk_a, t_stk *stk_b)
{
	if (ft_strlen(op_str) != 4)
		return (0);
	if (ft_strncmp(op_str, "rra", 3) == 0)
	{
		stk_rot_down(stk_a);
		return (1);
	}
	else if (ft_strncmp(op_str, "rrb", 3) == 0)
	{
		stk_rot_down(stk_b);
		return (1);
	}
	else if (ft_strncmp(op_str, "rrr", 3) == 0)
	{
		stk_rot_down(stk_a);
		stk_rot_down(stk_b);
		return (1);
	}
	return (0);
}
