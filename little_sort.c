/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/04 19:13:40 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	sort_five_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	minimum(s_a, uts);
	eject_two_mini(s_a, s_b, uts);
	// afficher_deux_stack(s_a, s_b);
	sort_three_values(s_a);
	if ((*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
	push_a(s_b, s_a);
	push_a(s_b, s_a);
	return (SUCCESS);
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
	int	two;
	int	three;

	if (s_b == NULL || size_stack(*s_b) != 2)
		return (ERROR);
	two = (*s_b)->next->nbr;
	three = (*s_b)->next->next->nbr;
	if (!check_if_sort_inv(*s_b))
	{
		if (((*s_b)->nbr < two && two < three && (*s_b)->nbr < three)
			|| ((*s_b)->nbr < two && two > three && (*s_b)->nbr > three)
			|| ((*s_b)->nbr > two && two < three && (*s_b)->nbr > three))
		{
			swap_b(s_b);
			if ((*s_b)->nbr < two && two < three && (*s_b)->nbr < three)
				reverse_rotate_b(s_b);
			else if ((*s_b)->nbr > two && two < three && (*s_b)->nbr > three)
				rotate_b(s_b);
		}
		else if ((*s_b)->nbr < two && two > three && (*s_b)->nbr < three)
			rotate_b(s_b);
		else if ((*s_b)->nbr > two && two < three && (*s_b)->nbr < three)
			reverse_rotate_b(s_b);
	}
	return (SUCCESS);
}
