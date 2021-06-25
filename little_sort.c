/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/25 13:35:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		three_values(t_lst **stack, t_lst **first)
{
	int	one;
	int	two;
	int	three;
	int	pos;

	one = (*stack)->nbr;
	two = (*stack)->next->nbr;
	three = (*stack)->next->next->nbr;
	if (!check_if_sort(*stack))
	{
		pos = pos_not_good(*stack);
		if (pos == 2 && one < two && one > three)
			reverse_rotate(stack, first, 'a');
		if (pos == 1)
		{
			if (one > two && two > three)
			{
				swap(stack, first, 'a');
				reverse_rotate(stack, first, 'a');
			}
			else if (one > two && two < three)
				rotate(stack, first, 'a');
			if (one < three && !check_if_sort(*stack))
				swap(stack, first, 'a');
			if (!check_if_sort(*stack))
				reverse_rotate(stack, first, 'a');
		}
	}
	return (SUCCESS);
}

void	go_up(t_lst **stack, t_lst **first, int size, char s)
{
	(void)size;
	int	i;
	int	pos;

	i = 0;
	pos = pos_not_good(*stack);
	if (!check_if_sort(*stack))
	{
		if (pos == 1)
		{
			printf("test\n");
			swap(stack, first, s);
			return ;
		}
		while (i < pos)
		{
			rotate(stack, first, s);
			i++;
		}
		if (check_if_sort(*stack))
			return ;
		i = 0;
		// while (i < pos)
		// {
		// 	swap(stack, first, s);
		// 	reverse_rotate(stack, first, s);
		// }
	}
}

void	three_sort(t_lst **stack, t_lst **first, char s)
{
	int	i;
	int	size;
	int	wrong;

	i = 0;
	size = size_stack(*stack);
	wrong = how_many_not_good(*stack);
	printf("wrong = [%d]\n", wrong);
	if (!check_if_sort(*stack))
	{
		if (wrong == 1)
			go_up(stack, first, size, s);
		// rotate(stack, first, 'a');
	}
}
