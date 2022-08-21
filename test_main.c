/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 15:31:34 by lfarias-          #+#    #+#             */
/*   Updated: 2022/08/21 12:11:06 by lfarias-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void	print_stack(t_stk *test_stack)
{
	t_stk_nd *c_node = test_stack->top_node;
	while (c_node)
	{
		printf("[%p]: %s\n", c_node, (char *) c_node->content);
		c_node = c_node->previous;
	}
	printf("stack size is: %d\n", test_stack->size);
}

void	stk_add_test()
{
	t_stk_nd	*c_node;
	t_stk		*test_stk;
	t_stk		*test_stk_2;

	printf("\n>>> stk_add_test\n");
	printf("\n> Basic Functionality \n");
	// test 1
	// verificar se os dados estão empilhados da maneira correta
	test_stk = malloc(sizeof(t_stk));
	test_stk->top_node = NULL;
	test_stk->bottom_node = NULL;
	t_stk_nd *node = stk_new_node(ft_strdup("Item 1"));
	stk_add(node, test_stk);
	node = stk_new_node(ft_strdup("Item 2"));
	stk_add(node, test_stk);
	node = stk_new_node(ft_strdup("Item 3"));
	stk_add(node, test_stk);
	c_node = test_stk->bottom_node;
	printf("> from bottom to top:\n");
	while (c_node)
	{
		printf("[%p]: %s\n", c_node, (char *) c_node->content);
		c_node = c_node->next;
	}
	printf("> from top to bottom:\n");
	c_node = test_stk->top_node;
	while (c_node)
	{
		printf("[%p]: %s\n", c_node, (char *) c_node->content);
		c_node = c_node->previous;
	}
	
	printf("\n > Add NULL node on populated stack\n");
	stk_add(NULL, test_stk);
	printf("expected: Item 3\n");
	printf("got: %s\n", (char *) test_stk->top_node->content);
	
	printf("\n > Add NULL node on empty stack\n");
	test_stk_2 = malloc(sizeof(t_stk));
	test_stk_2->top_node = NULL;
	test_stk_2->bottom_node = NULL;
	stk_add(NULL, test_stk_2);
	printf("top node: expected: 0x0 - got: %p\n", test_stk_2->top_node);
	printf("bottom node: expected: 0x0 - got: %p\n", test_stk_2->bottom_node);

	printf("\n > Add a valid NODE on a NULL stack\n");
	printf("Non guarded code should provoke seg-fault\n");
	c_node = stk_new_node(ft_strdup("Search and Destroy\n"));
	stk_add(c_node, NULL);
	c_node = stk_new_node(ft_strdup("Master of Puppets\n"));
	stk_add(c_node, NULL);
	printf("If it reached here then everything is ok!\n");

	printf("\n > Add another stack on top of an existing stack \n");

}
	
void	stk_new_node_test()
{
	// test 1
	// stk_new_node should return false
	// for a NULL element
	printf(">>> stk_new_node_test \n");
	printf(">NULL arg:\n");
	void *element = NULL;
	t_stk_nd *new_node = stk_new_node(element);
	if (!new_node)
		printf("OK - expected: 0x0 - result: %p \n", new_node);
	else
		printf("KO - null arg should return null");
	
	// test 1
	printf("\n>new node next_node and previous_nodes fields should be empty\n");
	char *baby = "don't hurt me!";
	new_node = stk_new_node(baby);
	printf("next_node - expected: 0x0 - got: %p\n", new_node->next);
	printf("previous_node - expected: 0x0 - got: %p\n", new_node->previous);
	free(new_node);

	// test 2
	printf("\n>check if node points to the right content of address\n");
	char *chocolate = ft_strdup("dakedo chokoreto chokoreto");
	new_node = stk_new_node(chocolate);
	printf("string: %p: %s\n", chocolate, chocolate);
	printf("node's content: %p: %s\n", new_node->content, (char *) new_node->content);
	free(chocolate);
}

void	stk_rot_up_test()
{
	// test 1 - NULL stack
	// expect: no seg fault
	printf("\n>>> stk_rot_up_test <<<\n");
	printf("\n---NULL test---\n");
	stk_rot_up(NULL);
	printf("expect: if this prints == null protected\n");

	// test 2 - empty stack
	// expect: no seg fault
	printf("\n---Empty stack test---\n");
	t_stk *test_stack = malloc(sizeof(t_stk));
	test_stack->top_node = NULL;
	test_stack->bottom_node = NULL;
	test_stack->size = 0;
	stk_rot_up(test_stack);
	printf("expect: if this prints == OK\n");
	 
	// test 3
	printf("\n---Rotate up with 1 (one) element---\n");
	t_stk_nd *node = stk_new_node(ft_strdup("Item 1"));
	stk_add(node, test_stack);
	printf("Before rotate up\n");
	print_stack(test_stack);
	printf("vvv\n");
	printf("After rotate up\n");
	stk_rot_up(test_stack);
	print_stack(test_stack);
	
	// test 4
	printf("\n---Rotate up with 2 (two) elements---\n");
	printf("Adding 'Item 2' to stack\n");
	node = stk_new_node(ft_strdup("Item 2"));
	stk_add(node, test_stack);
	printf("Before rotate up\n");
	print_stack(test_stack);
	printf("vvv\n");
	printf("After rotate up\n");
	stk_rot_up(test_stack);
	print_stack(test_stack);

	printf("\n---Rotate up with 6 elements ---\n");
	stk_swap(test_stack);
	printf("Adding 'Item 3' to stack\n");
	node = stk_new_node(ft_strdup("Item 3"));
	stk_add(node, test_stack);

	printf("Adding 'Item 4' to stack\n");
	node = stk_new_node(ft_strdup("Item 4"));
	stk_add(node, test_stack);

	printf("Adding 'Item 5' to stack\n");
	node = stk_new_node(ft_strdup("Item 5"));
	stk_add(node, test_stack);

	printf("Adding 'Item 6' to stack\n");
	node = stk_new_node(ft_strdup("Item 6"));
	stk_add(node, test_stack);

	printf("Before rotate up\n");
	print_stack(test_stack);
	printf("stack size is: %d\n", test_stack->size);
	printf("vvv\n");
	printf("After rotate up\n");
	stk_rot_up(test_stack);
	print_stack(test_stack);
	printf("stack size is: %d\n", test_stack->size);

	printf("Sanity check\n");
	printf("stack->top_node->next %p\n", test_stack->top_node->next);
	printf("stack->bottom_node->previous %p\n", test_stack->bottom_node->previous);
}

void	stk_rot_down_test()
{
	// test 1 - NULL stack
	// expect: no seg fault
	printf("\n>>> stk_rot_down_test <<<\n");
	printf("\n---NULL test---\n");
	stk_rot_up(NULL);
	printf("expect: if this prints == null protected\n");

	// test 2 - empty stack
	// expect: no seg fault
	printf("\n---Empty stack test---\n");
	t_stk *test_stack = malloc(sizeof(t_stk));
	test_stack->top_node = NULL;
	test_stack->bottom_node = NULL;
	test_stack->size = 0;
	stk_rot_down(test_stack);
	printf("expect: if this prints == OK\n");
	 
	// test 3
	printf("\n---Rotate down with 1 (one) element---\n");
	t_stk_nd *node = stk_new_node(ft_strdup("Item 1"));
	stk_add(node, test_stack);
	printf("Before rotate down\n");
	print_stack(test_stack);
	printf("stack size is: %d\n", test_stack->size);
	printf("vvv\n");
	printf("After rotate down\n");
	stk_rot_down(test_stack);
	print_stack(test_stack);
	printf("stack size is: %d\n", test_stack->size);
	
	// test 4
	printf("\n---Rotate down with 2 (two) elements---\n");
	printf("Adding 'Item 2' to stack\n");
	node = stk_new_node(ft_strdup("Item 2"));
	stk_add(node, test_stack);
	printf("Before rotate down\n");
	print_stack(test_stack);
	printf("stack size is: %d\n", test_stack->size);
	printf("vvv\n");
	printf("After rotate down\n");
	stk_rot_down(test_stack);
	print_stack(test_stack);
	printf("stack size is: %d\n", test_stack->size);

	printf("\n---Rotate down with 6 elements ---\n");
	stk_swap(test_stack);
	printf("Adding 'Item 3' to stack\n");
	node = stk_new_node(ft_strdup("Item 3"));
	stk_add(node, test_stack);

	printf("Adding 'Item 4' to stack\n");
	node = stk_new_node(ft_strdup("Item 4"));
	stk_add(node, test_stack);

	printf("Adding 'Item 5' to stack\n");
	node = stk_new_node(ft_strdup("Item 5"));
	stk_add(node, test_stack);

	printf("Adding 'Item 6' to stack\n");
	node = stk_new_node(ft_strdup("Item 6"));
	stk_add(node, test_stack);

	printf("Before rotate down\n");
	print_stack(test_stack);
	printf("vvv\n");
	printf("After rotate down\n");
	stk_rot_down(test_stack);
	print_stack(test_stack);

	printf("stack->top_node->next %p\n", test_stack->top_node->next);
	printf("stack->bottom_node->previous %p\n", test_stack->bottom_node->previous);
}

void	stk_pop_test()
{
	printf("\n --- STK_POP TEST --- \n");

	printf("\n --- stk_pop null stack\n");
	stk_pop(NULL);
	printf("If this runs == stk_pop is null protected\n");

	printf("\n --- stk_pop empty stack\n");
	t_stk *test_stack = malloc(sizeof(t_stk));
	test_stack->top_node = NULL;
	test_stack->bottom_node = NULL;
	test_stack->size = 0;
	stk_pop(test_stack);
	t_stk_nd *node = stk_new_node(ft_strdup("Item 1"));
	stk_add(node, test_stack);
	printf("-before stk_pop\n");
	print_stack(test_stack);	
	node = stk_pop(test_stack);	
	printf("-after stk_pop\n");
	print_stack(test_stack);
}

int	main(void)
{
	printf("=== UNIT TESTS ===\n");
	stk_new_node_test();
	stk_add_test();
	stk_pop_test();
	stk_rot_up_test();	
	stk_rot_down_test();
}
