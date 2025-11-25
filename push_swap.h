#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

#include <stdlib.h>
#include <unistd.h>

int		ft_atol(const char *str);
t_node	*ft_lstnew(int content);
void	ft_lstadd_back(t_node **lst, t_node *new);
void	ft_putnbr(int nb);
char	**ft_split(char const *s, char c);
int	ft_isspace(char c);
char	**parsing(char **av);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);
void	ft_lstclear(t_node **lst, void (*del)(void *));


#endif