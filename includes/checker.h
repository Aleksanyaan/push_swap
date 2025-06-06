/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:12:12 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 14:12:13 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

// validation_bonus.c
char				*join_all_args(int argc, char **argv);

// validation_utils_bonus.c
int					has_duplicates(char **args);
int					is_valid_int(const char *str);
int					is_empty_or_spaces(const char *str);
int					check_valid_args(int argc, char **argv);
int					check_empty(int argc, char **argv);

// free_bonus.c
void				free_args(char **args);
void				free_stack(t_stack *stack);

// fill_stack_bonus.h
t_stack				*fill_stack_a(const char *str);
void				stack_add_back(t_stack **stack, t_stack *new);
void				set_index(t_stack *stack);

// swap_bonus.c
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);

// push_bonus.c
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
t_stack				*pop_stack(t_stack **stack);
void				push_front(t_stack **stack, t_stack *new_node);

// rotate_bonus.c
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rr(t_stack **a, t_stack **b);

// reverse_rotate_bonus.c
void				rra(t_stack **a);
void				rrb(t_stack **b);
void				rrr(t_stack **a, t_stack **b);
t_stack				*stack_last(t_stack **stack);

// small_sorts_bonus.c
void				sort2(t_stack **stack);
void				sort3(t_stack **stack);
void				sort4(t_stack **a, t_stack **b);
void				sort5(t_stack **a, t_stack **b);

// sort_utils_bonus.c
int					is_sorted(t_stack *stack);
int					get_position(t_stack *stack, int index);
int					get_min_index(t_stack *stack);
int					get_max_index(t_stack *stack);
int					stack_size(t_stack *stack);

// butterfly_bonus.c
void				back_to_a(t_stack **a, t_stack **b);
void				butterfly(t_stack **a, t_stack **b, int size);

#endif