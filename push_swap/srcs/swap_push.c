#include "../include/push_swap.h"

void		ft_sa(t_env *e, int b)
{
	if (e->a != NULL && e->a->next != NULL)
		e->a = swap(e->a, e->a->next);
	if (b == 1)
		ft_putendl("sa");
	e->coup++;
}

void		ft_sb(t_env *e, int b)
{
	if (e->b != NULL && e->b->next != NULL)
		e->b = swap(e->b, e->b->next);
	if (b == 1)
		ft_putendl("sb");
	e->coup++;
}

void		ft_pb(t_env *e, int b)
{
	if (e->a != NULL)
		e->a = push(e->a, &e->b);
	if (b == 1)
		ft_putendl("pb");
	e->coup++;
}

void		ft_pa(t_env *e, int b)
{
	if (e->b != NULL)
		e->b = push(e->b, &e->a);
	if (b == 1)
		ft_putendl("pa");
	e->coup++;
}
