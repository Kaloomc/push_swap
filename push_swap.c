/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:04:33 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/04 17:32:42 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		signe;
	long	res;

	signe = 1;
	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * signe);
}

void	free_parsing(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

int	main(int ac, char **av)
{
	t_list	*a;
	char	**new_av;
	int		i;
	t_list	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	i = 0;
	new_av = parsing(&av[1]);
	if (!new_av)
		return (0);
	while (new_av[i])
		ft_lstadd_back(&a, ft_lstnew(ft_atol(new_av[i++])));
	free_parsing(new_av);
	if (check_value(a))
		sort_stacks(&a, &b);
	ft_lstclear(&a, &free);
	ft_lstclear(&b, &free);
	return (0);
}
