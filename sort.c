/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarnier <fgarnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:23:46 by fgarnier          #+#    #+#             */
/*   Updated: 2025/12/04 18:14:03 by fgarnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_rank(int size, t_list *ptr, int *arr)
{
	int	rank;
	int	i;

	while (ptr)
	{
		rank = 0;
		i = -1;
		while (++i < size)
			if (arr[i] < ptr->content)
				rank++;
		ptr->index = rank;
		ptr = ptr->next;
	}
}

void	normalize_stack(t_list **stack)
{
	t_list	*ptr;
	int		*arr;
	int		i;
	int		size;

	size = ft_lstsize(*stack);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	ptr = *stack;
	i = 0;
	while (ptr)
	{
		arr[i++] = ptr->content;
		ptr = ptr->next;
	}
	ptr = *stack;
	set_rank(size, ptr, arr);
	free(arr);
}

void	push_back_to_a(t_list **a, t_list **b)
{
	int		current_max;
	t_list	*tmp;

	while (*b)
	{
		current_max = -1;
		tmp = *b;
		while (tmp)
		{
			if (tmp->index > current_max)
				current_max = tmp->index;
			tmp = tmp->next;
		}
		if (find_pos(*b, current_max) <= ft_lstsize(*b) / 2)
		{
			while ((*b)->index != current_max)
				rb(b);
		}
		else
		{
			while ((*b)->index != current_max)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_stacks(t_list **a, t_list **b)
{
	int	size;

	if (!a || !*a)
		return ;
	if (is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	normalize_stack(a);
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
		sort_chunks(a, b);
}
