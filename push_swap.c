/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarchtou <aarchtou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:34:28 by aarchtou          #+#    #+#             */
/*   Updated: 2023/04/10 02:44:58 by aarchtou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort_end_pusha(t_data *data, int push)
{
	t_list	*test;
	int		i;

	test = data->stackb;
	i = 0;
	data->countb = ft_lstsize(data->stackb);
	while (test)
	{
		if (test->content == push)
		{
			if (i <= data->countb / 2)
			{
				while (i-- > 0)
					rb(data, 1);
			}
			else if (i > data->countb / 2)
			{
				while (data->countb - i++ > 0)
					rrb(data, 1);
			}
		}
		test = test->next;
		i++;
	}
	pa(data, 1);
}

int ft_chek_drist(t_data *data, int l, int i)
{
	t_list *a = data->stackb;

	while (a)
	{
		if (a->content == data->max)
			break;
		a = a->next;
		data->countpf++;
	}
	a = data->stackb;
	while (a)
	{
		if (a->content == data->hold_second)
			break;
		a = a->next;
		data->countps++;
	}
	// printf("--%d\n", data->max);
	// printf("--%d\n", data->hold_second);
	// t_list *u =data->stackb;
			
	// 		while (u)
	// 		{
	// 			printf("%d\n", u->content);
	// 			u= u->next;
	// 		}
	if (l == 0 && i == 1)
	{
		// puts("lllllllllllll");
		ft_sort_end_pusha(data, data->max);
		return (0);
	}
	if (data->countpf < (ft_lstsize(data->stackb) / 2) && data->countps < (ft_lstsize(data->stackb) / 2))
	{
		if (data->countpf < data->countps)
			ft_sort_end_pusha(data, data->max);
		else
		{
			ft_sort_end_pusha(data, data->hold_second);
			return (1);
		}
	}
	else if (data->countpf > (ft_lstsize(data->stackb) / 2) && data->countps > (ft_lstsize(data->stackb) / 2))
	{
		if (data->countpf > data->countps)
			ft_sort_end_pusha(data, data->max);
		else
		{
			ft_sort_end_pusha(data, data->hold_second);
			return (1);
		}
	}
	else
	{
		if (data->countpf > (ft_lstsize(data->stackb) - data->countps))
			ft_sort_end_pusha(data, data->max);
		else
		{
			ft_sort_end_pusha(data, data->hold_second);
			return (1);
		}
	}
	
	return(0);
}

void	ft_sort(t_data *data)
{
	int i = 2;
	int a = 0;
	if (data->count <= 3)
		ft_sort_3number(data);
	else if (data->count <= 5)
	{
		ft_sort_5number(data);
	}
	else if (data->count > 5)
	{
		while (data->stacka)
		{
			if (data->index > data->count)
				data->index = data->count;
			ft_sort_100number(data);
		}
		while (data->stackb)
		{
			while (i-- > 0 && data->stackb)
			{
				data->countb = ft_lstsize(data->stackb);
				ft_check_maxb(data);
				a = a + ft_chek_drist(data, a, i);
				if (a == 1 && i == 0)
				{
					sa(data, 1);
				}
			}
			a = 0;
			i = 2;
			// ft_sort_end_pusha(data);
		}
			// t_list *u =data->stacka;
			
			// while (u)
			// {
			// 	printf("%d\n", u->content);
			// 	u= u->next;
			// }
			
	}
}

void	ft_sortnumber(t_data *data)
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
			{
				ft_sort(data);
				return ;
			}
			b = b->next;
		}
		a = a->next;
		b = a;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	data.stacka = NULL;
	data.stackb = NULL;
	data.count = 0;
	if (ac < 2)
		return (0);
	if (ac > 1)
	{
		ft_get_stacka(&data, av);
		ft_chek_dup(&data);
		ft_intindex(data.stacka);
		ft_indexstacka(&data);
		get_chunk(&data);
		data.index = data.chunk;
		ft_sortnumber(&data);
		ft_lstclear(&data.stacka);
	}
}
