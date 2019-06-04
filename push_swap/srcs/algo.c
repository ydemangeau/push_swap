/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:20:07 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 07:24:03 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		tri_a(t_env *e)
{
	t_lst	*tmp;

	while (is_sort(e->a) != 1)
	{
		tmp = e->a->next;
		if (tmp->value > tmp->next->value)
			ft_rra(e, 1);
		else if (tmp->value < e->a->value)
			ft_sa(e, 1);
	}
}

void		algo(t_env *e)
{
	t_lst	*tmp;
	int		min;
	int		max;
	int		pos;

	tmp = e->b;
	while (e->b != NULL)
	{
		min = found_min(e->b);
		max = found_max(e->b);
		pos = count_i(e->b, max);
		if (e->b->value == max || e->b->value == min)
		{
			ft_pa(e, 1);
			if (e->a->value == min)
				ft_ra(e, 1);
		}
		else if (pos > (count_lst(e->b) / 2))
			ft_rrb(e, 1);
		else
			ft_rb(e, 1);
	}
	while (e->a->value != found_min(e->a))
		ft_rra(e, 1);
}

int			check_med(t_lst *a, int med)
{
	t_lst	*tmp;

	tmp = a;
	while (tmp != NULL)
	{
		if (count_lst(a) == 3)
			break ;
		if (tmp->value < med)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void		split(t_env *e)
{
	t_lst	*tmp;
	int		med;

	tmp = e->a;
	med = calc_mediane(e->a);
	while (check_med(e->a, med))
	{
		if (e->a->value < med)
			ft_pb(e, 1);
		else
			ft_ra(e, 1);
		if (e->b && e->b->value < calc_mediane(e->b))
			ft_rb(e, 1);
	}
}

void		algo2(t_env *e)
{
	
	if (count_lst(e->a) == 2)
	{
		if (e->a->value > e->a->next->value)
			ft_sa(e, 1);
		return ;
	}
	if (count_lst(e->a) == 4)
	{
		while (e->a->value != found_min(e->a))
			ft_ra(e, 1);
	}
	while (count_lst(e->a) > 3)
		split(e);
	tri_a(e);
	algo(e);
}
