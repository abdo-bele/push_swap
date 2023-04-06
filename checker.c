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
	ft_putstr("error");
	exit(1);
}

int ft_is_sorted(t_data *data)
{
	t_list	*a;
	t_list	*b;

	a = data->stacka;
	b = data->stacka;
	while (a)
		{
			while (b->next)
			{
				if (a->content > b->next->content)
					return (0);
				b = b->next;
			}
			a = a->next;
			b = a;
		}
		return (1);
}

int	ft_check_operation(char *str, t_data *data)
{
	if(ft_strcmp(str, "pa"))
		return (pa(data), 1);
	else if(ft_strcmp(str, "pb"))
		return (pb(data), 1);
	else if(ft_strcmp(str, "ra"))
		return (ra(data), 1);
	else if(ft_strcmp(str, "rra"))
		return (rra(data), 1);
	else if(ft_strcmp(str, "sa"))
		return (sa(data), 1);
	else if(ft_strcmp(str, "sb"))
		return (sb(data), 1);
	else if(ft_strcmp(str, "rb"))
		return (rb(data), 1);
	else if(ft_strcmp(str, "rrb"))
		return (rrb(data), 1);
	else if(ft_strcmp(str, "rr"))
		return (rr(data), 1);
	else if(ft_strcmp(str, "ss"))
		return (ss(data), 1);
	else if(ft_strcmp(str, "rrr"))
		return (rrr(data), 1);
	else
		return (ft_putstr("Error"), 0);
}

int main(int ac, char **av)
{
        t_data	data;
    char	**ab;
    char	*al;
	int		i;
	char	*str;

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
		// free(ab);
		// t_list *d = data.stacka;
		// 				while (d)
		// 				{
		// 					printf("%d\n", d->content);
		// 					d = d->next;
		// 				}
		if(!ft_is_sorted(&data))
		{
			str = get_next_line(0);
			while(str)
			{	
				if(!ft_check_operation(str, &data))
				{
					ft_putstr("error");
					exit(1);
				}
				free(str);
				str = get_next_line(0);
			}
			
		}
		if (ft_is_sorted(&data))
		{
			ft_putstr("OK");
		}
		else
		{
			ft_putstr("KO");
			exit(1);
		}
    }
}