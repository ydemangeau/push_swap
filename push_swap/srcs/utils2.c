#include "../include/push_swap.h"

int		is_sort(t_lst *a)
{
	t_lst	*tmp;

	tmp = a;
	if (a == NULL)
		return (0);
	while (a != NULL)
	{
		if (tmp->value > a->value)
			return (0);
		tmp = a;
		a = a->next;
	}
	return (1);
}

int check_value(t_lst *a, int i)
{
	t_lst *tmp;

	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->value == i)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int count_i(t_lst *a , int nb)
{
	t_lst *tmp;
	int	i;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		if (tmp->value == nb)
			break ;
		i++;
		tmp = tmp->next;
	}
	return (i);

}

int		found_max(t_lst *a)
{
	t_lst *tmp;
	int i;

	tmp = a;
	i = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value > i)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}


int		found_min(t_lst *a)
{
	t_lst *tmp;
	int i;

	tmp = a;
	i = tmp->value;
	while (tmp != NULL)
	{
		if (tmp->value < i)
			i = tmp->value;
		tmp = tmp->next;
	}
	return (i);
}


