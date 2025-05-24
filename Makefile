NAME		= push_swap

LIBFT_DIR	= libs/libft

LIBFT		= -L./$(LIBFT_DIR) -lft

INCLUDES	= -I./includes -I./$(LIBFT_DIR)

HEADER		= ./includes/push_swap.h

CC			= cc

FLAGS		= -Wall -Wextra -Werror -fsanitize=address

SRC_DIR		= ./src

SRC			= $(SRC_DIR)/validation.c \
 				$(SRC_DIR)/free.c \
				$(SRC_DIR)/fill_stack.c \
				$(SRC_DIR)/swap.c \
				$(SRC_DIR)/push.c \
				$(SRC_DIR)/rotate.c \
				$(SRC_DIR)/reverse_rotate.c \
				$(SRC_DIR)/small_sorts.c \
				$(SRC_DIR)/sort_utils.c \
				$(SRC_DIR)/butterfly.c \

MAIN		= main.c

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
MOBJ		= $(MAIN:%.c=%.o)

BUILD_DIR	= ./build

all: build lib $(NAME)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c Makefile $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(MOBJ) $(LIBFT_DIR)/libft.a Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(MOBJ) -o $(NAME) $(LIBFT)

lib:
	make -C $(LIBFT_DIR)

build:
	mkdir -p ${BUILD_DIR}

clean:
	rm -rf $(BUILD_DIR) $(MOBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
	make -C $(LIBFT_DIR) re

.PHONY:	all fclean clean re lib build