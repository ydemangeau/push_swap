#include "../include/push_swap.h"

void		ft_ra(t_env *e, int b)
{
	if (e->a != NULL && e->a->next != NULL)
		e->a = rotate(e->a);
	if (b == 1)
		ft_putendl("ra");
	e->coup++;
}

void		ft_rb(t_env *e, int b)
{
	if (e->b != NULL && e->b->next != NULL)
		e->b = rotate(e->b);
	if (b == 1)
		ft_putendl("rb");
	e->coup++;
}

void		ft_rra(t_env *e, int b)
{
	if (e->a != NULL && e->a->next != NULL)
		e->a = reverse_rotate(e->a);
	if (b == 1)
		ft_putendl("rra");
	e->coup++;
}

void		ft_rrb(t_env *e, int b)
{
	if (e->b != NULL && e->b->next != NULL)
		e->b = reverse_rotate(e->b);
	if (b == 1)
		ft_putendl("rrb");
	e->coup++;
}
