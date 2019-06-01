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
		ft_memdel((void *)a);
		list = tmp;
	}
}

t_lst		*create_elem()
{
	t_lst	*data;

	data = NULL;
	if (!(data = ft_memalloc(sizeof(t_lst))))
		return (NULL);
	data->value = 0;
	data->next = NULL;
	return (data);
}

t_lst	*get_list(int argc, char **argv)
{
	t_lst		*a;
	t_lst		*sa;
	int i;

	i = 1;
	if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
		return (NULL);
	a = create_elem();
	a->value = ft_atoi(argv[i]);
	sa = a;
	while (++i != (argc))
	{
//		printf("a->value =%ld\n", ft_atol(argv[i]));
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			return (NULL);
		a->next = create_elem();
		a = a->next;
		a->value = ft_atoi(argv[i]);
	}
	return (sa);
}


