/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:31:44 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 07:35:20 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			count_lst(t_lst *a)
{
	int		i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int			calc_mediane(t_lst *a)
{
	int		*tab;
	int		count;
	int		res;

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

int			*lst_to_int(t_lst *a)
{
	int		*tab;
	int		i;

	i = count_lst(a);
	if (!(tab = ft_memalloc(sizeof(int) * i + 1)))
		return (NULL);
	i = -1;
	while (a != NULL)
	{
		tab[++i] = a->value;
		a = a->next;
	}
	return (tab);
}

void		free_lst(t_env *e)
{
	t_lst	*tmp;

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
