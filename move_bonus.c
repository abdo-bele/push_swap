#include "push_swap.h"

void	ra(t_data *data)
{
	t_list	*f;
	t_list	*r;
	t_list	*l;

	if (!data->stacka || !data->stacka->next)
		return ;
	r = data->stacka;
	f = data->stacka->next;
	l = data->stacka;
	l = ft_lstlast(l);
	r->next = NULL;
	l->next = r;
	data->stacka = f;
}

void	sa(t_data *data)
{
	int	a;

	if (!data->stacka || !data->stacka->next)
		return ;
	a = data->stacka->content;
	data->stacka->content = data->stacka->next->content;
	data->stacka->next->content = a;
}

void	rra(t_data *data)
{
	t_list	*f;
	t_list	*rr;
	t_list	*l;

	if (!data->stacka || !data->stacka->next)
		return ;
	f = data->stacka;
	l = data->stacka;
	while (l->next->next != NULL)
		l = l->next;
	rr = l->next;
	l->next = NULL;
	rr->next = f;
	data->stacka = rr;
}

void	pa(t_data *data)
{
	t_list	*a;
	t_list	*b;

	if (!data->stackb)
		return ;
	b = data->stackb->next;
	a = data->stackb;
	data->stackb = b;
	ft_lstadd_front(&data->stacka, a);
}

void	pb(t_data *data)
{
	t_list	*a;
	t_list	*b;

	if (!data->stacka)
		return ;
	a = data->stacka->next;
	b = data->stacka;
	data->stacka = a;
	ft_lstadd_front(&data->stackb, b);
}
