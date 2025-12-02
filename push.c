/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:31:55 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/02 15:30:28 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **from, t_list **to)
{
	t_list	*tmp;

	tmp = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, tmp);
	ft_printf("pa\n");
}

void	pb(t_list **from, t_list **to)
{
	t_list *tmp;

	tmp = *from;
	*from = (*from)->next;
	ft_lstadd_front(to, tmp);
	ft_printf("pb\n");
}