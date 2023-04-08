/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_3number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:50 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/08 18:34:51 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3number(t_data *data)
{
	if (data->count == 2)
		sa(data);
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content
		&& data->stacka->content > data->stacka->next->next->content)
		ra(data);
	else if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content
		&& data->stacka->content < data->stacka->next->next->content)
	{
		rra(data);
		sa(data);
	}
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content)
		sa(data);
	else if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
		rra(data);
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
	{
		ra(data);
		sa(data);
	}
}
