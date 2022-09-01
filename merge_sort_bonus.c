/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:30:43 by lfarias-          #+#    #+#             */
/*   Updated: 2022/09/01 11:47:49 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void		merge_recursive(long int *val_list, int left, int right);
static void		merge(long int *val_list, int left, int middle, int right);
static long int	*sub_list(long int *val_list, int start, int end);
static long int	*flush_stk(long int *orgn, long int *dst, int *d_i, int o_end);

long int	*merge_sort(long int *val_list, int length)
{
	if (!val_list)
		return (NULL);
	if (length <= 1)
		return (val_list);
	merge_recursive(val_list, 0, length - 1);
	return (val_list);
}

static void	merge_recursive(long int *val_list, int left, int right)
{
	int	middle;

	middle = 0;
	if (left < right)
	{
		middle = left + (right - left) / 2;
		merge_recursive(val_list, left, middle);
		merge_recursive(val_list, middle + 1, right);
		merge(val_list, left, middle, right);
	}
}

static void	merge(long int *val_list, int left, int middle, int right)
{
	long int	*left_stack;
	long int	*right_stack;
	int			ltop;
	int			rtop;
	int			i;

	left_stack = sub_list(val_list, left, middle + 1);
	right_stack = sub_list(val_list, middle + 1, right);
	ltop = 0;
	rtop = 0;
	i = left;
	while (ltop < (middle - left + 1) && rtop < (right - middle))
	{
		if (left_stack[ltop] < right_stack[rtop])
			val_list[i++] = left_stack[ltop++];
		else
			val_list[i++] = right_stack[rtop++];
	}	
	flush_stk(&left_stack[ltop], val_list, &i, (middle - left + 1) - ltop);
	flush_stk(&right_stack[rtop], val_list, &i, (right - middle) - rtop);
	free(left_stack);
	free(right_stack);
}

long int	*sub_list(long int *val_list, int start, int end)
{
	long int	*sub_list;
	int			i;
	int			j;

	i = 0;
	j = start;
	sub_list = malloc(sizeof(long int) * (end - start + 1));
	while (i < (end - start + 1))
	{
		sub_list[i] = val_list[j];
		i++;
		j++;
	}
	return (sub_list);
}

long int	*flush_stk(long int *orgn, long int *dst, int *d_i, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dst[*d_i] = *orgn;
		orgn++;
		*d_i = *d_i + 1;
		i++;
	}
	return (dst);
}

/*
#include <stdio.h>
void	print_vals(int *vals, int size)
{
	int i;

	printf("> ");
	i = 0;
	while (i < size)
		printf("%d ", vals[i++]);
	printf("\n");
}

int main(void)
{
	int vals[] = {3, 9, 2, 7, 4, 8, 1, 0, 6, 5};
	print_vals(vals, 10);
	mergesort(vals, 10);
	print_vals(vals, 10);

	int same_vals[] = {7, 7, 7, 4, 4, 4, 4, 1, 1, 1, 1, 8, 8, 3, 3, 0, 9};
	int size = sizeof(same_vals) / sizeof(int);
	print_vals(same_vals, size);
	mergesort(same_vals, size);
	print_vals(same_vals, size);

	int in_order[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int in_order_size = sizeof(in_order) / sizeof(int);
	print_vals(in_order, in_order_size);
	mergesort(in_order, in_order_size);
	print_vals(in_order, in_order_size);
}*/
