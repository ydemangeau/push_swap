
void		display(char **tab)
{
	int i;

	i = -1;
	while (tab[++i])
	{
		ft_putendl(tab[i]);
	}
}


void		display2(t_env *e)
{
	t_lst	*tmpa;
	t_lst	*tmpb;
	int		i;

	i = -1;
	tmpa = e->a;
	tmpb = e->b;
	while (tmpa != NULL)
	{
			ft_putnbr(tmpa->value);
			tmpa = tmpa->next;
			ft_putstr("   ");
			if (tmpb != NULL)
			{
				ft_putnbr(tmpb->value);
				tmpb = tmpb->next;
				ft_putchar('\n');
			}
			else
				ft_putchar('\n');
	}
	while (tmpb != NULL)
	{
		ft_putstr("    ");
		ft_putnbr(tmpb->value);
		tmpb = tmpb->next;
		ft_putchar('\n');
	}
		ft_putchar('\n');
}

