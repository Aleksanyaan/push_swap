#include "../includes/push_swap.h"

int	optimaizer(int size)
{
	int	sqrt;
	int	log;

	sqrt = 1;
	log = 0;
	while (sqrt < size / sqrt)
		sqrt++;
	while (size)
	{
		size /= 2;
		log++;
	}
	return (sqrt + log - 1);
}

void	butterfly(t_stack **a, t_stack **b, int size)
{
	int n;
	int	counter;

	n = optimaizer(size);
	counter = 0;
	while (counter < size && *a)
	{
		if ((*a)->index <= counter)
		{
			pb(a, b);
			rb(b);
			counter++;
		}
		else if ((*a)->index <= counter + n)
		{
			pb(a, b);
			counter++;
		}
		else
			ra(a);
	}
}

void	back_to_a(t_stack **a, t_stack **b)
{
	int pos;
	int size;
	int max;
	
	while (*b)
	{
		max = get_max_index(*b);
		pos = get_position(*b, max);
		size = stack_size(*b);
		if (pos <= size / 2)
		{
			while ((*b)->index != max)
			{
				rb(b);
			}
		}
		else
		{
			while ((*b)->index != max)
			{
				rrb(b);
			}
		}
		pa(a, b);
	}
}