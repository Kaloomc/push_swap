/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:04:27 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/01 18:01:16 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	verif_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
		{
			if (line[i] == '+' || line[i] == '-')
			{
				if (i > 0 && line[i - 1] != ' ')
					return (0);
				if (!(line[i + 1] >= '0' && line[i + 1] <= '9'))
					return (0);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

char	**parsing(char **av)
{
	char	*new_line;
	char	*tmp;
	char	**res;
	int		i;

	i = 0;
	new_line = ft_strdup("");
	while (av[i])
	{
		tmp = ft_strjoin_space(new_line, av[i]);
		free(new_line);
		new_line = tmp;
		i++;
	}
	if (only_spaces(new_line) || !verif_line(new_line))
		return (NULL);
	res = ft_split(new_line, ' ');
	free(new_line);
	return (res);
}
