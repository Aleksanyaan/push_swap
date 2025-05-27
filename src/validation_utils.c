/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:51:36 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 13:51:37 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	i;
	int	sign;

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

int	is_empty_or_spaces(const char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}

int	check_empty(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (is_empty_or_spaces(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
