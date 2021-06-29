/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/29 14:45:18 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	up_rotate_reverse(t_lst **stack, t_lst **first, t_utils *uts, int max)
{
	int	i;

	i = 0;
	if (max <= uts->middle)
	{
		while (i < max)
		{
			rotate(stack, first, 'a');
			i++;
		}
	}
	else
	{
		while (max <= uts->size)
		{
			reverse_rotate(stack, first, 'a');
			max++;
		}
	}
}

int	pos_three_max(t_lst **stack, t_utils *uts)
{
	int i;
	int	max;
	int	med;
	int	lit;

	i = 0;
	uts->pos1 = max_val(*stack);
	max = get_nbr_pos(stack, uts->pos1);
	uts->pos2 = max_with_max(*stack, max);
	med = get_nbr_pos(stack, uts->pos2);
	uts->pos3 = max_with_max(*stack, med);
	lit = get_nbr_pos(stack, uts->pos3);
	if (max > med && max > lit)
		return (uts->pos1);
	else if (med > max && med > lit)
		return (uts->pos2);
	else
		return (uts->pos3);
	return (-1);
}

void	get_three_max(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	(void)s_b;
	(void)first;
	(void)uts;
	int	i;
	int	j;

	i = 0;
	j = 0;
	// while (i < 3)
	// {
	// 	uts->max = max_val(*s_a, (*first)->fst_a);
	// 	uts->size = size_stack(*s_a);
		// if ((uts->size % 2) == 0)
		// 	uts->middle = uts->size / 2;
		// else
		// 	uts->middle = (uts->size + 1) / 2;
		// up_rotate_reverse(s_a, &((*first)->fst_a), uts, uts->max);		
		// push(s_a, s_b, &((*first)->fst_b), 'b');
	// 	i++;
	// }
	// uts->pos = pos_three_max(s_a, uts);
	// printf("uts->pos = %d\n", uts->pos);
	while (i < 3)
	{
		printf("i = %d\n", i);
		while (j < pos_three_max(s_a, uts))
		{
			push(s_a, s_b, &((*first)->fst_b), 'b');
			j++;
		}
		rotate(s_a, &((*first)->fst_a), 'b');
		i++;
	}
}

void	sort_median(t_lst **stack, t_lst **first, t_utils *uts)
{
	(void)stack;
	(void)first;
	(void)uts;
}

void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	get_info(uts);
	get_three_max(s_a, s_b, first, uts);
	sort_three_values(s_b, &((*first)->fst_b));
	sort_median(s_b, &((*first)->fst_b), uts);
	
	
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	if (check_if_sort(*s_a))
		return (SUCCESS);
	if (uts->size == 3)
		sort_three_values(s_a, &((*first)->fst_a));
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, first);
	// if (uts->size <= 10)
	// 	little_sort(s_a, &((*first)->fst_a), 'a');
	// else if (uts->size <= 100)
	// 	medium_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	else
		nightmare_size(s_a, s_b, first, uts);
	return (SUCCESS);
}