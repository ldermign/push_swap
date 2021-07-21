/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/21 14:54:29 by ldermign         ###   ########.fr       */
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
	uts->pos2 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos2);
	uts->pos3 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos3);
	uts->pos4 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos4);
	uts->pos5 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos5);
	by_order_5(uts);
	// printf("1 = %d, 2 = %d, 3 = %d, 4 = %d, 5 = %d\n", uts->pos1, uts->pos2, uts->pos3, uts->pos4, uts->pos5);
	afficher_une_stack(stack);
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
	uts->pos2 = max_with_max(*s_a, max);
	med = get_nbr_pos(s_a, uts->pos2);
	uts->pos3 = max_with_max(*s_a, med);
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
	// afficher_une_stack(s_a);
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
	// afficher_une_stack(s_a);
	// printf("min = %d, uts->min1 = %d, med = %d, uts->min2 = %d\n", min, uts->min1, med, uts->min2);
	by_order_2(uts);
	// afficher_une_stack(s_a);
	eject_two_mini(s_a, s_b, uts);
	// afficher_deux_stack(s_a, s_b);
	while (max_val(*s_a) != size_stack(*s_a))
		rotate_a(s_a);
	afficher_une_stack(s_a);
	sort_three_with_more(s_a);
	afficher_une_stack(s_a);
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
{
	(void)size;
	int		i;
	int		ret;
	// int		sizet;

	i = 0;
	ret = 0;
	int rot = 0, pus = 0;
	// sizet = size_stack(*s_a);
	// printf("regarder la \n");
	// afficher_une_stack(s_a);
	printf("size = %d, s_a = %d, mediane = %f\n", size, size_stack(*s_a), uts->med);
	while (i <= size)
	{
		if ((*s_a)->nbr < uts->med)
		{
			push_b(s_a, s_b);
			pus++;
		}
		else
		{
			rotate_a(s_a);
			rot++;
		}
		ret++;
		i++;
	}
	printf("dans med = %d, pus = %d, rot = %d, size = %d\n", ret, pus, rot, size);
	return (ret);
}

void	cleaning(t_lst **s_a)
{
	// printf("max_val = %d, size = %d\n", max_val(*s_b), size_stack(*s_b) / 2);
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

void	sort_by_sort(t_lst **s_a)
{
	int	size;

	size = size_stack(*s_a) - 3;
	if (check_if_sort(*s_a))
		return ;
	if (size == 2)
		sort_three_values(s_a);
	// printf("size = %d\n", size);
	if (size == 1 && ((*s_a)->nbr > (*s_a)->next->nbr))
		swap_a(s_a);
}

int	med_reduc(t_lst **s_a, t_lst **s_b, t_lst **med, t_lst **hmn, t_utils *uts, int sort, int ret, int nique)
{
	int	size;

	size = size_stack(*s_a) - sort;
	uts->med = get_med(s_a, uts->tmp, uts);
	add_nbr_back(med, uts->med);
	nique = push_med_inf(s_a, s_b, ret, uts);
	add_nbr_back(hmn, nique);
	cleaning(s_a);
	return (0);
}

void	start(t_lst **s_a, t_lst **s_b, t_lst **med, t_lst **hmn, t_utils *uts)
{
	int	ret;
	int	nique;
	int	sort;

	ret = size_stack(*s_a) - 3;
	sort = 3;
	uts->stack = 'a';
	pos_three_max(s_a, s_b, uts);
	sort_three_values(s_a);
	uts->med = get_med(s_b, INT32_MAX, uts);
	add_nbr_back(med, uts->med);
	nique = push_med_sup(s_a, s_b, uts);
	add_nbr_back(hmn, nique);
	cleaning(s_a);
	nique = 0;
		afficher_deux_stack(s_a, s_b);
	while (!check_if_sort(*s_a) && *med != NULL)
	{
		while (less_in_med(hmn) >= 5)
			med_reduc(s_a, s_b, med, hmn, uts, sort, ret, nique);
	}
	// ret = size_stack(*s_a) - sort;
	// uts->med = get_med(s_a, uts->tmp, uts);
	// add_nbr_back(med, uts->med);
	// nique = push_med_inf(s_a, s_b, ret, uts);
	// add_nbr_back(hmn, nique);
	// cleaning(s_a);
	// afficher_deux_stack(s_a, s_b);
	// afficher_stack_med(med, hmn);
	// afficher_deux_stack(s_a, s_b);
		// if (check_if_sort(*s_a))
		// 	sort = size_stack(*s_a);
		// printf("less ??? %d\n", less_in_med(*s_a));
		// if (less_in_med(*hmn) <= 6)
		// {
		// 	if (!check_if_sort(*s_a))
		// 	{
		// 		if (size_stack(*s_a) - 3 == 2)
		// 			sort_three_values(s_a);
		// 		else if (size_stack(*s_a) - 3 == 1
		// 			&& ((*s_a)->nbr > (*s_a)->next->nbr))
		// 			swap_a(s_a);
		// 	}
		// 	if (check_if_sort(*s_a))
		// 	{
		// 		sort = size_stack(*s_a);
		// 		supp_elemt(hmn);
		// 		supp_elemt(med);
		// 	}
		// }
	}
	// if (check_if_sort(*s_a))
	// 	return ;
	// if (size_stack(*s_a) - 3 == 2)
	// 	sort_three_values(s_a);
	// else if (size_stack(*s_a) - 3 == 1
	// 	&& ((*s_a)->nbr > (*s_a)->next->nbr))
	// 	swap_a(s_a);
}

int	nightmare_size(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	t_lst	*med;
	t_lst	*hmn;

	med = NULL;
	hmn = NULL;
	start(s_a, s_b, &med, &hmn, uts);
	afficher_stack_med(&med, &hmn);
	return (SUCCESS);
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	get_info(uts);
	if (check_if_sort(*s_a))
		return (SUCCESS);
	if (uts->size == 3)
		sort_three_values(s_a);
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, uts);
	else if (uts->size <= 50)
		sort_50_values(s_a, s_b, uts);
	// else if (uts->size <= 100)
	// 	sort_100_values(s_a, s_b, uts);
	// else if (uts->size <= 50)
	// 	sort_under_50(s_a, s_b, uts);
	// else if (uts->size <= 100)
	// 	sort_under_100(s_a, s_b, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, uts);
	else
		nightmare_size(s_a, s_b, uts);
	return (SUCCESS);
}