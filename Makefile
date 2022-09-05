# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfarias- <lfarias-@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/04 22:24:57 by lfarias-          #+#    #+#              #
#    Updated: 2022/09/05 00:47:33 by lfarias-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

GNL_DIR = ./get_next_line/
GNL_SRC = get_next_line.c \
		  get_next_line_utils.c
GNL = $(addprefix $(GNL_DIR), $(GNL_SRC))

SRC_OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
GNL_OBJ = $(GNL:.c=.o)

LIBFT_DIR = ./libft

$(NAME): $(SRC_OBJ) 
	make -C $(LIBFT_DIR) libft.a
	$(CC) $(CFLAGS) -g -I. $(SRC_OBJ) $(LIBFT_DIR)/libft.a -o $(NAME)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(LIBFT_DIR)/libft.a 
	rm -f push_swap

re: fclean $(NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(GNL_OBJ)
	make -C $(LIBFT_DIR)/ libft.a
	$(CC) $(CFLAGS) -I. $(BONUS_OBJ) $(GNL) $(LIBFT_DIR)/libft.a -o $(BONUS_NAME)	

bonus: $(BONUS_NAME)

bclean:
	rm -f $(BONUS_OBJ) $(GNL_OBJ)	

bfclean: bclean
	rm -f $(BONUS_NAME)

bre: bclean bonus

.PHONY:
	all clean fclean re bonus bclean bfclean bre
