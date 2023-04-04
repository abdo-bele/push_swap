#include "push_swap.h"

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

	data->hold_first = data->stacka->content;
	data->hold_second = data->stacka->content;
	a = data->stacka;
	while (a)
	{
		if (a->content < data->hold_first)
			data->hold_first = a->content;
		a = a->next;
	}
	a = data->stacka;
	while (a)
	{
		if (a->content < data->hold_second && a->content != data->hold_first)
			data->hold_second = a->content;
		a = a->next;
	}
    ft_check_position(data);
    // printf("%d\n", data->hold_first);
    // printf("%d\n", data->hold_second);
    // printf("f%d\n", data->countpf);
    // printf("s%d\n", data->countps);
    // printf("%d\n", data->count);
    // printf("%d\n", data->counta);
}

void    ft_sort_100number(t_data *data)
{
    t_list *h;
    // int     index;

    ft_intindex(data->stacka);
    h = data->stacka;
    while (h && data->count > 0)
    {
        ft_checknumber(data);
        // t_list *d = data->stacka;
		// while (d)
		// {
		// 	printf("%d\n", d->content);
		// 	d = d->next;
		// }
        // printf("--a%d\n", data->hold_first);
        // printf("--b%d\n", data->hold_second);
        // printf("===f%d\n", data->countpf);
        // printf("===s%d\n", data->countps);
        if (data->countpf > data->countps)
        {
            // printf("bhabcha");
            while (h && data->countps > 0)
            {
                printf("ra\n");
                ra(data);
                data->countps--;
            }
            // break;
        }
        else if (data->countpf <= (data->count - (data->countps + 1)))
        {
            while (h && data->countpf > 0)
            {
                printf("ra\n");
                ra(data);
                data->countpf--;
            }
        }
        else if (data->countpf > (data->count - (data->countps + 1)))
        {
            if (data->countps < (data->count/2))
            {
                while (h && data->count - data->countps > 0)
                {
                    printf("ra\n");
                    ra(data);
                    data->countps++;
                }   
            }
            else if (data->countps > (data->count/2))
            {
                while (h && data->count - data->countps > 0)
                {
                    printf("rra\n");
                    rra(data);
                    data->countps++;
                } 
            }
        }
        printf("pb\n");
        pb(data);
        data->count--;
    }
}