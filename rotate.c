/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:43:33 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/04 15:41:38 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **node)
{
	t_list	*tmp;

	tmp = *node;
	*node = (*node)->next;
	tmp->next = NULL;
	ft_lstadd_back(node, tmp);
	ft_printf("ra\n");
}

void	rb(t_list **node)
{
	t_list	*tmp;

	tmp = *node;
	*node = (*node)->next;
	tmp->next = NULL;
	ft_lstadd_back(node, tmp);
	ft_printf("rb\n");
}

void	rr(t_list **node_a, t_list **node_b)
{
	t_list	*tmp;

	tmp = *node_a;
	*node_a = (*node_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(node_a, tmp);
	tmp = *node_b;
	*node_b = (*node_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(node_b, tmp);
	ft_printf("rr\n");
}
