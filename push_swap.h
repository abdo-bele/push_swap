#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

typedef struct s_data
{
	t_list	*stacka;
	t_list	*stackb;
	int		max;
	int		min;
	int		counta;
	int		countb;
	int		count;
	int		countpf;
	int		countps;
	int		index;
	int		hold_first;
	int		hold_second;
	int		chunk;
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
void    get_chunk(t_data *data);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *c);
void    ft_intindex(t_list *data);
void	ft_check_max(t_data *data);
void	ft_check_maxb(t_data *data);
void	ft_checknumber(t_data *data);
void    ft_indexstacka(t_data *data);
void	ft_sort_5number(t_data *data);
void	ft_sort_3number(t_data *data);
void	ft_sort_end_push(t_data *data);
char	*ft_strjoin(char *s1, char *s2);
void    ft_sort_100number(t_data *data);
void    ft_check_position(t_data *data);
char	**ft_split(char const *s, char c);
int 	ft_atoi2(const char *str, int i, int b);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);

#endif