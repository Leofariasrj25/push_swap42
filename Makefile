SRC = push_swap.c \
	 stack.c 
LIBFT_DIR = ./libft/
CC = cc
CFLAGS = -Wall -Werror -Wextra
T_MAIN = test_main.c

push_swap:
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -g -I. stack.c push_swap.c $(LIBFT_DIR)libft.a -o push_swap

all: push_swap

clean:
	rm -f push_swap
	
re:
	clean
	push_swap
test:
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -I. stack.c test_main.c $(LIBFT_DIR)libft.a -o test

tclean:
	rm -f ./test
