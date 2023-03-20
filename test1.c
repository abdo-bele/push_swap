#include "push_swap.h"

int main(int ac, char **av)
{
    t_data	data;
    char	**ab;
	int		i;
	t_list	*a;
	t_list	*l;
	t_list	*f;
	t_list	*b;

	i = 1;
	if (ac < 2)
		return (0);
	if (ac > 2)
	{
		data.count = ac - 1;
		while (av[i])
		{
				ft_lstadd_back(&data.stacka ,ft_lstnew(ft_atoi(av[i])));
				i++;
		}
	}
	else
	{
		i = 0;
		ab = ft_split(av[1], ' ');
		while (ab[i])
		{

				ft_lstadd_back(&data.stacka ,ft_lstnew(ft_atoi(ab[i])));
				i++;
		}
		data.count = i;
	}
	
	if (ac > 1)
	{
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
					exit(1);
				f = f->next;
			}
			l = l->next;
			f = l;
		}
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
					// t_list *h = data.stacka;
					// while (h)
					// {
					// 	printf("%d ", h->content);
					// 	h = h->next;
					// }
					exit(0);
				}
				b = b->next;
			}
			a = a->next;
			b = a;
		}
	}
}