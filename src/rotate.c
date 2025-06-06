/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:51:23 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 13:51:24 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	shift_up(t_stack **stack)
{
	t_stack	*top;

	top = pop_stack(stack);
	stack_add_back(stack, top);
}

void	ra(t_stack **a)
{
	shift_up(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	shift_up(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	shift_up(a);
	shift_up(b);
	write(1, "rr\n", 3);
}
