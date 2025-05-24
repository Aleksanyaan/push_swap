#include "../includes/push_swap.h"

void	sort2(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		sa(*stack);
}

void	sort3(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first < third)
		sa(*stack);
	else if (first > second && second > third)
	{
		sa(*stack);
		rra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
	else if (first > second && first > third && second < third)
		ra(stack);
	else if (second > third && third > first && second > first)
	{
		rra(stack);
		sa(*stack);
	}
}

void	sort4(t_stack **a, t_stack **b)
{
	int	min_index;
	int	position;

	min_index = get_min_index(*a);
	position = get_position(*a, min_index);
	if (position == 1)
		ra(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_stack **a, t_stack **b)
{
	int	min_index;
	int	position;

	min_index = get_min_index(*a);
	position = get_position(*a, min_index);
	if (position == 1)
		ra(a);
	else if (position == 2)
	{
		ra(a);
		ra(a);
	}
	else if (position == 3)
	{
		rra(a);
		rra(a);
	}
	else if (position == 4)
		rra(a);
	if (is_sorted(*a))
		return ;
	pb(a, b);
	sort4(a, b);
	pa(a, b);
	pa(a, b);
}
