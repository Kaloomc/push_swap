/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 14:04:27 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/21 16:36:40 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int only_spaces(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}


int verif_line(char *line)
{
    int i = 0;

    while (line[i])
    {
        if (line[i] != ' ' && (line[i] < '0' || line[i] > '9'))
        {
            if (line[i] == '+' || line[i] == '-')
            {
                if (i > 0 && line[i - 1] != ' ')
                    return 0;
                if (!(line[i + 1] >= '0' && line[i + 1] <= '9'))
                    return 0;
            }
            else
                return 0;
        }
        i++;
    }
    return 1;
}


char	**parsing(char **av)
{
	char *new_line;
	int i;

	i = 0;
	new_line = ft_strdup("");
	while(av[i])
	{
		new_line = ft_strjoin(new_line,av[i]);
		i++;
	}
	if (only_spaces(new_line) || !verif_line(new_line))
		return NULL;
	return ft_split(new_line, ' ');

}