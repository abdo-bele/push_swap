#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	struct s_list	*last;
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	t_list	*stacka;
	t_list	*stackb;
	int		count;
}					t_data;

int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
int		ft_lstsize(t_list *lst);
void	ft_sort_3number(t_data *data);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);

#endif