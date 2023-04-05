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
