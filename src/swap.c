#include "../includes/push_swap.h"

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
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	swap_elem(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_elem(a);
	swap_elem(b);
	write(1, "ss\n", 3);
}