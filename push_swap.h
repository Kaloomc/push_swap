#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>
long	ft_atol(const char *str);
char	**parsing(char **av);
int		check_value(t_list *stack);
char	*ft_strjoin_space(const char *s1, const char *s2);

void	sa(t_list **node);
void	sb(t_list **node);
void	ss(t_list **node_a, t_list **node_b);

void	pa(t_list **from, t_list **to);
void	pb(t_list **from, t_list **to);

void	ra(t_list **node);
void	rb(t_list **node);
void	rr(t_list **node_a, t_list **node_b);

void	rra(t_list **node);
void	rrb(t_list **node);
void	rrr(t_list **node_a, t_list **node_b);

t_list	*before_last(t_list *list);

void	sort_stacks(t_list **a, t_list **b);
void	sort_3(t_list **a);
int		find_pos(t_list *stack, int rank);
void	sort_chunks(t_list **a, t_list **b);
void	sort_5(t_list **a, t_list **b);

void	push_back_to_a(t_list **a, t_list **b);
int		is_sorted(t_list *stack);
void	normalize_stack(t_list **stack);

#endif