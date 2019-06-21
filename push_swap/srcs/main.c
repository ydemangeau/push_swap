/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:28:32 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/21 16:15:40 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		display2(t_env *e)
{
	t_lst	*tmpa;
	t_lst	*tmpb;
	int		i;

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

int		die(t_env *e, char *reason)
{
	ft_putendl(reason);
	del_lst(&e->a);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env		e;
	int i;

	i = -1;
	if (argc == 1)
		return (0);
	if ((e.tab = check_error(argc, argv)) == NULL)
		return (die(&e, "Error"));
	display(e.tab);
	if (!(e.a = get_list(e.tab)))
		return (die(&e, "Error"));
	free_tab(e.tab);
	e.b = NULL;
	e.coup = 0;
	if (check_double(e.a) == -1)
		return (die(&e, "Error"));
	if (is_sort(e.a) == 1)
		return(die(&e, ""));
	algo2(&e);
	//display2(&e);
	del_lst(&e.a);
	
	return (0);
}
