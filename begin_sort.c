/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/30 13:15:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_three_max(t_lst **s_a, t_lst **s_b, t_first **first, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		push(s_a, s_b, &((*first)->fst_b), 'b');
		i++;
	}
	rotate(s_a, &((*first)->fst_a), 'a');
	afficher_deux_stack(s_a, s_b);
}

void	pos_three_max(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int i;
	int	max;
	int	med;
	int	lit;

	i = 0;
	uts->pos1 = max_val(*s_a);
	max = get_nbr_pos(s_a, uts->pos1);
	uts->pos2 = max_with_max(*s_a, max);
	med = get_nbr_pos(s_a, uts->pos2);
	uts->pos3 = max_with_max(*s_a, med);
	lit = get_nbr_pos(s_a, uts->pos3);
	by_order(uts);
	push_three_max(s_a, s_b, first, uts->pos1);
	push_three_max(s_a, s_b, first, uts->pos2 - uts->pos1 - 1);
	push_three_max(s_a, s_b, first, uts->pos3 - uts->pos2 - uts->pos1);
	uts->size = size_stack(*s_a) - 3;
	while (i <= uts->size)
	{
		push(s_a, s_b, &((*first)->fst_b), 'b');
		i++;
	}
}

// void	sort_median(t_lst **stack, t_lst **first, t_utils *uts)
// {
// 	(void)stack;
// 	(void)first;
// 	(void)uts;
// }

void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	get_info(uts);
	pos_three_max(s_a, s_b, first, uts);
	sort_three_values(s_a, &((*first)->fst_a));
	// sort_median(s_b, &((*first)->fst_b), uts);
	
	
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