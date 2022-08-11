/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:31:34 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/11 19:35:08 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void	stck_add_test()
{
	t_stk_nd	*c_node;
	t_stack		*test_stack;
	t_stack		*test_stack_2;

	printf("\n>>> stck_add_test\n");
	printf("\n> Basic Functionality \n");
	// test 1
	// verificar se os dados estão empilhados da maneira correta
	test_stack = malloc(sizeof(t_stack));
	test_stack->top_node = NULL;
	test_stack->bottom_node = NULL;
	t_stk_nd *node = create_stk_node(ft_strdup("Item 1"));
	stck_add(node, test_stack);
	node = create_stk_node(ft_strdup("Item 2"));
	stck_add(node, test_stack);
	node = create_stk_node(ft_strdup("Item 3"));
	stck_add(node, test_stack);
	c_node = test_stack->bottom_node;
	printf("> from bottom to top:\n");
	while (c_node)
	{
		printf("[%p]: %s\n", c_node, c_node->content);
		c_node = c_node->next;
	}
	printf("> from top to bottom:\n");
	c_node = test_stack->top_node;
	while (c_node)
	{
		printf("[%p]: %s\n", c_node, c_node->content);
		c_node = c_node->previous;
	}
	
	printf("\n > Add NULL node on populated stack\n");
	stck_add(NULL, test_stack);
	printf("expected: Item 3\n");
	printf("got: %s\n", test_stack->top_node->content);
	
	printf("\n > Add NULL node on empty stack\n");
	test_stack_2 = malloc(sizeof(t_stack));
	test_stack_2->top_node = NULL;
	test_stack_2->bottom_node = NULL;
	stck_add(NULL, test_stack_2);
	printf("top node: expected: 0x0 - got: %p\n", test_stack_2->top_node);
	printf("bottom node: expected: 0x0 - got: %p\n", test_stack_2->bottom_node);

	printf("\n > Add a valid NODE on a NULL stack\n");
	printf("Non guarded code should provoke seg-fault\n");
	c_node = create_stk_node(ft_strdup("Search and Destroy\n"));
	stck_add(c_node, NULL);
	c_node = create_stk_node(ft_strdup("Master of Puppets\n"));
	stck_add(c_node, NULL);
	printf("If it reached here then everything is ok!\n");

	printf("\n > Add another stack on top of an existing stack \n");

}
	
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
	stck_add_test();
}
