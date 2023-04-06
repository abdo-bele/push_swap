#include "push_swap.h"

void	rb(t_data *data)
{
	t_list	*f;
	t_list	*r;
	t_list	*l;

	if (!data->stackb || !data->stackb->next)
		return ;
	r = data->stackb;
	f = data->stackb->next;
	l = data->stackb;
	l = ft_lstlast(l);
	r->next = NULL;
	l->next = r;
	data->stackb = f;
	ft_putstr("rb");
}

void	sb(t_data *data)
{
	int	a;

	if (!data->stackb || !data->stackb->next)
		return ;
	a = data->stackb->content;
	data->stackb->content = data->stackb->next->content;
	data->stackb->next->content = a;
	ft_putstr("sb");
}

void	rrb(t_data *data)
{
	t_list	*f;
	t_list	*rr;
	t_list	*l;

	if (!data->stackb || !data->stackb->next)
		return ;
	f = data->stackb;
	l = data->stackb;
	while (l->next->next != NULL)
		l = l->next;
	rr = l->next;
	l->next = NULL;
	rr->next = f;
	data->stackb = rr;
	ft_putstr("rrb");
}

void	rrr(t_data *data)
{
	rra(data);
	rrb(data);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}