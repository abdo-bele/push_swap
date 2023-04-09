/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_100number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:56 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 18:12:43 by aarchtou         ###   ########.fr       */
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
		data->chunk = data->count / 8;
	else
		data->chunk = data->count / 15;
}

void	ft_check_maxb(t_data *data)
{
	t_list	*a;

	data->max = data->stackb->content;
	a = data->stackb;
	while (a)
	{
		if (a->content > data->max)
			data->max = a->content;
		a = a->next;
	}
}

void	ft_get_first_and_second(t_data *data)
{
	t_list *a;

	a= data->stacka;
	data->hold_first = data->stacka->index;
	data->hold_second = data->stacka->index;
	while (a)
	{
		if (a->index < data->hold_first)
			data->hold_first = a->index;
		a = a->next;
	}
	a =  data->stacka;
	while (a)
	{
		if (a->index < data->hold_second && a->index != data->hold_first)
			data->hold_second = a->index;
		a = a->next;
	}
	a =  data->stacka;
	while (a && a->index != data->hold_first)
	{
		data->countpf++;
		a = a->next;
	}
	a =  data->stacka;
	while (a && a->index != data->hold_second)
	{
		data->countps++;
		a = a->next;
	}
		// printf("%d\n", data->hold_first);
		// printf("%d\n", data->hold_second);
		// printf("%d\n", data->countpf);
		// printf("%d\n", data->countps);
	// exit(0);
}

void	ft_sort_100number(t_data *data)
{
	ft_get_first_and_second(data);
	while (data->stacka->index >= data->index)
	{
		if (data->countpf < data->countps && data->countpf < (ft_lstsize(data->stacka) / 2))
			ra(data, 1);
		else if (data->countpf < data->countps && data->countpf > (ft_lstsize(data->stacka) / 2))
			rra(data, 1);
		if (data->countpf > data->countps && data->countps < (ft_lstsize(data->stacka) / 2))
			ra(data, 1);
		else if (data->countpf > data->countps && data->countps > (ft_lstsize(data->stacka) / 2))
			rra(data, 1);
	}
	// while (data->stacka->index >= data->index)
	// {
	// 	ra(data, 1);
	// }
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
