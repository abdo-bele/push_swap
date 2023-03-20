#include "push_swap.h"

void	ft_sort_3number(t_data *data)
{
	if (data->count == 2)
	{
		printf("sa\n");
		sa(data);
	}
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content
		&& data->stacka->content > data->stacka->next->next->content)
	{
	
		printf("ra\n");
		ra(data);
	}
	else if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content
		&& data->stacka->content < data->stacka->next->next->content)
	{
		printf("rra\n");
		printf("sa\n");
		rra(data);
		sa(data);
	}
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content)
	{
		printf("sa\n");
		sa(data);
	}
	else if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
	{
		printf("rra\n");
		rra(data);
	}
	else if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
	{
		printf("ra\nsa\n");
		ra(data);
		sa(data);
	}
	// t_list *h = data->stacka;
	// while (h)
	// {
	// 	printf("%d ", h->content);
	// 	h = h->next;
	// }
}
