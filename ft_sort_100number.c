/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:56 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/10 15:25:43 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_indexstacka(t_data *data)
{
	t_list	*tmp;
	t_list	*tmp1;
	int		min;
	int		i;

	tmp = data->stacka;
	tmp1 = data->stacka;
	min = 0;
	i = ft_lstsize(tmp);
	while (i--)
	{
		tmp = data->stacka;
		min = 0;
		while (tmp)
		{
			if (tmp1->content > tmp->content)
				min++;
			tmp = tmp->next;
		}
		tmp1->index = min;
		tmp1 = tmp1->next;
	}
}

void	get_chunk(t_data *data)
{
	data->count = ft_lstsize(data->stacka);
	if (data->count <= 20)
		data->chunk = data->count / 2;
	else if (data->count <= 200)
		data->chunk = data->count / 5;
	else if (data->count <= 500)
		data->chunk = data->count / 9;
	else
		data->chunk = data->count / 15;
}

void	ft_check_maxb(t_data *data)
{
	t_list	*a;

	data->max = 0;
	data->hold_second = 0;
	a = data->stackb;
	while (a)
	{
		if (a->index > data->max)
			data->max = a->index;
		a = a->next;
	}
	a = data->stackb;
	while (a)
	{
		if (a->index > data->hold_second && a->index != data->max)
			data->hold_second = a->index;
		a = a->next;
	}
}

void	ft_sort_100number(t_data *data)
{
	while (data->stacka->index >= data->index)
	{
		ra(data, 1);
	}
	if (data->stacka->index <= data->index - (data->chunk / 2))
	{
		pb(data, 1);
	}
	else if (data->stacka->index > data->index - (data->chunk / 2))
	{
		pb(data, 1);
		if (data->stacka && data->stacka->index >= data->index)
			rr(data);
		else
			rb(data, 1);
	}
	if (ft_lstsize(data->stackb) == data->index)
		data->index = data->index + data->chunk;
}
