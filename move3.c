/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:35:32 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 15:35:43 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *data)
{
	rra(data, 0);
	rrb(data, 0);
	ft_putstr("rrr");
}

void	rr(t_data *data)
{
	ra(data, 0);
	rb(data, 0);
	ft_putstr("rr");
}

void	ss(t_data *data)
{
	sa(data, 0);
	sb(data, 0);
	ft_putstr("ss");
}
