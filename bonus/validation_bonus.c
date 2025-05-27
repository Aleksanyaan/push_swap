/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaleksan <zaleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 13:51:39 by zaleksan          #+#    #+#             */
/*   Updated: 2025/05/27 13:55:58 by zaleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

	if (!check_empty(argc, argv))
		return (0);
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
