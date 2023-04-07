#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line/get_next_line.h"

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
	int		index;
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
void	ft_check(char *av);
void	ft_putstr(char *str);
t_list	*ft_lstnew(int content);
int		ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_check_operation(char *str, t_data *data);
int		ft_strncmp(const char *a, const char *b, size_t n);

#endif