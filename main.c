#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	if (!check_valid_args(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	write(1, "Success\n", 8);
	return (0);
}
