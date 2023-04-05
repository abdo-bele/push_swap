#include "push_swap.h"

void	ft_check(char *av)
{
	int i;

	// i = ft_strlen(av);
	i = 0;
	while (av[i])
	{
		if(av[i] != ' ')
			return ;
		i++;
	}
	printf("error");
	exit(1);
}

int main(int ac, char **av)
{
    t_data	data;
    char	**ab;
    char	*al;
	int		i;
	t_list	*a;
	t_list	*l;
	t_list	*f;
	t_list	*b;

	i = 1;
	data.count = 0;
	if (ac < 2)
		return (0);
	if (ac > 1)
	{
		al = malloc(1);
		al[0] = '\0';
		while(av[i])
		{
			ft_check(av[i]);
			al = ft_strjoin(al, av[i++]);
			al = ft_strjoin(al, " ");
		}
		ab = ft_split(al, ' ');
		free(al);
		i = 0;
		while (ab[i])
		{
			ft_lstadd_back(&data.stacka ,ft_lstnew(ft_atoi(ab[i])));
			data.count++;
			i++;
		}
		free(ab);
		a = data.stacka;
		b = data.stacka;
		l = data.stacka;
		f = data.stacka;
		i = 0;
		while (l)
		{
			while (f->next)
			{
				if (l->content == f->next->content)
				{
					printf("error");
					exit(1);
				}
				f = f->next;
			}
			l = l->next;
			f = l;
		}
		// t_list *h = data.stacka;
		// while (h)
		// {
		// 	printf("%d\n", h->content);
		// 	h = h->next;
		// }
		while (a)
		{
			while (b->next)
			{
				if (a->content > b->next->content)
				{
					if (data.count <= 3)
						ft_sort_3number(&data);
					else if (data.count <= 5)
						ft_sort_5number(&data);
					else if (data.count > 5)
						ft_sort_5number(&data);
					exit(0);
				}
				b = b->next;
			}
			a = a->next;
			b = a;
		}
	}
}





    // printf("\n");
//    t_list *d = data->stackb;
// 	while (d)
// 	{
// 		printf("%d\n", d->content);
// 		d = d->next;
// 	}
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