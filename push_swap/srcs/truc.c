#include "../include/push_swap.h"

int		count_lst(t_lst *a)
{
	int i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}


int		calc_mediane(t_lst *a)
{
	int		*tab;
	int		count;
	int	res;
	
	count = count_lst(a);
	tab = lst_to_int(a);
	quicksort(tab, count);
	if (count_lst(a) > 100)
		count /= 7;
	else
		count /= 2;
	res = tab[count];
	free(tab);
	return (res);
}

void	display(t_env *e)
{
	t_lst	*tmpa;
	t_lst	*tmpb;
	int i;

	i = -1;
	tmpa = e->a;
	tmpb = e->b;
	while (tmpa != NULL)
	{
			ft_putnbr(tmpa->value);
			tmpa = tmpa->next;
			ft_putstr("   ");
			if (tmpb != NULL)
			{
				ft_putnbr(tmpb->value);
				tmpb = tmpb->next;
				ft_putchar('\n');
			}
			else 
				ft_putchar('\n');
	}
	while (tmpb != NULL)
	{
		ft_putstr("    ");
		ft_putnbr(tmpb->value);
		tmpb = tmpb->next;
		ft_putchar('\n');
	}
		ft_putchar('\n');
}

int		*lst_to_int(t_lst *a)
{
	int		*tab;
	int i;
	
	i = count_lst(a);
	if(!(tab = ft_memalloc(sizeof(int) * i + 1)))
		return (NULL);
	i = -1;
	while (a != NULL)
	{
		tab[++i] = a->value;
		a = a->next;
	}
	return (tab);
}

void	free_lst(t_env *e)
{
	t_lst *tmp;

	while (e->a != NULL)
	{
		tmp = e->a->next;
		free(e->a);
		e->a = tmp;
	}
	while (e->b != NULL)
	{
		tmp = e->b->next;
		free(e->b);
		e->b = tmp;
	}
}
