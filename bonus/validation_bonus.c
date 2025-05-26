#include "checker.h"

int	check_overflow(const char *str, int i, int sign)
{
	long	result;

	result = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && (sign * result) < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_int(const char *str)
{
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	if (!check_overflow(str, i, sign))
		return (0);
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
		while (args[j])
		{
			compare = ft_atoi(args[j]);
			if (current == compare)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*join_all_args(int argc, char **argv)
{
	char	*joined;
	char	*tmp;
	char	*new_part;
	int		i;

	i = 1;
	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	while (i < argc)
	{
		new_part = ft_strjoin(" ", argv[i]);
		if (!new_part)
			return (free(joined), NULL);
		tmp = ft_strjoin(joined, new_part);
		free(new_part);
		free(joined);
		if (!tmp)
			return (NULL);
		joined = tmp;
		i++;
	}
	return (joined);
}

int	check_valid_args(int argc, char **argv)
{
	char	*joined;
	char	**args;
	int		i;

	joined = join_all_args(argc, argv);
	if (!joined)
		return (0);
	args = ft_split(joined, ' ');
	free(joined);
	if (!args || !args[0])
		return (free_args(args), 0);
	i = 0;
	while (args[i])
	{
		if (!is_valid_int(args[i]))
			return (free_args(args), 0);
		i++;
	}
	if (has_duplicates(args))
		return (free_args(args), 0);
	free_args(args);
	return (1);
}
