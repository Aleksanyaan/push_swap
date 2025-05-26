#include "checker.h"

void	swap_elem(t_stack *stack)
{
	int	tmp;

	if (!stack || !stack->next)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

void	sa(t_stack *a)
{
	swap_elem(a);
}

void	sb(t_stack *b)
{
	swap_elem(b);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_elem(a);
	swap_elem(b);
}
