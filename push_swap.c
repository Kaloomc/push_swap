/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:04:33 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/02 15:47:14 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_list	*print_node(t_list *node)
{
	if (!node)
		return (NULL);
	ft_putnbr_fd(node->content, 1);
	return (node->next);
}

void	print_stack(t_list *stack_a, t_list *stack_b)
{
	write(1, "A :", 3);
	write(1, "          ", 10);
	write(1, "B :\n\n", 5);
	while (stack_a || stack_b)
	{
		if (stack_a)
			stack_a = print_node(stack_a);
		write(1, "            ", 12);
		if (stack_b)
			stack_b = print_node(stack_b);
		write(1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	char	**new_av;
	int		i;
	t_list	*stack_b;

	(void)ac;
	stack_a = NULL;
	stack_b = NULL;
	i = 0;
	new_av = parsing(&av[1]);
	if (!new_av)
	{
		write(1, "Error", 5);
		return (0);
	}
	while (new_av[i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(new_av[i++])));
	free_parsing(new_av);
	print_stack(stack_a, stack_b);
	ft_printf("\n");
	print_stack(stack_a, stack_b);
	ft_lstclear(&stack_a, &free);
}
