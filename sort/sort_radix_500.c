/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 13:52:16 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/18 19:05:29 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_to_real_stack(t_lst **s_a, t_lst **s_b, t_lst *rad_ope)
{
	while (rad_ope != NULL)
	{
		if (rad_ope != NULL && rad_ope->nbr == 0)
		{
			rotate_a(s_a);
			rad_ope = rad_ope->next;
		}
		if (rad_ope != NULL && rad_ope->nbr == 1)
		{
			push_b(s_a, s_b);
			rad_ope = rad_ope->next;
		}
		if (rad_ope != NULL && rad_ope->nbr == 2)
		{
			push_a(s_b, s_a);
			rad_ope = rad_ope->next;
		}
	}
}

void	get_list_nbr(t_lst **s_a, t_lst **rad)
{
	int		i;
	int		ret;
	int		nbr;
	t_lst	*first;

	i = 0;
	ret = 0;
	nbr = 0;
	first = *s_a;
	while (ret <= size_stack(*s_a))
	{
		i = 0;
		while (*s_a != NULL && i < ret)
		{
			*s_a = (*s_a)->next;
			i++;
		}
		nbr = (*s_a)->nbr;
		*s_a = first;
		add_nbr_back(rad, how_many_down(*s_a, nbr));
		ret++;
	}
	*s_a = first;
}

void	get_operations(t_lst **rad_a, t_lst **rad_b, t_lst **rad_ope)
{
	int	i;
	int	j;
	int	size_stk;
	int	max_len;

	size_stk = size_stack(*rad_a);
	max_len = ft_len_int(ft_binary(get_nbr_pos(rad_a, max_val(*rad_a))));
	i = 0;
	while (i < max_len)
	{
		j = 0;
		while (j <= size_stk)
		{
			if (((*rad_a)->nbr >> i) & 1)
				simu_rotate_a(rad_a, rad_ope);
			else
				simu_push_b(rad_a, rad_b, rad_ope);
			j++;
		}
		while (*rad_b != NULL)
			simu_push_a(rad_b, rad_a, rad_ope);
		i++;
	}
}
