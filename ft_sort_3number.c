/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:50 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 15:32:30 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3number(t_data *data)
{
	if (data->count == 2)
		sa(data, 1);
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content
		&& data->stacka->content > data->stacka->next->next->content)
		ra(data, 1);
	else if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content
		&& data->stacka->content < data->stacka->next->next->content)
	{
		rra(data, 1);
		sa(data, 1);
	}
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content)
		sa(data, 1);
	else if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
		rra(data, 1);
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
	{
		ra(data, 1);
		sa(data, 1);
	}
}
