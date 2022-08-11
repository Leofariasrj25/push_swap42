/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:31:34 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/11 16:56:32 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

/*void	stck_add_test(t_stack node)
{

}*/
	
void	create_stk_node_test()
{
	// test 1
	// create_stk_node should return false
	// for a NULL element
	printf(">>> create_stk_node_test \n");
	printf(">NULL arg:\n");
	void *element = NULL;
	t_stk_nd *new_node = create_stk_node(element);
	if (!new_node)
		printf("OK - expected: 0x0 - result: %p \n", new_node);
	else
		printf("KO - null arg should return null");
	
	// test 1
	printf("\n>new node next_node and previous_nodes fields should be empty\n");
	char *baby = "don't hurt me!";
	new_node = create_stk_node(baby);
	printf("next_node - expected: 0x0 - got: %p\n", new_node->next);
	printf("previous_node - expected: 0x0 - got: %p\n", new_node->previous);
	free(new_node);

	// test 2
	printf("\n>check if node points to the right content of address\n");
	char *chocolate = ft_strdup("dakedo chokoreto chokoreto");
	new_node = create_stk_node(chocolate);
	printf("string: %p: %s\n", chocolate, chocolate);
	printf("node's content: %p: %s\n", new_node->content, new_node->content);
	free(chocolate);
}

int	main(void)
{
	printf("=== UNIT TESTS ===\n");
	create_stk_node_test();
}
