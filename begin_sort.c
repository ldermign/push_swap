/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/16 14:30:15 by ldermign         ###   ########.fr       */
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
	// printf("\nmax = %d\n", max);
	uts->pos2 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos2);
	// printf("\nmax = %d\n", max);
	uts->pos3 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos3);
	// printf("\nmax = %d\n", max);
	uts->pos4 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos4);
	// printf("\nmax = %d\n", max);
	uts->pos5 = max_with_max(*stack, max);
	max = get_nbr_pos(stack, uts->pos5);
	// printf("\nmax = %d\n", max);
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

	i = 0;
	uts->pos1 = max_val(*s_a);
	max = get_nbr_pos(s_a, uts->pos1);
	uts->pos2 = max_with_max(*s_a, max);
	med = get_nbr_pos(s_a, uts->pos2);
	uts->pos3 = max_with_max(*s_a, med);
	lit = get_nbr_pos(s_a, uts->pos3);
	by_order_3(uts);
	uts->size = size_stack(*s_a);
	uts->here = uts->pos1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_max(s_a, s_b, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_max(s_a, s_b, uts);
	uts->size = size_stack(*s_a) - 3;
	while (i <= uts->size)
	{
		push_b(s_a, s_b);
		i++;
	}
}

// void	sort_median(t_lst **stack, t_lst **t_utils *uts)
// {
// 	(void)stack;
// 	(void)first;
// 	(void)uts;
// }

// void	sort_100_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
// {
// 	int	i;
// 	int	ret;

// 	i = 0;
// 	ret = size_stack(*s_a);
// 	pos_three_max(s_a, s_b, uts);
// 	sort_three_values(s_a);
// 	while (ret >= 3)
// 	{
// 		printf("ret = %d\n", ret);
// 		pos_three_max(s_b, s_a, uts);
// 		sort_three_values(s_b, &((*first)->fst_b), 'b');
// 		uts->size = size_stack(*s_a);
// 		while (i <= uts->size - 3)
// 		{
// 			push(s_a, s_b, &((*first)->fst_b), 'b');
// 			i++;
// 		}
// 		i = 0;
// 		while (i < 3)
// 		{
// 			reverse_rotate(s_b, &((*first)->fst_b), 'b');
// 			push(s_b, s_a);
// 			i++;
// 		}
// 		ret -= 3;
// 	}
// }

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
	while (size_stack(*s_b) >= 5)
	{
		uts->stack = 'b';
		pos_five_max(s_b, uts);
		push_all_five_to(s_a, s_b, uts);
		sort_five_with_more(s_a, s_b, uts);
	}
	if (size_stack(*s_b) == 2)
		sort_three_values_inv(s_b);
	if (size_stack(*s_b) == 1 && (*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
	while (*s_b != NULL)
		push_a(s_b, s_a);
}

int	nightmare_size(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	t_med **three;

	three = NULL;
 	three = malloc(sizeof(t_med));
	if (three == NULL)
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	pos_three_max(s_a, s_b, uts);
	sort_three_values(s_a);
	get_med(s_b, three); ///////////// commencer vrai algo
	
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
	// else
	// 	nightmare_size(s_a, s_b, uts);
	return (SUCCESS);
}