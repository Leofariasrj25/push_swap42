NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
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
BONUS_SRC = checker.c
LIBFT_DIR = ./libft/
GNL_DIR = ./get_next_line/
$(NAME):
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -g -I. $(SRC) $(LIBFT_DIR)libft.a -o $(NAME)
	cp $(NAME) ./visualizer/
	./visualizer/visualizer

all: $(NAME)

clean:
	rm -f push_swap
	
re: clean $(NAME)

bonus:
		make -C $(LIBFT_DIR) libft.a
		$(CC) $(CFLAGS) -g -I. $(BONUS_SRC) $(LIBFT_DIR)libft.a -o $(NAME)
