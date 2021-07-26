/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_nul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 10:51:08 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/26 10:53:06 by ldermign         ###   ########.fr       */
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
	int i;
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

int	push_med_sup(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	int		i;
	int		ret;
	int		size;

	i = 0;
	ret = 0;
	size = size_stack(*s_b);
	while (i <= size)
	{
		if ((*s_b)->nbr >= uts->med)
		{
			push_a(s_b, s_a);
			// ret++;
		}
		else
			rotate_b(s_b);
		i++;
		ret++;
	}
	return (ret);
}

int	push_med_inf(t_lst **s_a, t_lst **s_b, int size, t_utils *uts)
{	// ATTENTION SIZE ET SIZET --> quand fin algo, verifier lequel plus efficace
	(void)size;
	int		i;
	// int		sizet;

	i = 0;
	uts->last_push = 0;
	int ret = 0;
	// sizet = size_stack(*s_a);
	// printf("regarder la \n");
	// afficher_une_stack(s_a);
	// printf("size = %d, s_a = %d, size = %d, mediane = %f\n", size, size_stack(*s_a), size, uts->med);
	while (i <= size)
	{
		if ((*s_a)->nbr < uts->med)
		{
			push_b(s_a, s_b);
			uts->last_push++;
			// printf("\tuts->push = %d\n", uts->push);
		}
		else
			rotate_a(s_a);
		i++;
		ret++;
	}
	uts->last_push = ret;
	// printf("\tuts->push = %d\n", uts->push);
	return (ret);
}

void	cleaning(t_lst **s_a)
{
	if (max_val(*s_a) > (size_stack(*s_a) / 2))
	{
		while (max_val(*s_a) != size_stack(*s_a))
			rotate_b(s_a);
	}
	else
	{
		while (max_val(*s_a) != size_stack(*s_a))
			reverse_rotate_b(s_a);
	}
}

void	sort_by_sort(t_lst **s_a, t_lst **s_b, t_utils *uts, int size)
{
	int	min;
	printf("size = %d\n", size);
	if (check_if_sort(*s_a) || size == 0 || size == 1)
		return ;
	else if (size == 2 && ((*s_a)->nbr > (*s_a)->next->nbr))
		swap_a(s_a);
	else if (size == 3)
		sort_three_with_more(s_a);
	else if (size == 4)
	{
		uts->min1 = min_val(*s_a, size);
		min = get_nbr_pos(s_a, uts->min1);
		uts->min2 = -1;
		eject_two_mini(s_a, s_b, uts);
		while (max_val(*s_a) != size_stack(*s_a))
			rotate_a(s_a);
		sort_three_with_more(s_a);
		push_a(s_b, s_a);
	}
	else if (size == 5)
		sort_five_with_more(s_a, s_b, uts);
		// printf("test normalement 2\n");
}

int	med_reduc(t_lst **s_a, t_lst **s_b, t_lst **med, t_utils *uts)
{
	uts->med = get_med(s_a, uts->tmp, uts);
	add_nbr_back(med, uts->med);
	push_med_inf(s_a, s_b, uts->ret, uts);
	cleaning(s_a);
	return (0);
}

int	med_reduc2(t_lst **s_a, t_lst **s_b, t_lst **med, t_utils *uts)
{
	uts->med = get_med(s_a, uts->tmp, uts);
	add_nbr_back(med, uts->med);
	push_med_inf(s_a, s_b, uts->ret, uts);
	cleaning(s_a);
	return (0);
}

void	start(t_lst **s_a, t_lst **s_b, t_lst **med, t_utils *uts)
{
	int	i;
	int	sort;

	i = 0;
	uts->stack = 'a';
	pos_three_max(s_a, s_b, uts);
	sort_three_values(s_a);
	sort = size_stack(*s_a);
	uts->med = get_med(s_b, INT32_MAX, uts);
	add_nbr_back(med, uts->med);
	push_med_sup(s_a, s_b, uts);
	cleaning(s_a);
	uts->first = (*s_b)->nbr;
	uts->ret = size_stack(*s_b) - sort;
	while (uts->ret >= 3)
	{
		uts->ret = size_stack(*s_a) - sort;
		med_reduc(s_a, s_b, med, uts);
		if (uts->last_push <= 6)
			break ;
	}
	sort_by_sort(s_a, s_b, uts, uts->ret);
	sort = size_stack(*s_a);
	printf("last_push = %d\n", uts->first);

	// uts->pos_first = get_nbr_pos;
	// while (1)
	// {
		// med_reduc2(s_a, s_b, med, uts);
	// }
	// while (!check_if_sort(*s_a) && *s_b != NULL)
	// {
	// 	sort = size_stack(*s_a);
	// 	supp_last_elemt(med);
	// 	// if (last_push <= 2)
	// 	// printf("sort = %d, ret = %d, last_push = %d\n", sort, ret, uts->last_push);

	// 	break ;
	// }
}

int	nightmare_size(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	t_lst	*med;

	med = NULL;
	start(s_a, s_b, &med, uts);
	afficher_stack_med(&med);
	return (SUCCESS);
}