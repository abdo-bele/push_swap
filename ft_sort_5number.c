/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_5number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:53 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/08 18:34:54 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_end_push(t_data *data)
{
	t_list	*test;
	int		i;

	test = data->stacka;
	i = 0;
	while (test)
	{
		if (test->content == data->max)
		{
			if (i <= 2)
			{
				while (i-- > 0)
					ra(data);
			}
			else
			{
				while (i++ < data->counta)
					rra(data);
			}
		}
		test = test->next;
		i++;
	}
	pb(data);
}

void	ft_sort_5number(t_data *data)
{
	data->counta = data->count;
	while (data->counta >= 4)
	{
		ft_check_max(data);
		ft_sort_end_push(data);
		data->counta--;
	}
	ft_sort_3number(data);
	while (data->stackb)
	{
		pa(data);
		ra(data);
	}
}

void	ft_check_max(t_data *data)
{
	t_list	*a;

	data->max = data->stacka->content;
	a = data->stacka;
	while (a)
	{
		if (a->content > data->max)
			data->max = a->content;
		a = a->next;
	}
}
