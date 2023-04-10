/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:28 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/10 16:53:17 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] != ' ')
			return ;
		i++;
	}
	ft_putstr("error");
	exit(1);
}

void	ft_chek_drist(t_data *data)
{
	t_list	*a;
	int		c;
	int		b;

	a = data->stackb;
	b = 0;
	c = 0;
	data->countpf = 0;
	data->countps = 0;
	ft_get_pos(data, a, &c, &b);
	if (c <= b)
	{
		ft_sort_end_pusha(data, data->max);
		ft_sort_end_pusha(data, data->hold_second);
	}
	else
	{
		ft_sort_end_pusha(data, data->hold_second);
		ft_sort_end_pusha(data, data->max);
		sa(data, 1);
	}
}

void	ft_sort(t_data *data)
{
	if (data->count <= 3)
		ft_sort_3number(data);
	else if (data->count <= 5)
	{
		ft_sort_5number(data);
	}
	else if (data->count > 5)
	{
		while (data->stacka)
		{
			if (data->index > data->count)
				data->index = data->count;
			ft_sort_100number(data);
		}
		while (data->stackb)
		{
			data->countb = ft_lstsize(data->stackb);
			ft_check_maxb(data);
			ft_chek_drist(data);
		}
	}
}

void	ft_sortnumber(t_data *data)
{
	t_list	*a;
	t_list	*b;

	a = data->stacka;
	b = data->stacka;
	while (a)
	{
		while (b->next)
		{
			if (a->content > b->next->content)
			{
				ft_sort(data);
				return ;
			}
			b = b->next;
		}
		a = a->next;
		b = a;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.stacka = NULL;
	data.stackb = NULL;
	data.count = 0;
	if (ac < 2)
		return (0);
	if (ac > 1)
	{
		ft_get_stacka(&data, av);
		ft_chek_dup(&data);
		ft_intindex(data.stacka);
		ft_indexstacka(&data);
		get_chunk(&data);
		data.index = data.chunk;
		ft_sortnumber(&data);
		ft_lstclear(&data.stacka);
	}
}
