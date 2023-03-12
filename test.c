#include "push_swap.h"



int	main(int ac, char **av)
{
	t_data	data;
	char	**ab;
	int		i;
	int		b;
	int		l;
	int		t;
	int		*a;

	l = 0;
	if (ac < 2)
		return (0);
	if (ac > 2)
		data.count = ac - 1;
	else
	{
		ab = ft_split(av[1], ' ');
		i = 0;
		while (ab[i] != NULL)
		{
			ft_lstadd_back(&data.stacka, ft_lstnew(ft_atoi(ab[i])));
			i++;
		}
		data.count = i;
		// diyal 3 5dama
		// ft_sort_3number(&data);
		ft_sort_5number(&data);
		// while (data.stacka)
		// {
		// 	printf("%d\n",data.stacka->content);
		// 	data.stacka = data.stacka->next;
		// }
		
		// a = malloc(sizeof(int) * i);
		// i--;
		// while (i >= 0)
		// {
		// 	a[i] = ft_atoi(ab[i]);
		// 	i--;
		// }
		// i = 0;
		// while (i < data.count)
		// {
		// 	while (b + 1 < data.count)
		// 	{
		// 		if (a[i] >= a[b + 1])
		// 		{
		// 			// printf("NOT sorted");
		// 			if (data.count <= 3)
		// 				ft_sort_3number(&data);
		// 			else if (data.count <= 5)
		// 				ft_sort_5number(&data);
		// 			exit(1);
		// 		}
		// 		b++;
		// 	}
		// 	i++;
		// 	b = i;
		// }
	}

	// i = 0;
	// while (i < data.count)
	// {
	// 	b = data.stacka->content;
	// 	while (l + 1 < data.count)
	// 	{
	// 		t = data.stacka->next->content;
	// 		if (b >= t)
	// 		{
	// 			// printf("NOT sorted");
	// 			printf("%d", data.stacka->content);
	// 			printf("%d", data.stacka->next->content);
	// 			if (data.count <= 3)
	// 				ft_sort_3number(&data);
	// 			exit(1);
	// 		}
	// 		data.stacka->next;
	// 		l++;
	// 	}
	// 	i++;
	// 	l = i;
	// 	data.stacka = data.stacka->next;
	// }
	// puts("a");
	// if (data.count <= 3)
	// 	ft_sort_3number(&data);
	// else if (data.count <= 5)
	// 	ft_sort_5number(&data);
	// else if (data.count > 5)
	// 	ft_sort_extranumber(&data);
	// while (data.stacka)
	// {
	// 	printf("%d\n", data.stacka->content);
	// 	data.stacka = data.stacka->next;
	// }
}
