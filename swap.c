/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:12:02 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/04 15:40:49 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **node)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*tmp;

	elem1 = *node;
	elem2 = elem1->next;
	tmp = elem2->next;
	*node = elem2;
	elem2->next = elem1;
	elem1->next = tmp;
	ft_printf("sa\n");
}

void	sb(t_list **node)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*tmp;

	elem1 = *node;
	elem2 = elem1->next;
	tmp = elem2->next;
	*node = elem2;
	elem2->next = elem1;
	elem1->next = tmp;
	ft_printf("sb\n");
}

void	ss(t_list **node_a, t_list **node_b)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*tmp;

	elem1 = *node_a;
	elem2 = elem1->next;
	tmp = elem2->next;
	*node_a = elem2;
	elem2->next = elem1;
	elem1->next = tmp;
	elem1 = *node_b;
	elem2 = elem1->next;
	tmp = elem2->next;
	*node_b = elem2;
	elem2->next = elem1;
	elem1->next = tmp;
	ft_printf("ss\n");
}
