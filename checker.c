/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:40 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/09 15:20:14 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int	ft_is_sorted(t_data *data)
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
				return (0);
			b = b->next;
		}
		a = a->next;
		b = a;
	}
	return (1);
}

int	ft_check_operation(char *str, t_data *data)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		return (pa(data), 1);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		return (pb(data), 1);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		return (ra(data), 1);
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		return (rra(data), 1);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		return (sa(data), 1);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		return (sb(data), 1);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		return (rb(data), 1);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		return (rrb(data), 1);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		return (rr(data), 1);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		return (ss(data), 1);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
		return (rrr(data), 1);
	else
		return (ft_putstr("Error"), 0);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	*str;

	data.stacka = NULL;
	data.stackb = NULL;
	data.count = 0;
	if (ac < 2)
		return (ft_putstr("Error"), 1);
	if (ac > 1)
	{
		ft_get_stacka(&data, av);
		ft_chek_dup(&data);
		str = get_next_line(0);
		while (str)
		{
			if (!ft_check_operation(str, &data))
				exit(1);
			free(str);
			str = get_next_line(0);
		}
		if (ft_is_sorted(&data) && !data.stackb)
			return (ft_lstclear(&data.stacka), ft_putstr("OK"), 0);
		else
			return (ft_putstr("KO"), ft_lstclear(&data.stacka), exit(1), 1);
	}
}
