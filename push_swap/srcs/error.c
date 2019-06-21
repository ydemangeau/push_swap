/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:27:16 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/21 16:41:35 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void		display(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putendl(tab[i]);
	}
}

char	**free_tab(char **tab)
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

char	**get_tab(char *argv)
{
	char	**tab;
	int i;
	int a;
	int err;

	a = -1;
	tab = ft_strsplit(argv, ' ');
	while (tab[++a])
	{
		i = -1;
		while (tab[a][++i])
		{
			if ((tab[a][i] == '+' || tab[a][i] == '-'))
			{
				if (i != 0)
					return (free_tab(tab));
				else
					i++;
			}
			if (ft_isdigit(tab[a][i]) == 0)
					return (free_tab(tab));
		}
	}
	return (tab);
}

char	**ralloc(char **tab, char **tmp)
{
	char	**res;
	int		size;
	int		i;
	int		j;

	size = 0;
	i = -1;
	j = -1;
	while (tab[++i])
		size++;
	i = -1;
	while (tmp[++i])
		size++;
	if (!(res = ft_memalloc(sizeof(char *) * size + 1)))
		return (NULL);
	i = -1;
	while (tab[++i])
		res[i] = ft_strdup(tab[i]);
	while (tmp[++j])
	{
		res[i] = ft_strdup(tmp[j]);
		i++;
	}
	res[i] = 0;
	return (res);
}

char		**check_error(int argc, char **argv)
{
	char	**tab;
	char	**tmp;
	char	**tmp2;
	int		a;

	a = 0;
	tab = NULL;
	tmp = NULL;
	tmp2 = NULL;
	if (argc < 2)
		return (NULL);
	while (argv[++a])
	{
		if (tab == NULL)
		{
			if ((tab = get_tab(argv[a])) == NULL)
				return (NULL);
		}
		else
		{
			if ((tmp = get_tab(argv[a])) == NULL)
				return (free_tab(tab));
			tmp2 = ralloc(tab, tmp);
			free_tab(tab);
			free_tab(tmp);
			tab = tmp2;
		}
	}
	return (tab);
}

int		check_double(t_lst *a)
{
	t_lst	*tmp;

	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->value == tmp->value)
				return (-1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}
