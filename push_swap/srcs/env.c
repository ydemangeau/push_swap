/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:25:50 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 07:27:02 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		del_lst(t_lst **a)
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
	a = create_elem();
	while (argv[++i])
		size++;
	if (ft_atol(argv[0]) > 2147483647 || ft_atol(argv[0]) < -2147483648)
		return (NULL);
	a->value = ft_atoi(argv[0]);
	sa = a;
	i = 0;
	while (++i != size)
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (NULL);
		a->next = create_elem();
		a = a->next;
		a->value = ft_atoi(argv[i]);
	}
	return (sa);
}
