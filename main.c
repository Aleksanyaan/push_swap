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
	free(joined);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (1);
	}

	print_stack(a);
	free_stack(a);
	return (0);
}
