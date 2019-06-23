/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:28:32 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/23 16:06:49 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			die(t_env *e, char *reason)
{
	ft_putstr(reason);
	del_lst(&e->a);
	return (-1);
}

int			main(int argc, char **argv)
{
	t_env		e;
	int			i;

	i = -1;
	if (argc == 1)
		return (0);
	if ((e.tab = check_error(argc, argv)) == NULL)
		return (die(&e, "Error\n"));
	if (!(e.a = get_list(e.tab)))
	{
		free_tab(e.tab);
		return (die(&e, "Error\n"));
	}
	free_tab(e.tab);
	e.b = NULL;
	e.coup = 0;
	if (check_double(e.a) == -1)
		return (die(&e, "Error\n"));
	if (is_sort(e.a) == 1)
		return (die(&e, ""));
	algo2(&e);
	del_lst(&e.a);
	return (0);
}
