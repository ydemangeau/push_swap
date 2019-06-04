/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 07:36:45 by ydemange          #+#    #+#             */
/*   Updated: 2019/06/04 07:38:56 by ydemange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct		s_lst
{
	int				value;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_env
{

	int				coup;
	struct s_lst	*a;
	struct s_lst	*b;
}					t_env;

void				del_lst(t_lst **list);
void				algo(t_env *e);
void				algo2(t_env *e);
int					found_min(t_lst *a);
int					found_max(t_lst *a);
int					count_i(t_lst *a, int nb);
int					check_value(t_lst *a, int i);
int					is_sort(t_lst *a);
int					check_med(t_lst *a, int med);
void				split(t_env *e);
int					calc_mediane(t_lst *a);
int					*lst_to_int(t_lst *a);
int					count_lst(t_lst *a);
int					*quicksort(int *v, int i);
int					check_error(int argc, char **argv);
int					check_double(t_lst *a);
void				ft_sa(t_env *e, int b);
void				ft_sb(t_env *e, int b);
void				ft_ss(t_env *e, int b);
void				ft_pa(t_env *e, int b);
void				ft_pb(t_env *e, int b);
void				ft_ra(t_env *e, int b);
void				ft_rb(t_env *e, int b);
void				ft_rr(t_env *e, int b);
void				ft_rra(t_env *e, int b);
void				ft_rrb(t_env *e, int b);
void				ft_rrr(t_env *e, int b);
void				display(t_env *e);
t_lst				*create_elem();
t_lst				*get_list(int argc, char **argv);
t_lst				*push(t_lst *a, t_lst **b);
t_lst				*swap(t_lst *a, t_lst *b);
t_lst				*rotate(t_lst *a);
t_lst				*reverse_rotate(t_lst *a);
#endif
