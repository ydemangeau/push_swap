/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:25:50 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/23 16:06:20 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char		**free_tab(char **tab)
{
	int		i;
	int		size;

	i = -1;
	size = 0;
	while (tab[++i])
		size++;
	i = 0;
	while (i != size)
	{
		ft_strdel(&tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

t_lst		*del_lst(t_lst **a)
{
	t_lst	*tmp;
	t_lst	*list;

	list = *a;
	tmp = NULL;
	while (list != NULL)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
	return (NULL);
}

t_lst		*create_elem(void)
{
	t_lst	*data;

	data = NULL;
	if (!(data = ft_memalloc(sizeof(t_lst))))
		return (NULL);
	data->value = 0;
	data->next = NULL;
	return (data);
}

t_lst		*get_list(char **argv)
{
	t_lst		*a;
	t_lst		*sa;
	int			i;
	int			size;

	i = -1;
	size = 0;
	while (argv[++i])
		size++;
	a = create_elem();
	sa = a;
	i = -1;
	while (++i != size)
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (del_lst(&sa));
		a->value = ft_atoi(argv[i]);
		if ((i + 1) == size)
			break ;
		a->next = create_elem();
		a = a->next;
	}
	return (sa);
}
