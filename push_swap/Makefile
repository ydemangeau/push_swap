CC=gcc
FLAG=-Wall -Wextra -Werror
LIB_DIR=./libft
LIB=./libft/libft.a
EXEC=push_swap
EXEC_CHECKER=checker
SRC=srcs/main.c\
	srcs/operation.c\
	srcs/utils.c \
	srcs/utils2.c \
	srcs/env.c \
	srcs/swap_push.c \
	srcs/rotate.c \
	srcs/truc.c \
	srcs/algo.c \
	srcs/error.c \
	srcs/quick_sort.c \

SRC_CHECKER=srcs/checker.c\
	srcs/operation.c\
	srcs/utils.c \
	srcs/utils2.c \
	srcs/env.c \
	srcs/swap_push.c \
	srcs/rotate.c \
	srcs/truc.c \
	srcs/error.c \
	srcs/algo.c \
	srcs/quick_sort.c \

all:$(EXEC)

$(EXEC) :$(SRC) $(SRC_CHECKER)
		@(cd $(LIB_DIR) && $(MAKE))
		$(CC) $(SRC) $(LIB) -o $(EXEC)
		$(CC) $(SRC_CHECKER) $(LIB) -o $(EXEC_CHECKER)

clean:
	@(cd $(LIB_DIR) && $(MAKE) $@)

fclean: clean
		@(cd $(LIB_DIR) && $(MAKE) $@)
		rm -rf $(EXEC)

re: fclean all

.PHONY : all, clean, fclean, re
