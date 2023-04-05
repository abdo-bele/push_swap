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

void    ft_check_position(t_data *data)
{
    t_list	*a;

	a = data->stacka;
    while (a)
	{
		if (a->content == data->hold_first)
			break;
		a = a->next;
        data->countpf++;
	}
	a = data->stacka;
    while (a)
	{
		if (a->content == data->hold_second)
			break;
		a = a->next;
        data->countps++;
	}
}

void	ft_checknumber(t_data *data)
{
	t_list	*a;

    data->countpf = 0;
    data->countps = 0;
    data->countpf = 0;
    data->countps = 0;
    data->hold_first = 0;
    data->hold_second = 0;

	data->hold_first = data->stacka->index;
	data->hold_second = data->stacka->index;
	a = data->stacka;
	while (a)
	{
		if (a->index < data->hold_first)
			data->hold_first = a->index;
		a = a->next;
	}
	a = data->stacka;
	while (a)
	{
		if (a->index < data->hold_second && a->index > data->hold_first)
			data->hold_second = a->index;
		a = a->next;
	}
    ft_check_position(data);
    // printf("--%d\n", data->hold_first);
    // printf("--%d\n", data->hold_second);
    // printf("f%d\n", data->countpf); 
    // printf("s%d\n", data->countps);
    // printf("%d\n", data->count);
    // printf("%d\n", data->counta);
}

void    ft_sort_100number(t_data *data)
{
        while (data->stacka->index >= data->index)
        {
            printf("ra\n");
            ra(data);
        }
        if (data->stacka->index <= data->index - (data->chunk / 2))
        {
            printf("pb\n");
            pb(data);
        }
        else if(data->stacka->index > data->index  - (data->chunk / 2))
        {
            printf("pb\n");
            pb(data);
            printf("rb\n");
            rb(data);
        }
        if (ft_lstsize(data->stackb) == data->index)
            data->index = data->index + data->chunk;

}