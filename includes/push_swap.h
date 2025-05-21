#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// validation.c
int	is_valid_int(const char *str);
int	check_valid_args(int argc, char **argv);
int	has_duplicates(char **args);

// free.c
void	free_args(char **args);

#endif