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

void	ft_sort_end_pusha(t_data *data)
{
	t_list	*test;
	int		i;

	test = data->stackb;
	i = 0;
	data->countb = ft_lstsize(data->stackb);
	while (test)
	{
		if (test->content == data->max)
		{
			if (i <= data->countb / 2)
			{
			while (i > 0)
			{
				printf("rb\n");
				rb(data);
				i--;
			}
			}
			if (i > data->countb / 2)
			{
			while (data->countb - i > 0)
			{
				printf("rrb\n");
				rrb(data);
				i++;
			}
			}
		}
		test = test->next;
		i++;
	}
	printf("pa\n");
	pa(data);
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
	data.stacka = NULL;
	data.stackb = NULL;
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
		ft_intindex(data.stacka);
    	ft_indexstacka(&data);
    	get_chunk(&data);
		data.index = data.chunk;
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
					{	
						while (data.stacka)
						{
							if (data.index > data.count)
								data.index = data.count;
							ft_sort_100number(&data);
						}
						while (data.stackb)
						{
							ft_check_maxb(&data);
							ft_sort_end_pusha(&data);
						}
						// t_list *d = data.stacka;
						// while (d)
						// {
						// 	printf("%d\n", d->content);
						// 	d = d->next;
						// }
						
					}
					exit(0);
				}
				b = b->next;
			}
			a = a->next;
			b = a;
		}
	}
}
 