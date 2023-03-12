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
	t_list	*test;
	t_list	*test1;

	data->counta = data->count;
	while (data->counta > 4)
	{
		ft_check_max(data);
		ft_sort_end_push(data);
	}
	ft_sort_3number(data);
	printf("%d\n", data->stacka->content);
	printf("%d\n", data->stacka->next->content);
	printf("%d\n", data->stacka->next->next->content);
	printf("%d\n", data->stackb->content);
	printf("%d", data->stackb->next->content);

}

void	ft_check_max(t_data *data)
{
	t_list	*a;

	data->max = data->stacka->content;
	a = data->stacka;
	data->counta = 0;
	while (a)
	{
		// printf("%d", data->max);
		if (a->content > data->max)
			data->max = a->content;
		a = a->next;
		data->counta++;
	}
}
