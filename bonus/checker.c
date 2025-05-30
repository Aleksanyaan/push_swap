/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:55:24 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/30 14:32:32 by zaleksan         ###   ########.fr       */
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
	else if (!ft_strncmp(op, "rrr\n", 4))
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
			return (0);
		if (!apply_operation(a, b, line))
		{
			free(line);
			get_next_line(-1);
			return (0);
		}
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
	int		size;
	char	*joined;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	joined = join_all_args(argc, argv);
	if (!joined || !check_valid_args(argc, argv))
		return (free(joined), write(2, "Error\n", 6), 1);
	a = fill_stack_a(joined);
	free(joined);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	set_index(a);
	size = stack_size(a);
	if (!size || size == 1 || is_sorted(a))
		return (0);
	if (!check_operations(&a, &b))
		return (write_output(&a, &b), 1);
	write_output(&a, &b);
	return (0);
}
