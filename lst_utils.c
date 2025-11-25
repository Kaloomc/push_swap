/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 11:21:01 by fgarnier          #+#    #+#             */
/*   Updated: 2025/11/21 16:59:29 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int content)
{
	t_node	*newelem;

	newelem = malloc(sizeof(t_node));
	if (!newelem)
		return (NULL);
	newelem->value = content;
	newelem->next = NULL;
	return (newelem);
}

t_node	*ft_lstlast(t_node *lst)
{
	t_node	*current;

	if (!lst)
		return (NULL);
	current = lst;
	while (current->next)
		current = current->next;
	return (current);
}

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
}

void	ft_lstdelone(t_node *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	del(lst->value);
	free(lst);
}

void	ft_lstclear(t_node **lst, void (*del)(void *))
{
	t_node	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	*lst = NULL;
}