#include "checker.h"

t_stack	*stack_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!stack || !*stack)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	shift_down(t_stack **stack)
{
	t_stack	*prev;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = stack_last(stack);
	prev = *stack;
	while (prev->next && prev->next->next)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	shift_down(a);
}

void	rrb(t_stack **b)
{
	shift_down(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	shift_down(a);
	shift_down(b);
}
