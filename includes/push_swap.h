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
void				stack_add_back(t_stack **stack, t_stack *new);
void				set_index(t_stack *stack);

// swap.c
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

// push.c
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
t_stack				*pop_stack(t_stack **stack);
void				push_front(t_stack **stack, t_stack *new_node);

// rotate.c
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

// reverse_rotate.c
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);

#endif