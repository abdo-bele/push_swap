#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	t_list	*stacka;
	t_list	*stackb;
	int		max;
	int		min;
	int		counta;
	int		count;
}					t_data;

void	ra(t_data *data);
void	pb(t_data *data);
void	pa(t_data *data);
void	sb(t_data *data);
void	rb(t_data *data);
void	sa(t_data *data);
void	rr(t_data *data);
void	ss(t_data *data);
void	rrb(t_data *data);
void	rra(t_data *data);
void	rrr(t_data *data);
size_t	ft_strlen(const char *c);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
void	ft_check_max(t_data *data);
void	ft_sort_5number(t_data *data);
void	ft_sort_3number(t_data *data);
void	ft_sort_end_push(t_data *data);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
char	*ft_strjoin(char *s1, char *s2);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);

#endif