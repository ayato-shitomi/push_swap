CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
DBG		=	-g3 -fsanitize=address -fsanitize=leak
CI		=	-I include/
RM		=	rm -rf

NAME	=	push_swap

SRCS	=	srcs/add_state.c \
			srcs/align_stacks.c \
			srcs/bruteforce.c \
			srcs/bruteforce_pick_check.c \
			srcs/check_ac.c \
			srcs/free_something.c \
			srcs/ft_bzero.c \
			srcs/ft_calloc.c \
			srcs/ft_itoa.c \
			srcs/ft_memset.c \
			srcs/ft_strdup.c \
			srcs/ft_putstr_fd.c \
			srcs/ft_strlen.c \
			srcs/ft_strncmp.c \
			srcs/instructions.c \
			srcs/instructions_utils.c \
			srcs/less_mvt.c \
			srcs/main.c \
			srcs/movement.c \
			srcs/new_empty_state.c \
			srcs/pushswap_utils.c \
			srcs/resolve.c \
			srcs/resolve_utils.c \
			srcs/rotate.c \
			srcs/second_resolve_utils.c \
			srcs/second_resolve.c \
			srcs/stack.c \
			srcs/stacks_utils.c \
			srcs/stack_utils.c \
			srcs/utils.c

all			:	$(NAME)

$(NAME)	:	$(SRCS)
	clear
	$(CC) $(CFLAGS) $(CI) $(SRCS) $(DBG) -o $(NAME)

clean		:
	clear
	$(RM)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

test		:	re
	./push_swap 1
	./push_swap 0
	./push_swap 2 3 1
	./push_swap 2 3 1 5 4 0
	./push_swap 7834 5 72 63 954 97 824 1
	./push_swap 4 64 26 32 44 60 3 12 87 10 34 81 91 52 61 40 69 79 1 73 6

.PHONY		:	all clean fclean re