#include "../include/push_swap.h"
/*
char	**get_tab(char *argv)
{
	char	**tab;
	int i;
	int a;
	
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
				{
					ft_putendl("Error");
					return (NULL);
				}
				else
					i++;
			}
			if (ft_isdigit(tab[a][i]) == 0)
			{
				ft_putendl("Error");
				return (NULL);
			}
		}
	}
	return (tab);
}
*/
int		die(char *reason)
{
	ft_putendl(reason);
	return (-1);
}

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc == 1)
		return (0);
	if (check_error(argc, argv) == -1)
		return (die("Error"));
	if (!(e.a = get_list(argc, argv)))
		return (die("over"));
	e.b = NULL;
	e.coup = 0;
	if (check_double(e.a) == -1)
		return (die("doublon"));
	if (is_sort(e.a) == 1)
		return (0);
	algo2(&e);
	
	display(&e);
	del_lst(&e.a);
	display(&e);
	//printf("nb d'argument  = %d\n",count_lst(e.a));
	//printf("nb de coup = %d\n",e.coup);
	return (0);
}



