/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:09:47 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/04 00:20:23 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include <stdio.h>

static void		sort(t_stk *stk_a, t_stk *stk_b);
static int		is_valid_op(char *op_str);
static int		check_is_sort(t_stk *stk_a, t_stk *stk_b, int n_size);
static void		destroy(t_stk *stk_a, t_stk *stk_b);

int	main(int argc, char **argv)
{
	long int	*values;
	int			n_size;
	t_stk		*stk_a;
	t_stk		*stk_b;

	if (argc - 1 == 0)
		return (0);
	n_size = 0;
	values = parse_input(&argv[1], argc - 1, &n_size);
	if (!values || check_dups(values, n_size))
	{
		if (values)
			free(values);
		ft_putendl_fd("Error", 2);
		exit(127);
	}
	stk_a = stk_create_from(values, n_size);
	stk_b = stk_create();
	free(values);
	sort(stk_a, stk_b);
	if (check_is_sort(stk_a, stk_b, n_size))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	destroy(stk_a, stk_b);
}

static int	is_valid_op(char *op_str)
{
	int			i;
	int			input_len;
	static char	*ops[] = {"pa", "pb", "sa", "sb", "ss", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};

	input_len = ft_strlen(op_str) - 1;
	if (input_len < 2)
		return (0);
	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(ops[i], op_str, input_len) == 0)
			return (1);
		i++;
	}
	return (0);
}

static void	sort(t_stk *stk_a, t_stk *stk_b)
{
	char	*op_str;
	int		fd;

	fd = 0;
	op_str = get_next_line(fd);
	if (!op_str)
		fd = 1;
	while (1)
	{
		if (!op_str)
			return ;
		if (is_valid_op(op_str))
		{
			exec_op(op_str, stk_a, stk_b);
			free(op_str);
		}
		else
		{
			free(op_str);
			destroy(stk_a, stk_b);
			ft_putendl_fd("Error", 2);
			exit(127);
		}
		op_str = get_next_line(fd);
	}
}

static int	check_is_sort(t_stk *stk_a, t_stk *stk_b, int n_size)
{
	t_stk_nd	*node;

	if (stk_b->size != 0 || stk_a->size == 0)
		return (0);
	if ((int) stk_a->size != n_size)
		return (0);
	node = stk_a->bottom_node;
	while (node->next)
	{
		if (node->value > node->next->value)
			node = node->next;
		else
			return (0);
	}
	return (1);
}

static void	destroy(t_stk *stk_a, t_stk *stk_b)
{
	stk_clean(stk_a);
	stk_clean(stk_b);
}
