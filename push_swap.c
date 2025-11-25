/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:04:33 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/21 16:56:37 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_node *stack)
{
	if(!stack)
		return;
	ft_putnbr(stack->value);
	if (stack->next)
	{
		write(1,"\n",1);	
		print_stack(stack->next);
	}
}
#include <stdio.h>
int main(int ac, char **av)
{
	t_node *stack_a = NULL;
	t_node *stack_b = NULL;
	char **new_av;
	int i;
	i = 0;
	new_av = parsing(&av[1]);
	if (!new_av)
	{
		write(1,"Error",5);
		return 0;
	}
	
	while(new_av[i])
	{
		if (ft_atoi(new_av[i]) > 2147483648 || ft_atoi(new_av[i]) > -2147483647)
		{
			ft_lstclear(&stack_a,&free);
			return 0;
		}
		ft_lstadd_back(&stack_a,ft_lstnew(ft_atoi(new_av[i])));
		i++;
	}
	
	print_stack(stack_a);
	
}