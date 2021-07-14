/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/14 16:01:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_max(t_lst **one, t_lst **two, t_first **first, t_utils *uts)
{
	int		i;

	i = 0;
	if (uts->stack == 'a')
	{
		while (i < uts->here)
		{
			push(one, two, &((*first)->fst_b), 'b');
			i++;
		}
		rotate(one, &((*first)->fst_a), 'a');
	}
	else
	{
		while (i < uts->here)
		{
			push(one, two, &((*first)->fst_a), 'a');
			i++;
		}
		rotate(one, &((*first)->fst_b), 'b');
	}
}

void	push_only_max(t_lst **one, t_lst **two, t_first **first, t_utils *uts)
{
	int		i;

	i = 0;
	if (uts->stack == 'a')
	{
		while (i < uts->here)
		{
			rotate(one, &((*first)->fst_a), 'a');
			i++;
		}
		push(one, two, &((*first)->fst_b), 'b');
	}
	else
	{
		while (i < uts->here)
		{
			rotate(one, &((*first)->fst_b), 'b');
			i++;
		}
		push(one, two, &((*first)->fst_a), 'a');
	}
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
	by_order_3(uts);
	uts->size = size_stack(*one);
	uts->here = uts->pos1;
	push_max(one, two, first, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_max(one, two, first, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_max(one, two, first, uts);
	uts->size = size_stack(*one) - 3;
	while (i <= uts->size)
	{
		push(one, two, &((*first)->fst_b), 'b');
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

// void	push_sort_auto(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
// {
// 	pos_three_max(s_b, s_a, first, uts);
	
// }

void	sort_100_values(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;
	int	ret;

	i = 0;
	ret = size_stack(*s_a);
	pos_three_max(s_a, s_b, first, uts);
	sort_three_values(s_a, &((*first)->fst_a), 'a');
	while (ret >= 3)
	{
		printf("ret = %d\n", ret);
		pos_three_max(s_b, s_a, first, uts);
		sort_three_values(s_b, &((*first)->fst_b), 'b');
		uts->size = size_stack(*s_a);
		while (i <= uts->size - 3)
		{
			push(s_a, s_b, &((*first)->fst_b), 'b');
			i++;
		}
		i = 0;
		while (i < 3)
		{
			reverse_rotate(s_b, &((*first)->fst_b), 'b');
			push(s_b, s_a, &((*first)->fst_a), 'a');
			i++;
		}
		ret -= 3;
	}
}

void	sort_five(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 0;
	uts->size = size_stack(*s_a) - 5;
	while (i <= uts->size)
	{
		push(s_a, s_b, &((*first)->fst_b), 'b');
		i++;
	}
	afficher_deux_stack(s_a, s_b);
	sort_five_values(s_a, s_b, first, uts);
}

void	sort_five_with_more(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 0;
	uts->size = size_stack(*s_a) - 5;
	while (i <= uts->size)
	{
		push(s_a, s_b, &((*first)->fst_b), 'b');
		i++;
	}
	afficher_deux_stack(s_a, s_b);
	sort_five_values(s_a, s_b, first, uts);
}

void	push_all_except_five_to(t_lst **one, t_lst **two,
			t_first **first, t_utils *uts)
{
	uts->here = uts->pos1;
	push_max(one, two, first, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_max(one, two, first, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_max(one, two, first, uts);
	uts->here = uts->pos4 - uts->pos3 - 1;
	push_max(one, two, first, uts);
	uts->here = uts->pos5 - uts->pos4 - 1;
	push_max(one, two, first, uts);
}

void	push_all_five_to(t_lst **one, t_lst **two, t_first **first,
			t_utils *uts)
{
	uts->here = uts->pos1;
	push_only_max(one, two, first, uts);
	uts->here = uts->pos2 - uts->pos1 - 1;
	push_only_max(one, two, first, uts);
	uts->here = uts->pos3 - uts->pos2 - 1;
	push_only_max(one, two, first, uts);
	uts->here = uts->pos4 - uts->pos3 - 1;
	push_only_max(one, two, first, uts);
	uts->here = uts->pos5 - uts->pos4 - 1;
	push_only_max(one, two, first, uts);
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
	printf("1 = %d, 2 = %d, 3 = %d, 4 = %d, 5 = %d\n", uts->pos1, uts->pos2, uts->pos3, uts->pos4, uts->pos5);
}

void	sort_50_values(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;
	int	size;

	i = 0;
	size = size_stack(*s_a);
	pos_five_max(s_a, uts);
	uts->stack = 'a';
	push_all_except_five_to(s_a, s_b, first, uts);
	sort_five(s_a, s_b, first, uts);
	// while (size_stack(*s_b) >= 5)
	// {
		uts->stack = 'b';
		pos_five_max(s_b, uts);
		push_all_five_to(s_b, s_a, first, uts);
		// sort_five_with_more(s_a, s_b, first, uts);
	// }
}
// void	sort_under_50(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
// {
// 	t_lst **five;

// 	five = NULL;
// 	five = malloc(sizeof)
// }

int	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	t_med **three;

	three = NULL;
 	three = malloc(sizeof(t_med));
	if (three == NULL)
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	pos_three_max(s_a, s_b, first, uts);
	sort_three_values(s_a, &((*first)->fst_a), 'a');
	get_med(s_b, three); ///////////// commencer vrai algo
	
	return (SUCCESS);
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	get_info(uts);
	if (check_if_sort(*s_a))
		return (SUCCESS);
	if (uts->size == 3)
		sort_three_values(s_a, &((*first)->fst_a), 'a');
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, first, uts);
	else if (uts->size <= 50)
		sort_50_values(s_a, s_b, first, uts);
	else if (uts->size <= 100)
		sort_100_values(s_a, s_b, first, uts);
	// else if (uts->size <= 50)
	// 	sort_under_50(s_a, s_b, first, uts);
	// else if (uts->size <= 100)
	// 	sort_under_100(s_a, s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	else
		nightmare_size(s_a, s_b, first, uts);
	return (SUCCESS);
}