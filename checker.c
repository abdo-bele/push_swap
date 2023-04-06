#include "push_swap.h"
#include <string.h>

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
	if(ft_strncmp(str, "pa", 2) == 0)
		return (pa(data), 1);
	else if(ft_strncmp(str, "pb", 2) == 0)
		return (pb(data), 1);
	else if(ft_strncmp(str, "ra", 2) == 0)
		return (ra(data), 1);
	else if(ft_strncmp(str, "rra", 3) == 0)
		return (rra(data), 1);
	else if(ft_strncmp(str, "sa", 2) == 0)
		return (sa(data), 1);
	else if(ft_strncmp(str, "sb", 2) == 0)
		return (sb(data), 1);
	else if(ft_strncmp(str, "rb", 2) == 0)
		return (rb(data), 1);
	else if(ft_strncmp(str, "rrb", 3) == 0)
		return (rrb(data), 1);
	else if(ft_strncmp(str, "rr", 2) == 0)
		return (rr(data), 1);
	else if(ft_strncmp(str, "ss", 2) == 0)
		return (ss(data), 1);
	else if(ft_strncmp(str, "rrr", 3) == 0)
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
		free(ab);
			str = get_next_line(0);
			while(str)
			{
				if(!ft_check_operation(str, &data))
					exit(1);
				free(str);
				str = get_next_line(0);
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