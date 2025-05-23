#include "./includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d\n", stack->value);
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	*joined;

	if (argc < 2)
		return (0);

	joined = join_all_args(argc, argv);
	if (!joined || !check_valid_args(argc, argv))
	{
		free(joined);
		write(2, "Error\n", 6);
		return (1);
	}

	a = fill_stack_a(joined);
	b = fill_stack_a(joined);
	free(joined);
	if (!a || !b)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	// print_stack(a);
	// print_stack(b);
	rra(&a);
	printf("A\n");
	print_stack(a);
	// printf("B\n");
	// print_stack(b);
	free_stack(a);
	free_stack(b);
	return (0);
}
