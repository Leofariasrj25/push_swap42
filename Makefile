SRC = push_swap.c \
	 stack.c \
OBJ = $(SRC:.c=.o)
LIBFT_DIR = ./libft/
CC = cc
CFLAGS = -Wall -Werror -Wextra
T_MAIN = test_main.c

test:
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -I. stack.c test_main.c $(LIBFT_DIR)libft.a -o test

tclean:
	rm -f ./test
