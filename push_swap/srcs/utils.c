#include "../include/push_swap.h"

t_lst		*swap(t_lst *a, t_lst *b)
{
	t_lst	*tmp;
	
	tmp = a;
	tmp->next = b->next;
	b->next = tmp;
	a = b;
	return (a);
}

t_lst	*push(t_lst *a, t_lst **b)
{
	t_lst	*tmp;

	tmp = a;
	a = a->next;
	tmp->next = *b;
	*b = tmp;
	return (a);
}

t_lst	*rotate(t_lst *a)
{
	t_lst	*tmp;
	t_lst	*slst;

	slst = a->next;
	tmp = a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = a;
	a->next = NULL;
	return (slst);

}

t_lst	*reverse_rotate(t_lst *a)
{
	t_lst	*tmp;
	t_lst	*slst;

	slst = a;
	tmp = a;
	while (slst->next->next != NULL)
		slst = slst->next;
	a = slst;
	slst = slst->next;
	a->next = NULL;
	slst->next = tmp;
	return (slst);
}







