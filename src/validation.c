#include "../includes/push_swap.h"

static int	check_overflow(long result, int sign)
{
	if (sign == 1 && result > INT_MAX)
		return (0);
	if (sign == -1 && (sign * result) < INT_MIN)
		return (0);
	return (1);
}

int	is_valid_int(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		if (!check_overflow(result, sign))
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicates(char **args)
{
	int	i;
	int	j;
	int	current;
	int	compare;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		current = ft_atoi(args[i]);
		printf("cur = %s\n", args[i]);
		while (args[j])
		{
			compare = ft_atoi(args[j]);
			printf("cmp = %s\n", args[j]);
			if (current == compare)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_valid_args(const char *str)
{
	int		i;
	char	**args;

	if (!str)
		return (0);
	args = ft_split(str, ' ');
	if (!args || !args[0])
	{
		free_args(args);
		return (0);
	}
	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
		{
			free_args(args);
			return (0);
		}
		// printf("%s", args[i]);
		i++;
	}
	if (has_duplicates(args))
	{
		free_args(args);
		return (0);
	}
	free_args(args);
	return (1);
}
