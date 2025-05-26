#include "checker.h"

void	shift_up(t_stack **stack)
{
	t_stack	*top;

	top = pop_stack(stack);
	stack_add_back(stack, top);
}

void	ra(t_stack **a)
{
	shift_up(a);
}

void	rb(t_stack **b)
{
	shift_up(b);
}

void	rr(t_stack **a, t_stack **b)
{
	shift_up(a);
	shift_up(b);
}
