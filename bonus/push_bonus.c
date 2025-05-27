/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:55:34 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 13:55:35 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

static void	push_stack(t_stack **to, t_stack **from)
{
	t_stack	*node;

	node = pop_stack(from);
	if (node)
		push_front(to, node);
}

void	pa(t_stack **a, t_stack **b)
{
	push_stack(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	push_stack(b, a);
}
