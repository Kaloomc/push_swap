/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:23:46 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/04 15:54:03 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->content;
	second = (*a)->next->content;
	third = (*a)->next->next->content;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

int	find_pos(t_list *stack, int rank)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->content == rank)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	sort_chunks(t_list **a, t_list **b)
{
	int	i;
	int	range;

	if (ft_lstsize(*a) <= 100)
		range = 15;
	else
		range = 35;
	i = 0;
	while (*a)
	{
		if ((*a)->content <= i)
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if ((*a)->content <= i + range)
		{
			pb(a, b);
			i++;
		}
		else
			ra(a);
	}
	push_back_to_a(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int		min;
	t_list	*ptr;

	while (ft_lstsize(*a) > 3)
	{
		ptr = *a;
		min = ptr->content;
		while (ptr)
		{
			if (ptr->content < min)
				min = ptr->content;
			ptr = ptr->next;
		}
		if (find_pos(*a, min) <= ft_lstsize(*a) / 2)
			while ((*a)->content != min)
				ra(a);
		else
			while ((*a)->content != min)
				rra(a);
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
