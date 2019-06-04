/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:28:32 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 07:28:48 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env		e;
	char		**tab;
	int i;

	i = -1;
	if (argc == 1)
		return (0);
	if (!(tab = check_error(argc, argv)))
		return (die("Error"));
	if (!(e.a = get_list(tab)))
		return (die("Error"));
	ft_memdel((void**)tab);
	e.b = NULL;
	e.coup = 0;
/*
	 while (e.a != NULL)
	 {
		printf("%d\n",e.a->value);
		e.a = e.a->next;
	 }
*/
	if (check_double(e.a) == -1)
		return (die("Error"));
	if (is_sort(e.a) == 1)
		return (0);
	algo2(&e);
	del_lst(&e.a);
	return (0);
}
