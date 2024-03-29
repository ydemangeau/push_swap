/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:24:22 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/24 15:59:02 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int			die(t_env *e, char *reason)
{
	ft_putendl(reason);
	del_lst(&e->a);
	return (-1);
}

int			comp(t_env *e, char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(e, 0);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(e, 0);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(e, 0);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(e, 0);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(e, 0);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(e, 0);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(e, 0);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(e, 0);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(e, 0);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(e, 0);
	else
		return (-1);
	return (0);
}

int			checker(t_env *e)
{
	char	*line;

	while ((ft_get_next_line(0, &line) > 0))
	{
		if (comp(e, line) == -1)
		{
			free(line);
			ft_putendl("Error");
			return (0);
		}
		free(line);
	}
	if (e->b == NULL && is_sort(e->a) == 1)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}

int			main(int argc, char **argv)
{
	t_env		e;
	int			i;

	i = -1;
	if (argc == 1)
		return (0);
	if ((e.tab = check_error(argc, argv)) == NULL)
		return (die(&e, "Error"));
	if (!(e.a = get_list(e.tab)))
	{
		free_tab(e.tab);
		return (die(&e, "Error"));
	}
	free_tab(e.tab);
	e.b = NULL;
	e.coup = 0;
	if (check_double(e.a) == -1)
		return (die(&e, "Error"));
	checker(&e);
	//ft_putnbr(count_lst(e.a));
	//ft_putendl("");
	del_lst(&e.a);
	//ft_putnbr(e.coup);
	return (0);
}
