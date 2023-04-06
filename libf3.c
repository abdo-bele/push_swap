#include "push_swap.h"

// size_t	ft_strlen(const char *c)
// {
// 	int	i;

// 	i = 0;
// 	if (!c)
// 		return (0);
// 	while (c[i])
// 		i++;
// 	return (i);
// }

int ft_atoi2(const char *str, int i, int b)
{
    long    r;

    r = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] || (r > 2147483647 && b == 1) || (r > 2147483648 && b == -1))
	{
		ft_putstr("error");
		exit(1);
	}
	return (r);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		b;
	long	r;

	i = 0;
	r = 0;
	b = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			b = b * (-1);
		i++;
	}
    r = ft_atoi2(str, i , b);
	return (r * b);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(const char *a, const char *b)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			i;

	i = 0;
	s1 = (unsigned char *)a;
	s2 = (unsigned char *)b;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if ((s1[i] - s2[i]) == 0)
		return (0);
	else if ((s1[i] - s2[i]) > 0)
		return (1);
	else
		return (-1);
}
