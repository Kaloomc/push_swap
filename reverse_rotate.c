/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:43:33 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/04 15:43:15 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **node)
{
	t_list	*old_last;
	t_list	*new_last;
	t_list	*old_first;

	old_first = *node;
	old_last = ft_lstlast(*node);
	new_last = before_last(*node);
	new_last->next = NULL;
	*node = old_last;
	old_last->next = old_first;
	ft_printf("rra\n");
}

void	rrb(t_list **node)
{
	t_list	*old_last;
	t_list	*new_last;
	t_list	*old_first;

	old_first = *node;
	old_last = ft_lstlast(*node);
	new_last = before_last(*node);
	new_last->next = NULL;
	*node = old_last;
	old_last->next = old_first;
	ft_printf("rrb\n");
}

void	rrr(t_list **node_a, t_list **node_b)
{
	t_list	*old_last;
	t_list	*new_last;
	t_list	*old_first;

	old_first = *node_a;
	old_last = ft_lstlast(*node_a);
	new_last = before_last(*node_a);
	new_last->next = NULL;
	*node_a = old_last;
	old_last->next = old_first;
	old_first = *node_b;
	old_last = ft_lstlast(*node_b);
	new_last = before_last(*node_b);
	new_last->next = NULL;
	*node_b = old_last;
	old_last->next = old_first;
	ft_printf("rrr\n");
}

t_list	*before_last(t_list *list)
{
	t_list	*current;

	current = list;
	while (current->next->next)
		current = current->next;
	return (current);
}
