/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:23:35 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 15:52:22 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **ab)
{
	int	i;

	i = 0;
	while (ab[i])
	{
		free(ab[i]);
		i++;
	}
	free(ab);
}
