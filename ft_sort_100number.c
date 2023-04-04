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
    t_list *d = data->stacka;
    while (d)
    {
		printf("%d--%d\n", d->content, d->index);
		d = d->next;
	}
        
    
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
    printf("--%d\n", data->hold_first);
    printf("--%d\n", data->hold_second);
    // printf("f%d\n", data->countpf); 
    // printf("s%d\n", data->countps);
    // printf("%d\n", data->count);
    // printf("%d\n", data->counta);
}

void    ft_sort_100number(t_data *data)
{
    t_list *h;
    int     index;

    ft_intindex(data->stacka);
    ft_indexstacka(data);
    t_list *d = data->stacka;
    while (d)
    {
		printf("%d--%d\n", d->content, d->index);
		d = d->next;
	}
    h = data->stacka;
    index = 19;
    while (h)
    {
        while (h && h->index > index)
        {
            printf("ra\n");
            ra(data);
        }
        if (h->index < index / 2)
        {
            printf("%d",h->index);
            printf("pb\n");
            puts("bbbbbb");
            pb(data);
        }
        else if(h->index > index / 2)
        {
            printf("pb\n");
            pb(data);
            puts("her");
            printf("rb\n");
            rb(data);
        }
        if (ft_lstsize(data->stackb) == index)
            index = index + 20;
        puts("aaaaaa");
    }
    // t_list *d = data->stacka;
	// while (d)
	// {
	// 	printf("%d\n", d->content);
	// 	d = d->next;
	// }
    // data->counta = data->count;
    // while (h && data->count > 0)
    // {
    //     ft_checknumber(data);
    //     // t_list *d = data->stacka;
	// 	// while (d)
	// 	// {
	// 	// 	printf("%d\n", d->content);
	// 	// 	d = d->next;
	// 	// }
    //     // printf("--a%d\n", data->hold_first);
    //     // printf("--b%d\n", data->hold_second);
    //     // printf("===f%d\n", data->countpf);
    //     // printf("===s%d\n", data->countps);
    //     if (data->countpf > data->countps)
    //     {
    //         // printf("bhabcha");
    //         while (h && data->countps > 0)
    //         {
    //             printf("ra\n");
    //             ra(data);
    //             data->countps--;
    //         }
    //         // break;
    //     }
    //     else if (data->countpf <= (data->count - (data->countps + 1)))
    //     {
    //         while (h && data->countpf > 0)
    //         {
    //             printf("ra\n");
    //             ra(data);
    //             data->countpf--;
    //         }
    //     }
    //     else if (data->countpf > (data->count - (data->countps + 1)))
    //     {
    //         if (data->countps < (data->count/2))
    //         {
    //             while (h && data->count - data->countps > 0)
    //             {
    //                 printf("ra\n");
    //                 ra(data);
    //                 data->countps++;
    //             }   
    //         }
    //         else if (data->countps > (data->count/2))
    //         {
    //             while (h && data->count - data->countps > 0)
    //             {
    //                 printf("rra\n");
    //                 rra(data);
    //                 data->countps++;
    //             } 
    //         }
    //     }
    //     printf("pb\n");
    //     pb(data);
    //     data->count--;
    // }
    // while (data->stackb)
    // {
    // ft_check_maxb(data);
    // t_list	*test;
	// int		i;
	// int		a;

	// test = data->stackb;
	// i = 0;
	// while (test)
	// {
    //     // printf("----------%d\n", data->max);
	// 	if (test->content == data->max)
	// 	{
    //         a = ft_lstsize(test);
    //         // printf("aaaaaa%d\n",a);
    //         // printf("iiiiii%d\n",i);
    //         if (i <= (a / 2))
    //         {
	// 		while (i > 0)
	// 		{
	// 			printf("rb\n");
	// 			rb(data);
	// 			i--;
	// 		}
    //         }
    //         else if (i > (a / 2))
    //         {
    //             while (a - i > 0)
    //             {
    //                 printf("rrb\n");
	// 			    rrb(data);
	// 			    i--;
    //             } 
    //         }
	// 	}
	// 	test = test->next;
	// 	i++;
	// }
	// printf("pa\n");
	// pa(data);
    // }
    // t_list *d = data->stacka;
	// while (d)
	// {
	// 	printf("%d\n", d->content);
	// 	d = d->next;
	// }
}