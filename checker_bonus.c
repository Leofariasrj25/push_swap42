/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:09:47 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/31 14:46:36 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int argc, char **argv)
{
	// what happens if the checker is invoked without arguments
	// nothing should be displayend on the screen even if its receives cmds
	// via pipe
	if (argc - 1 == 0)
		return (0);
}
