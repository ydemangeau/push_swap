/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:28:32 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 13:33:54 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	if (!(e.a = get_list(e.tab)))
		return (die(&e, "Error"));
	free_tab(e.tab);
	e.b = NULL;
	e.coup = 0;
	if (check_double(e.a) == -1)
		return (die(&e, "Error"));
	if (is_sort(e.a) == 1)
		return (0);
	algo2(&e);
	del_lst(&e.a);
	return (0);
}
