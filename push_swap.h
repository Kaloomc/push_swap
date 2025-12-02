#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

int		ft_atol(const char *str);
char	**parsing(char **av);
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

#endif