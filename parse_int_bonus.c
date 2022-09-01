/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <leofariasrj25@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 14:28:49 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 19:34:24 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

static int	check_signal(const char *str, int *i)
{
	int	signal;

	signal = 1;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			signal *= -1;
		*i = *i + 1;
	}
	return (signal);
}

long int	*clean_ret(long int *ret)
{
	free(ret);
	return (NULL);
}

long int	*parse_int(const char *str)
{
	long int	res;
	int			signal;
	int			i;
	long int	*ret;

	ret = NULL;
	res = 0;
	signal = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	signal = check_signal(str, &i);
	if (str[i] != '\0' || ft_isdigit(str[i]))
		ret = malloc(sizeof(long int));
	else
		return (NULL);
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0' || !ret)
		return (clean_ret(ret));
	*ret = res * signal;
	return (ret);
}
