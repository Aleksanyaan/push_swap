/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:55:24 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 21:10:31 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	apply_operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strncmp(op, "sa\n", 3))
		sa(*a);
	else if (!ft_strncmp(op, "sb\n", 3))
		sb(*b);
	else if (!ft_strncmp(op, "ss\n", 3))
		ss(*a, *b);
	else if (!ft_strncmp(op, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(op, "pb\n", 3))
		pb(a, b);
	else if (!ft_strncmp(op, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(op, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(op, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(op, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(op, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(op, "rrr\n", 3))
		rrr(a, b);
	else
		return (0);
	return (1);
}

int	check_operations(t_stack **a, t_stack **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!apply_operation(a, b, line))
			return (free(line), 0);
		free(line);
	}
	return (1);
}

void	write_output(t_stack **a, t_stack **b)
{
	if (is_sorted(*a) && *b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(*a);
	free_stack(*b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*joined;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	joined = join_all_args(argc, argv);
	if (!joined || !check_valid_args(argc, argv))
		return (free(joined), 1);
	a = fill_stack_a(joined);
	free(joined);
	if (!a)
		return (1);
	set_index(a);
	if (!check_operations(&a, &b))
		return (write_output(&a, &b), 1);
	write_output(&a, &b);
	return (0);
}
