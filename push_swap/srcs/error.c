#include "../include/push_swap.h"

int		check_error(int argc , char **argv)
{
	int		a;
	int		i;

	a = 0;
	if (argc < 2)
		return (-1);
	while (argv[++a])
	{
		i = -1;
		while (argv[a][++i])
		{
			if ((argv[a][i] == '+' || argv[a][i] == '-'))
			{
				if (i != 0)
					return (-1);
				else
					i++;
			}
			if (ft_isdigit(argv[a][i]) == 0)
				return (-1);
		}
	}
	return (1);
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
}


