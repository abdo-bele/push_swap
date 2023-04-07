#include "push_swap.h"

void	ft_intindex(t_list *data)
{
	t_list	*h;

	h = data;
	while (h)
	{
		h->index = 0;
		h = h->next;
	}
}
