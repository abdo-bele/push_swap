/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:35:06 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 15:23:57 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi2(const char *str, int i, int b)
{
	long	r;

	r = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] || (r > 2147483647 && b == 1) || (r > 2147483648 && b == -1))
	{
		ft_putstr("error");
		exit(1);
	}
	return (r);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		b;
	long	r;

	i = 0;
	r = 0;
	b = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b = b * (-1);
		i++;
	}
	r = ft_atoi2(str, i, b);
	return (r * b);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;

	if (lst == 0)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = temp;
	}
}

void	ft_lstdelone(t_list *lst)
{
	if (lst == 0)
		return ;
	free (lst);
}
