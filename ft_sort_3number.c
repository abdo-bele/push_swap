#include "push_swap.h"

void	ft_sort_3number(t_data *data)
{
	int i = 0;

	if (data->stacka->content > data->stacka->next->content)
	{
	puts("b");
		printf("ra\n");
		// ra(data);
		ft_sort_3number(data);
	}
	if (data->stacka->content < data->stacka->next->content
		&& data->stacka->next->content > data->stacka->next->next->content)
	{
		printf("rra\n");
		// rra(data);
        // if (data->stacka->content < )
		ft_sort_3number(data);
	}
	if (data->stacka->content > data->stacka->next->content
		&& data->stacka->next->content < data->stacka->next->next->content)
	{
		printf("sa\n");
		// sa(data);
	}
    // printf("aaaa");
}
