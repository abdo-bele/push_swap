/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:35:32 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/08 18:35:33 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
	ft_putstr("rrr");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	ft_putstr("rr");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_putstr("ss");
}
