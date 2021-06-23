/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:33:26 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/23 16:57:13 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_swap_reverse_rotate1(t_lst **s_a, t_lst **f_a, t_utils *uts)
{
	int	i;

	i = 1;
	while (i < uts->max)
	{
		rotate(s_a, f_a, 'a');
		i++;
	}
	i = 0;
	while (i < uts->max)
	{
		swap(s_a, f_a, 'a');
		reverse_rotate(s_a, f_a, 'a');
		i++;
	}
	rotate(s_a, f_a, 'a');
	rotate(s_a, f_a, 'a');
}

void	up_swap_reverse_rotate2(t_lst **s_a, t_lst **f_a, t_utils *uts)
{
	int	i;

	i = uts->max;
	while (i < uts->size)
	{
		reverse_rotate(s_a, f_a, 'a');
		i++;
	}
	i = 1;
	while (i < (uts->size - uts->max))
	{
		swap(s_a, f_a, 'a');
		rotate(s_a, f_a, 'a');
		i++;
	}
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

void	get_last_three(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 1;
	max(s_a, &((*first)->fst_a), uts, uts->size);
	simple_up(s_a, first, uts);
	while (i < 3)
	{
		max(s_a, &((*first)->fst_a), uts, (uts->size - i));
		if (uts->max <= (uts->middle - i))
			up_swap_reverse_rotate1(s_a, &((*first)->fst_a), uts);
		else
			up_swap_reverse_rotate2(s_a, &((*first)->fst_a), uts);
		i++;
	}
	i = 0;
	while (i < (uts->size - 3))
	{
		push(s_a, s_b, &((*first)->fst_b), 'b');
		i++;
	}
}
