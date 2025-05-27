/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:11:18 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 14:11:19 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
	else
	{
		butterfly(a, b, size);
		back_to_a(a, b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*joined;
	int		size;

	if (argc < 2)
		return (0);
	joined = join_all_args(argc, argv);
	if (!joined || !check_valid_args(argc, argv))
		return (free(joined), write(2, "Error\n", 6), 1);
	a = fill_stack_a(joined);
	b = NULL;
	free(joined);
	if (!a)
		return (write(2, "Error\n", 6), 1);
	set_index(a);
	size = stack_size(a);
	sort(&a, &b, size);
	free_stack(a);
	free_stack(b);
	return (0);
}
