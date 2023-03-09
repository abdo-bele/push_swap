#include "push_swap.h"

int	main(int ac, char **av)
{
	char **ab;
	int i = 0;
	int *a;
	int b = 0;

	if (ac == 1)
		return (0);
	ab = ft_split(av[1], ' ');
	while (ab[i] != NULL)
		i++;
	a = malloc(sizeof(int) * i);
	int c = i;
	i--;
	while (i >= 0)
	{
		a[i] = ft_atoi(ab[i]);
		i--;
	}
	i = 0;
	while (i < c)
	{
		while (b + 1 < c)
		{
			if (a[i] >= a[b+1])
			{
				printf("NOT sorted");
				return (0);
			}
			b++;
		}
		i++;
		b = i;
	}
}
