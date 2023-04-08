/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:47 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/08 18:34:48 by aarchtou         ###   ########.fr       */
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
	free(ab);
}
