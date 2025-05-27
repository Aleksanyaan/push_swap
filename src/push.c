/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:51:17 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 13:51:18 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*pop_stack(t_stack **stack)
{
	t_stack	*top;

	if (!stack || !*stack)
		return (NULL);
	top = *stack;
	*stack = (*stack)->next;
	top->next = NULL;
	return (top);
}

void	push_front(t_stack **stack, t_stack *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

static void	push_stack(t_stack **to, t_stack **from, const char *op_name)
{
	t_stack	*node;

	node = pop_stack(from);
	if (node)
	{
		push_front(to, node);
		write(1, op_name, 3);
	}
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(a, b, "pa\n");
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(b, a, "pb\n");
}
