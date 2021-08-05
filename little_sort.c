/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/05 18:26:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	by_order_2(t_utils *uts)
{
	int	tmp1;
	int	tmp2;

	if (uts->min1 < uts->min2)
	{
		tmp1 = uts->min1;
		tmp2 = uts->min2;
	}
	else
	{
		tmp2 = uts->min1;
		tmp1 = uts->min2;
	}
	uts->min1 = tmp1;
	uts->min2 = tmp2;
}

void	minimum(t_lst **stack, t_utils *uts)
{
	int	i;
	int	min;
	int	med;

	i = 0;
	uts->min1 = min_val(*stack, size_stack(*stack));
	min = get_nbr_pos(stack, uts->min1);
	uts->min2 = min_with_min(*stack, size_stack(*stack), min);
	med = get_nbr_pos(stack, uts->min2);
	by_order_2(uts);
}

void	eject_two_mini(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int	i;

	i = 0;
	while (i < uts->min1)
	{
		rotate_a(s_a);
		i++;
	}
	push_b(s_a, s_b);
	if (uts->min2 == -1)
		return ;
	i = 0;
	while (i < uts->min2 - uts->min1 - 1)
	{
		rotate_a(s_a);
		i++;
	}
	push_b(s_a, s_b);
}

int	sort_three_values(t_lst **s_a)
{
	int	three;

	if (s_a == NULL || size_stack(*s_a) != 2)
		return (ERROR);
	three = (*s_a)->next->next->nbr;
	if (!check_if_sort(*s_a))
	{
		if ((*s_a)->nbr < (*s_a)->next->nbr && (*s_a)->next->nbr > three)
		{
			reverse_rotate_a(s_a);
			if ((*s_a)->nbr > (*s_a)->next->nbr)
				swap_a(s_a);
		}
		else if ((*s_a)->nbr > (*s_a)->next->nbr
			&& (((*s_a)->next->nbr < three && (*s_a)->nbr < three)
				|| ((*s_a)->next->nbr > three && (*s_a)->nbr > three)))
		{
			swap_a(s_a);
			if ((*s_a)->nbr > three)
				reverse_rotate_a(s_a);
		}
		else
			rotate_a(s_a);
	}
	return (SUCCESS);
}

int	sort_three_values_inv(t_lst **s_b)
{
	int	one;
	int	two;
	int	three;

	one = (*s_b)->nbr;
	two = (*s_b)->next->nbr;
	three = (*s_b)->next->next->nbr;
	if (!check_if_sort_inv(*s_b))
	{
		if ((one < two && two < three && one < three)
			|| (one < two && two > three && one > three)
			|| (one > two && two < three && one > three))
		{
			swap_b(s_b);
			if (one < two && two < three && one < three)
				reverse_rotate_b(s_b);
			else if (one > two && two < three && one > three)
				rotate_b(s_b);
		}
		else if (one < two && two > three && one < three)
			rotate_b(s_b);
		else if (one > two && two < three && one < three)
			reverse_rotate_b(s_b);
	}
	return (SUCCESS);
}
