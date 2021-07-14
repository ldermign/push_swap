/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/14 22:19:06 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	sort_three_and_more(t_lst **s_a, t_lst **s_b, t_lst **f_a, t_lst **f_b)
// {
// 	int	one;
// 	int	two;
// 	int	three;

// 	if (s_a == NULL || size_stack(*s_a) != 2)
// 		return (ERROR);
// 	one = (*s_a)->nbr;
// 	two = (*s_a)->next->nbr;
// 	three = (*s_a)->next->next->nbr;
	
// }

void	minimum(t_lst **stack, t_utils *uts)
{
	int	i;
	int	min;
	int	med;

	i = 0;
	min = 0;
	med = 0;
	uts->min1 = min_val(*stack, size_stack(*stack));
	min = get_nbr_pos(stack, uts->min1);
	uts->min2 = min_with_min(*stack, size_stack(*stack), min);
	med = get_nbr_pos(stack, uts->min2);
	by_order_2(uts);
	uts->size = size_stack(*stack);
}

void	eject_two_mini(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 0;
	while (i < uts->min1)
	{
		rotate(s_a, (&((*first)->fst_a)), 'a');
		i++;
	}
	afficher_deux_stack(s_a, s_b);
	push(s_a, s_b, &((*first)->fst_b), 'b');
	i = 0;
	while (i < uts->min2 - uts->min1 - 1)
	{
		rotate(s_a, (&((*first)->fst_a)), 'a');
		i++;
	}
	push(s_a, s_b, &((*first)->fst_b), 'b');
}

int	sort_five_values(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	minimum(s_a, uts);
	eject_two_mini(s_a, s_b, first, uts);
	afficher_deux_stack(s_a, s_b);
	sort_three_values(s_a, &((*first)->fst_a), 'a');
	if ((*s_b)->nbr < (*s_b)->next->nbr)
		swap(s_b, &((*first)->fst_b), 'b');
	push(s_b, s_a, &((*first)->fst_a), 'a');
	push(s_b, s_a, &((*first)->fst_a), 'a');
	return (SUCCESS);
}

int	sort_three_values(t_lst **stack, t_lst **first, char c)
{
	int	one;
	int	two;
	int	three;

	if (stack == NULL || size_stack(*stack) != 2)
		return (ERROR);
	one = (*stack)->nbr;
	two = (*stack)->next->nbr;
	three = (*stack)->next->next->nbr;
	if (!check_if_sort(*stack))
	{
		if (one < two && two > three)
		{
			reverse_rotate(stack, first, c);
			if (one < three)
				swap(stack, first, c);
		}
		else if (one > two
			&& ((two < three && one < three) || (two > three && one > three)))
		{
			swap(stack, first, c);
			if (one > three)
				reverse_rotate(stack, first, c);
		}
		else
			rotate(stack, first, c);
	}
	return (SUCCESS);
}
