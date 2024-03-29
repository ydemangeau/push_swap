/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:29:03 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 07:29:05 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_ss(t_env *e, int b)
{
	ft_sa(e, 0);
	ft_sb(e, 0);
	if (b == 1)
		ft_putendl("ss");
	e->coup--;
}

void	ft_rr(t_env *e, int b)
{
	ft_ra(e, 0);
	ft_rb(e, 0);
	if (b == 1)
		ft_putendl("rr");
	e->coup--;
}

void	ft_rrr(t_env *e, int b)
{
	ft_rra(e, 0);
	ft_rrb(e, 0);
	if (b == 1)
		ft_putendl("rrr");
	e->coup--;
}
