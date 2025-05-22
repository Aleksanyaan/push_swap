#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

// validation.c
int					is_valid_int(const char *str);
int					check_valid_args(int argc, char **argv);
int					has_duplicates(char **args);
char				*join_all_args(int argc, char **argv);

// free.c
void				free_args(char **args);
void				free_stack(t_stack *stack);

// fill_stack.h
t_stack				*fill_stack_a(const char *str);

#endif