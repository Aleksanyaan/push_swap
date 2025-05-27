NAME		= push_swap
B_NAME = checker

LIBFT_DIR	= libs/libft

LIBFT		= -L./$(LIBFT_DIR) -lft

INCLUDES	= -I./includes -I./$(LIBFT_DIR)

HEADER		= ./includes/push_swap.h

B_HEADER 	= ./includes/checker.h

CC			= cc

FLAGS		= -Wall -Wextra -Werror

SRC_DIR		= ./src
BONUS_DIR	= ./bonus

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
				$(SRC_DIR)/validation_utils.c \

B_SRCS		= $(BONUS_DIR)/checker.c \
				$(BONUS_DIR)/validation_bonus.c \
 				$(BONUS_DIR)/free_bonus.c \
				$(BONUS_DIR)/fill_stack_bonus.c \
				$(BONUS_DIR)/swap_bonus.c \
				$(BONUS_DIR)/push_bonus.c \
				$(BONUS_DIR)/rotate_bonus.c \
				$(BONUS_DIR)/reverse_rotate_bonus.c \
				$(BONUS_DIR)/small_sorts_bonus.c \
				$(BONUS_DIR)/sort_utils_bonus.c \
				$(BONUS_DIR)/butterfly_bonus.c \
				$(BONUS_DIR)/validation_utils_bonus.c \


MAIN		= main.c

OBJ			= $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC))
BOBJ		= $(patsubst $(BONUS_DIR)/%.c, $(BUILD_DIR)/%.o, $(B_SRCS))
MOBJ		= $(MAIN:%.c=%.o)

BUILD_DIR	= ./build

all: build lib $(NAME)

$(NAME): $(OBJ) $(MOBJ) $(LIBFT_DIR)/libft.a Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(MOBJ) -o $(NAME) $(LIBFT)

$(B_NAME): $(BOBJ) $(MOBJ) $(LIBFT_DIR)/libft.a Makefile
	$(CC) $(FLAGS) $(INCLUDES) $(BOBJ) -o $(B_NAME) $(LIBFT)

$(BUILD_DIR)/%.o:	$(SRC_DIR)/%.c Makefile $(HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(BUILD_DIR)/%.o: $(BONUS_DIR)/%.c Makefile $(B_HEADER)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


bonus: build lib $(B_NAME)

lib:
	make -C $(LIBFT_DIR) 
	make bonus -C $(LIBFT_DIR) 

build:
	mkdir -p ${BUILD_DIR}

clean:
	rm -rf $(BUILD_DIR) $(MOBJ) $(BOBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(B_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all
	make -C $(LIBFT_DIR) re

.PHONY:	all fclean clean re lib build