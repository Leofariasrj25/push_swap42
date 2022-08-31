NAME = push_swap
SRC	=	push_swap.c \
		push_swap_utils.c \
		input_parser.c \
		parse_int.c \
		sort_small.c \
		send_chunks_to.c \
		get_chunks_from.c \
		merge_sort.c \
	 	stack.c \
	 	stack_utils.c \
		stack_ops_a.c \
		stack_ops_b.c \
		print_op.c
LIBFT_DIR = ./libft/
CC = cc
CFLAGS = -Wall -Werror -Wextra
T_MAIN = test_main.c

$(NAME):
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -g -I. $(SRC) $(LIBFT_DIR)libft.a -o $(NAME)
	cp $(NAME) ./visualizer/
	./visualizer/visualizer

all: $(NAME)

clean:
	rm -f push_swap
	
re: clean $(NAME)

test:
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -I. stack.c stack_utils.c test_main.c $(LIBFT_DIR)libft.a -o test

tclean:
	rm -f ./test

tre: tclean test
