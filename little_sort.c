/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/16 14:08:27 by ldermign         ###   ########.fr       */
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
	// afficher_une_stack(stack);
	// printf("minimum = min = %d, uts->min1 = %d, med = %d, uts->min2 = %d\n", min, uts->min1, med, uts->min2);
}

void	eject_two_mini(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int	i;

	i = 0;
	printf("uts->min1 = %d, uts->min2 = %d\n", uts->min1, uts->min2);
	// afficher_une_stack(s_a);
	while (i < uts->min1)
	{
		rotate_a(s_a);
		i++;
	}
		// afficher_une_stack(s_a);
	// afficher_deux_stack(s_a, s_b);
	push_b(s_a, s_b);
	printf("%d - %d - 1 = %d\n", uts->min2, uts->min1, uts->min2 - uts->min1 - 1);
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
	int	one;
	int	two;
	int	three;

	if (s_a == NULL || size_stack(*s_a) != 2)
		return (ERROR);
	one = (*s_a)->nbr;
	two = (*s_a)->next->nbr;
	three = (*s_a)->next->next->nbr;
	if (!check_if_sort(*s_a))
	{
		if (one < two && two > three)
		{
			reverse_rotate_a(s_a);
			if (one < three)
				swap_a(s_a);
		}
		else if (one > two
			&& ((two < three && one < three) || (two > three && one > three)))
		{
			swap_a(s_a);
			if (one > three)
				reverse_rotate_a(s_a);
		}
		else
			rotate_a(s_a);
	}
	return (SUCCESS);
}

int	sort_three_values_inv(t_lst **s_a)
 {
 	int	one;
 	int	two;
 	int	three;

 	if (s_a == NULL || size_stack(*s_a) != 2)
 		return (ERROR);
 	one = (*s_a)->nbr;
 	two = (*s_a)->next->nbr;
 	three = (*s_a)->next->next->nbr;
 	if (!check_if_sort_inv(*s_a))
 	{
 		if ((one < two && two < three && one < three)
 		|| (one < two && two > three && one > three)
 		|| (one > two && two < three && one > three))
 		{
 			swap_b(s_a);
 			if (one < two && two < three && one < three)
 				reverse_rotate_b(s_a);
 			else if (one > two && two < three && one > three)
 				rotate_b(s_a);
 		}
 		else if (one < two && two > three && one < three)
 			rotate_b(s_a);
 		else if (one > two && two < three && one > three)
 			reverse_rotate_b(s_a);
 	}
 	return (SUCCESS);
 }