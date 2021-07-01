/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/01 10:41:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_three_max(t_lst **one, t_lst **two, t_first **first, t_utils *uts)
{
	int		i;
	t_lst	**go;

	i = 0;
	if (uts->c == 'b')
		go = &((*first)->fst_b);
	else
		go = &((*first)->fst_a);
	while (i < uts->here)
	{
		push(one, two, &((*first)->fst_b), uts->c);
		i++;
	}
	if (uts->c == 'b')
		rotate(one, &((*first)->fst_a), 'a');
	else
		rotate(one, &((*first)->fst_b), 'b');
}

void	pos_three_max(t_lst **one, t_lst **two, t_first **first, t_utils *uts)
{
	int i;
	int	max;
	int	med;
	int	lit;

	i = 0;
	uts->pos1 = max_val(*one);
	max = get_nbr_pos(one, uts->pos1);
	uts->pos2 = max_with_max(*one, max);
	med = get_nbr_pos(one, uts->pos2);
	uts->pos3 = max_with_max(*one, med);
	lit = get_nbr_pos(one, uts->pos3);
	by_order(uts);
	uts->size = size_stack(*one);
	uts->here = uts->pos1;
	push_three_max(one, two, first, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_three_max(one, two, first, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_three_max(one, two, first, uts);
	uts->size = size_stack(*one) - 3;
	while (i <= uts->size)
	{
		push(one, two, &((*first)->fst_b), uts->c);
		i++;
	}
}

// void	sort_median(t_lst **stack, t_lst **first, t_utils *uts)
// {
// 	(void)stack;
// 	(void)first;
// 	(void)uts;
// }

// void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
// {
// 	get_info(uts);
// 	pos_three_max(s_a, s_b, first, uts);
// 	sort_three_values(s_a, &((*first)->fst_a));
// 	sort_median(s_b, &((*first)->fst_b), uts);
	
	
// }

void	push_sort_auto(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	pos_three_max(s_b, s_a, first, uts);
}

void	sort_under_100(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	get_info(uts);
	uts->c = 'b';
	pos_three_max(s_a, s_b, first, uts);
	sort_three_values(s_a, &((*first)->fst_a));
	// 3 tries sur a, reste sur b
	uts->c = 'a';
	push_sort_auto(s_a, s_b, first, uts);
	
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	if (check_if_sort(*s_a))
		return (SUCCESS);
	if (uts->size == 3)
		sort_three_values(s_a, &((*first)->fst_a));
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, first);
	if (uts->size <= 100)
		sort_under_100(s_a, s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	// else
	// 	nightmare_size(s_a, s_b, first, uts);
	return (SUCCESS);
}