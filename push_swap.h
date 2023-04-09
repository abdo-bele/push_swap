/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:35:40 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 14:59:17 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
void	ft_check(char *av);
void	ft_free(char **ab);
void	ft_putstr(char *str);
void	ft_sort(t_data *data);
void	get_chunk(t_data *data);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *c);
void	ft_intindex(t_list *data);
void	ft_chek_dup(t_data *data);
void	ft_check_max(t_data *data);
void	ft_sortnumber(t_data *data);
void	ft_check_maxb(t_data *data);
void	ft_checknumber(t_data *data);
void	ft_indexstacka(t_data *data);
void	ft_sort_5number(t_data *data);
void	ft_sort_3number(t_data *data);
void	ft_sort_end_push(t_data *data);
char	*ft_strjoin(char *s1, char *s2);
void	ft_sort_100number(t_data *data);
void	ft_check_position(t_data *data);
char	**ft_split(char const *s, char c);
void	ft_get_stacka(t_data *data, char **av);
int		ft_atoi2(const char *str, int i, int b);
int		ft_strcmp(const char *a, const char *b);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst);
void	ft_lstclear(t_list **lst);
int		ft_strncmp(const char *a, const char *b, size_t n);

#endif