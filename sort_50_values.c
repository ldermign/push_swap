/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_50_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:51:08 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/04 14:08:33 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int		i;

	i = 0;
	if (uts->stack == 'a')
	{
		while (i < uts->here)
		{
			push_b(s_a, s_b);
			i++;
		}
		rotate_a(s_a);
	}
	else
	{
		while (i < uts->here)
		{
			push_a(s_b, s_a);
			i++;
		}
		rotate_a(s_a);
	}
}

void	push_only_max(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int		i;

	i = 0;
	if (uts->stack == 'a')
	{
		while (i < uts->here)
		{
			rotate_a(s_a);
			i++;
		}
		push_b(s_a, s_b);
	}
	else
	{
		while (i < uts->here)
		{
			rotate_b(s_b);
			i++;
		}
		push_a(s_b, s_a);
	}
}

void	sort_three_with_more(t_lst **s_a)
{
	int	one;
	int	two;
	int	three;

	if (s_a == NULL || size_stack(*s_a) <= 2)
		return ;
	one = (*s_a)->nbr;
	two = (*s_a)->next->nbr;
	three = (*s_a)->next->next->nbr;
	if (!check_if_sort(*s_a))
	{
		if ((one > two && two < three && one < three)
			|| (one > two && two < three && one > three)
			|| (one > two && two > three && one > three))
			swap_a(s_a);
		if (!(one > two && two < three && one < three))
		{
			rotate_a(s_a);
			swap_a(s_a);
			reverse_rotate_a(s_a);
		}
		if ((one < two && two > three && one > three)
			|| (one > two && two > three && one > three))
			swap_a(s_a);
	}
}

void	sort_five_with_more(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int	min;
	int	med;

	uts->min1 = min_val(*s_a, size_stack(*s_a) - 5);
	min = get_nbr_pos(s_a, uts->min1);
	uts->min2 = min_with_min(*s_a, size_stack(*s_a) - 5, min);
	med = get_nbr_pos(s_a, uts->min2);
	by_order_2(uts);
	eject_two_mini(s_a, s_b, uts);
	while (max_val(*s_a) != size_stack(*s_a))
		rotate_a(s_a);
	sort_three_with_more(s_a);
	if ((*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
	push_a(s_b, s_a);
	push_a(s_b, s_a);
}

void	sort_50_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	pos_five_max(s_a, uts);
	uts->stack = 'a';
	push_all_except_five_to(s_a, s_b, uts);
	sort_five_values(s_a, s_b, uts);
	while (size_stack(*s_b) >= 4)
	{
		uts->stack = 'b';
		pos_five_max(s_b, uts);
		push_all_five_to(s_a, s_b, uts);
		sort_five_with_more(s_a, s_b, uts);
	}
	if (size_stack(*s_b) == 3)
	{
		uts->stack = 'b';
		uts->here = max_val(*s_b);
		push_only_max(s_a, s_b, uts);
	}
	if (size_stack(*s_b) == 2)
		sort_three_values_inv(s_b);
	if (size_stack(*s_b) == 1 && (*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
	while (*s_b != NULL)
		push_a(s_b, s_a);
}
