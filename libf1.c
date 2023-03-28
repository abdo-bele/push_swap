#include "push_swap.h"

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(int content)
{
	t_list	*a;

	a = (void *)malloc(sizeof(t_list));
	if (a == 0)
		return (0);
	a->content = content;
	a->next = 0;
	return (a);
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
	if (!str[i] && (str[i] < '0' || str[i] > '9'))
		exit(1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		exit(1);
	return (r * b);
}

static int	chek_word(char const *a, char c)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (a[i])
	{
		while (a[i] && a[i] == c)
			i++;
		if (a[i] == 0)
			break ;
		t++;
		while (a[i] && a[i] != c)
			i++;
	}
	return (t);
}

void	ft_free_all(char	**strings, int a)
{
	while (a >= 0)
	{
		free(strings[a]);
		a--;
	}
	return ;
}

char	**ft_chek(char const *s, char c, char **strings, int words_count)
{
	char	*sub;
	int		index;
	int		a;
	int		l;

	index = 0;
	a = 0;
	while (a < words_count)
	{
		while (s[index] && s[index] == c)
			index++;
		l = 0;
		while (s[l + index] && s[l + index] != c)
			l++;
		sub = (char *)malloc(sizeof(char) * (l + 1));
		if (!sub)
			ft_free_all(strings, a);
		l = 0;
		while (s[index] && s[index] != c)
			sub[l++] = s[index++];
		sub[l] = 0;
		strings[a++] = sub;
	}
	strings[a] = 0;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		words_count;

	if (s == 0)
		return (0);
	words_count = chek_word(s, c);
	strings = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (strings == 0)
		return (0);
	ft_chek(s, c, strings, words_count);
	return (strings);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		l;
	char	*ptr;

	i = 0;
	l = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s2)
		return (free(s1), NULL);
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (ptr == NULL)
		return (NULL);
	while (s1[i])
		ptr[l++] = s1[i++];
	i = 0;
	while (s2[i])
		ptr[l++] = s2[i++];
	ptr[l] = '\0';
	free(s1);
	return (ptr);
}
