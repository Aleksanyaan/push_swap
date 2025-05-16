#include "./includes/push_swap.h"

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc < 2)
		return (0);
	while (i < argc)
	{
		if (!check_valid_args(argv[i]) || has_duplicates(argv))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		i++;
	}
	write(2, "Success\n", 8);
	return (0);
}
