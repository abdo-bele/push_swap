/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:47 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/10 16:35:50 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_intindex(t_list *data)
{
	t_list	*h;

	h = data;
	while (h)
	{
		h->index = 0;
		h = h->next;
	}
}

void	ft_chek_dup(t_data *data)
{
	t_list	*l;
	t_list	*f;

	l = data->stacka;
	f = data->stacka;
	while (l)
	{
		while (f->next)
		{
			if (l->content == f->next->content)
			{
				ft_putstr("error");
				exit(1);
			}
			f = f->next;
		}
		l = l->next;
		f = l;
	}
}

void	ft_get_stacka(t_data *data, char **av)
{
	char	**ab;
	char	*al;
	int		i;

	i = 1;
	al = malloc(1);
	al[0] = '\0';
	while (av[i])
	{
		ft_check(av[i]);
		al = ft_strjoin(al, av[i++]);
		al = ft_strjoin(al, " ");
	}
	ab = ft_split(al, ' ');
	free(al);
	i = 0;
	while (ab[i])
	{
		ft_lstadd_back(&data->stacka, ft_lstnew(ft_atoi(ab[i])));
		data->count++;
		i++;
	}
	ft_free(ab);
}

void	ft_sort_end_pusha(t_data *data, int push)
{
	t_list	*test;
	int		i;

	test = data->stackb;
	i = 0;
	data->countb = ft_lstsize(data->stackb);
	while (test)
	{
		if (test->index == push)
		{
			if (i <= data->countb / 2)
			{
				while (i-- > 0)
					rb(data, 1);
			}
			else if (i > data->countb / 2)
			{
				while (data->countb - i++ > 0)
					rrb(data, 1);
			}
		}
		test = test->next;
		i++;
	}
	pa(data, 1);
}

void	ft_get_pos(t_data *data, t_list *a, int *c, int *b)
{
	while (a)
	{
		if (a->index == data->max)
			break ;
		a = a->next;
		data->countpf++;
	}
	a = data->stackb;
	while (a)
	{
		if (a->index == data->hold_second)
			break ;
		a = a->next;
		data->countps++;
	}
	if (data->countpf > (data->countb / 2))
		*c = data->countb - data->countpf;
	else
		*c = data->countpf;
	if (data->countps > (data->countb / 2))
		*b = data->countb - data->countps;
	else
		*b = data->countps;
}
