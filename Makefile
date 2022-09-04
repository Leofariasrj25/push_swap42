NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC	=	push_swap.c \
		push_swap_utils.c \
		input_parser.c \
		parse_int.c \
		sort_small.c \
		send_chunks_to.c \
		send_chunks_utils.c \
		get_chunks_from.c \
		merge_sort.c \
	 	stack.c \
	 	stack_utils.c \
		stack_ops_a.c \
		stack_ops_b.c \
		print_op.c

BONUS_SRC = checker_bonus.c \
			stack_bonus.c \
			stack_utils_bonus.c \
			input_parser_bonus.c \
			parse_int_bonus.c \
			exec_ops_bonus.c \
			check_dup_bonus.c \
			merge_sort_bonus.c

GNL_DIR = ./get_next_line
GNL_SRC = get_next_line.c \
		  get_next_line_utils.c

SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
GNL_OBJ = $(GNL_SRC:.c=.o)

LIBFT_DIR = ./libft/

$(NAME):
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -g -c -I. $(SRC)
	$(CC) $(CFLAGS) -g -I. $(SRC_OBJ) $(LIBFT_DIR)libft.a -o $(NAME)
	cp ./push_swap ./visualizer/
	./visualizer/visualizer

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean $(NAME)
	make -C $(LIBFT_DIR) re

bonus:
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -c -g -I. $(BONUS_SRC) $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
	$(CC) $(CFLAGS) -I. $(BONUS_OBJ) $(GNL_OBJ) $(LIBFT_DIR)libft.a -o $(BONUS_NAME)		

bclean:
	rm -f $(BONUS_OBJ) $(GNL_DIR)$(GNL_OBJ)	

bfclean: bclean
	rm -f $(BONUS_NAME)

bre: bclean bonus

.PHONY:
	all clean fclean re bonus bclean bfclean bre
