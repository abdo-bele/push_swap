#include "push_swap.h"

void    ft_indexstacka(t_data *data)
{
    t_list  *tmp;
    t_list  *tmp1;
    int     min;
    int     i;

    tmp = data->stacka;
    tmp1 = data->stacka;
    min = 0;
    i = ft_lstsize(tmp);
    while (i--)
    {
        tmp = data->stacka;
        min = 0;
        while (tmp)
        {
            if(tmp1->content > tmp->content)
                min++;
            tmp = tmp->next;
        }
        tmp1->index = min;
        tmp1 = tmp1->next;
    }
}

void    get_chunk(t_data *data)
{

	data->count = ft_lstsize(data->stacka);
	if (data->count <= 20)
		data->chunk = data->count / 2;
	else if (data->count <= 200)
		data->chunk = data->count / 5;
	else if (data->count <= 500)
		data->chunk = data->count / 8;
	else
		data->chunk = data->count / 15;
}

void	ft_check_maxb(t_data *data)
{
	t_list	*a;

	data->max = data->stackb->content;
	a = data->stackb;
	while (a)
	{
		if (a->content > data->max)
			data->max = a->content;
		a = a->next;
	}
}

void    ft_sort_100number(t_data *data)
{
        while (data->stacka->index >= data->index)
        {
            ra(data);
        }
        if (data->stacka->index <= data->index - (data->chunk / 2))
        {
            pb(data);
        }
        else if(data->stacka->index > data->index  - (data->chunk / 2))
        {
            pb(data);
            rb(data);
        }
        if (ft_lstsize(data->stackb) == data->index)
            data->index = data->index + data->chunk;

}