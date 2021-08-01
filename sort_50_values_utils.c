/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_50_values_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:45:37 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:52:32 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pos_five_max(t_lst **stack, t_utils *uts)
{
	int	max;
	int	size;

	size = size_stack(*stack);
	uts->pos1 = max_val(*stack);
	max = get_nbr_pos(stack, uts->pos1);
	uts->pos2 = max_with_max(*stack, size_stack(*stack), max);
	max = get_nbr_pos(stack, uts->pos2);
	uts->pos3 = max_with_max(*stack, size_stack(*stack), max);
	max = get_nbr_pos(stack, uts->pos3);
	uts->pos4 = max_with_max(*stack, size_stack(*stack), max);
	max = get_nbr_pos(stack, uts->pos4);
	uts->pos5 = max_with_max(*stack, size_stack(*stack), max);
	max = get_nbr_pos(stack, uts->pos5);
	by_order_5(uts);
}

void	pos_three_max(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int	i;
	int	max;
	int	med;
	int	lit;

	i = -1;
	uts->pos1 = max_val(*s_a);
	max = get_nbr_pos(s_a, uts->pos1);
	uts->pos2 = max_with_max(*s_a, size_stack(*s_a), max);
	med = get_nbr_pos(s_a, uts->pos2);
	uts->pos3 = max_with_max(*s_a, size_stack(*s_a), med);
	lit = get_nbr_pos(s_a, uts->pos3);
	uts->tmp = lit;
	by_order_3(uts);
	uts->here = uts->pos1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_max(s_a, s_b, uts);
	uts->size = size_stack(*s_a) - 3;
	while (++i <= uts->size)
		push_b(s_a, s_b);
}

void	push_all_except_five_to(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int	i;

	i = 0;
	uts->here = uts->pos1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos4 - uts->pos3 - 1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos5 - uts->pos4 - 1;
	push_max(s_a, s_b, uts);
	uts->size = size_stack(*s_a) - 5;
	while (i <= uts->size)
	{
		push_b(s_a, s_b);
		i++;
	}
	sort_five_values(s_a, s_b, uts);
}

void	push_all_five_to(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	uts->here = uts->pos1;
	push_only_max(s_a, s_b, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_only_max(s_a, s_b, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_only_max(s_a, s_b, uts);
	uts->here = uts->pos4 - uts->pos3 - 1;
	push_only_max(s_a, s_b, uts);
	uts->here = uts->pos5 - uts->pos4 - 1;
	push_only_max(s_a, s_b, uts);
}
