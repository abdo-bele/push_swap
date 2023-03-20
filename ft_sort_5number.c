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
			while (i > 0)
			{
				printf("ra\n");
				ra(data);
				i--;
			}
		}
		test = test->next;
		i++;
	}
	printf("pb\n");
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
	while(data->stackb)
	{
		printf("pa\n");
		printf("ra\n");
		pa(data);
		ra(data);
	}
// 	printf("%d\n", data->stacka->content);
// 	printf("%d\n", data->stacka->next->content);
// 	printf("%d\n", data->stacka->next->next->content);
// 	printf("%d\n", data->stacka->next->next->next->content);
// 	printf("%d\n", data->stacka->next->next->next->next->content);
// 	printf("%d\n", data->stacka->next->next->next->next->next->content);
// 	printf("%d\n", data->stacka->next->next->next->next->next->next->content);
 	// printf("%d\n", data->stackb->content);
	// t_list *h = data->stacka;
	// while (h)
	// {
	// 	printf("%d ", h->content);
	// 	h = h->next;
	// }
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
