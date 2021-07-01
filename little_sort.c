/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/01 16:08:47 by ldermign         ###   ########.fr       */
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

int	minimum(t_lst *stack)
{
	int	i;
	int	tmp;
	int	pos;
	int	min;

	i = 0;
	pos = 0;
	min = stack->nbr;
	while (stack->next)
	{
		stack = stack->next;
		tmp = stack->nbr;
		i++;
		if (min > tmp)
		{
			min = tmp;
			pos = i;
		}
	}
	return (pos);
}

void	eject_two_mini(t_lst **stack, t_lst **first, int min)
{
	int	i;

	i = 0;
	if (i < 3)
	{
		while (i < min)
		{
			rotate(stack, first, 'a');
			i++;
		}
	}
	else
	{
		while (i <= min)
		{
			reverse_rotate(stack, first, 'a');
			i++;
		}
	}
}

void	five_values_one_wrong(t_lst **stack, t_lst **first, char c)
{
	(void)stack;
	(void)first;
	(void)c;
	int	i;
	int	pos;

	i = 0;
	pos = pos_not_good(*stack);
	printf("pos = %d\n", pos);
}

int	sort_five_values(t_lst **s_a, t_lst **s_b, t_first **first)
{
	int	min;

	min = minimum(*s_a);
	if (how_many_not_good(*s_a) == 1)
	{
		five_values_one_wrong(s_a, &((*first)->fst_a), 'a');
		return (SUCCESS);
	}
	eject_two_mini(s_a, &((*first)->fst_a), min);
	push(s_a, s_b, &((*first)->fst_b), 'b');
	min = minimum(*s_a);
	eject_two_mini(s_a, &((*first)->fst_a), min);
	push(s_a, s_b, &((*first)->fst_b), 'b');
	sort_three_values(s_a, &((*first)->fst_a), 'a');
	if ((*s_b)->nbr < (*s_b)->next->nbr)
		swap(s_b, &((*first)->fst_b), 'b');
	push(s_b, s_a, &((*first)->fst_a), 'a');
	push(s_b, s_a, &((*first)->fst_a), 'a');
	return (SUCCESS);
}

// int	sort_three_values_inv(t_lst **stack, t_lst **first, char c)
// {
// 	int	one;
// 	int	two;
// 	int	three;

// 	if (stack == NULL || size_stack(*stack) != 2)
// 		return (ERROR);
// 	one = (*stack)->nbr;
// 	two = (*stack)->next->nbr;
// 	three = (*stack)->next->next->nbr;
// 	if (!check_if_sort_inv(*stack))
// 	{
// 		if ((one < two && two < three && one < three)
// 		|| (one < two && two > three && one > three)
// 		|| (one > two && two < three && one > three))
// 		{
// 			swap(stack, first, c);
// 			if (one < two && two < three && one < three)
// 				reverse_rotate(stack, first, c);
// 			else if (one > two && two < three && one > three)
// 				rotate(stack, first, c);
// 		}
// 		else if (one < two && two > three && one < three)
// 			rotate(stack, first, c);
// 		else if (one > two && two < three && one > three)
// 			reverse_rotate(stack, first, c);
// 	}
// 	return (SUCCESS);
// }

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
		if ((one > two && two > three && one > three)
			|| (one > two && two < three && one < three))
		{
			swap(stack, first, c);
			if (one > three)
				reverse_rotate(stack, first, c);
		}
		else if ((one < two && two > three)
			|| (one > two && two < three && one > three))
		{
			reverse_rotate(stack, first, c);
			if (one < three)
				swap(stack, first, c);
			else if (one > two)
				reverse_rotate(stack, first, c);
		}
	}
	return (SUCCESS);
}
