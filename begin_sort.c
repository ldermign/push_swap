/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/22 16:08:09 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max(t_lst **s_a, t_lst *f_a, t_utils *uts, int last)
{
	int		i;
	int		tmp;
	int		nbr;

	i = 0;
	tmp = 0;
	nbr = 0;
	*s_a = f_a;
	while (i < last && (*s_a)->next)
	{
		tmp = (*s_a)->nbr;
		*s_a = (*s_a)->next;
		if (tmp > nbr)
		{
			nbr = tmp;
			uts->max = i;
		}
		i++;
	}
	*s_a = f_a;
}

void	up_swap_reverse_rotate(t_lst **s_a, t_lst **f_a, t_utils *uts)
{
	int	i;

	i = 1;
	while (i < uts->max)
	{
		rotate(s_a, f_a, 'a');
		i++;
	}
	i = 0;
	while (i <uts->max)
	{
		swap(s_a, f_a, 'a');
		reverse_rotate(s_a, f_a, 'a');
		i++;
	}
	rotate(s_a, f_a, 'a');
	rotate(s_a, f_a, 'a');
}

void	simple_up(t_lst **s_a, t_first **f, t_utils *uts)
{
	int	i;

	i = 0;
	if (uts->max < uts->middle)
	{
		while (i < uts->max + 1)
		{
			rotate(s_a, &((*f)->fst_a), 'a');
			i++;
		}
	}
	else
	{
		while (i < (uts->size - uts->max - 1))
		{
			reverse_rotate(s_a, &((*f)->fst_a), 'a');
			i++;
		}
	}
}

void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;
	(void)s_b;

	i = 0;
	get_info(uts);
	afficher_deux_stack(s_a, s_b);

	// automatiser + raccourcir s'il est plus proche de la fin ou non
	max(s_a, (*first)->fst_a, uts, uts->size);
	simple_up(s_a, first, uts);
	max(s_a, (*first)->fst_a, uts, (uts->size - 1));
	up_swap_reverse_rotate(s_a, &((*first)->fst_a), uts);
	max(s_a, (*first)->fst_a, uts, (uts->size - 2));
	up_swap_reverse_rotate(s_a, &((*first)->fst_a), uts);
// auto

	afficher_deux_stack(s_a, s_b);
	
	// while (i < 3)
	// {
	// 	uts->max = max(s_a, (*first)->fst_a, uts->size);
	// // 	up(s_a, first, uts, (uts->size - i));
	// // 	afficher_deux_stack(s_a, s_b);
	// // 	up(s_a, first, uts, (uts->size - i));
	// 	i++;
	// }
	
	
}

void	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	// if (uts->size <= 10)
	// 	little_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 100)
	// 	medium_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	// else
		nightmare_size(s_a, s_b, first, uts);
}