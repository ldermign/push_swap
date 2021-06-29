/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/29 12:07:09 by ldermign         ###   ########.fr       */
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

void	get_three_max(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		uts->max = max_val(*s_a, (*first)->fst_a);
		uts->size = size_stack(*s_a);
		if ((uts->size % 2) == 0)
			uts->middle = uts->size / 2;
		else
			uts->middle = (uts->size + 1) / 2;
		up_rotate_reverse(s_a, &((*first)->fst_a), uts, uts->max);		
		push(s_a, s_b, &((*first)->fst_b), 'b');
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
	int	i;

	i = 0;
	get_info(uts);
	get_three_max(s_a, s_b, first, uts);
	sort_three_values(s_a, &((*first)->fst_a));
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