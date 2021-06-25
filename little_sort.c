/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/25 12:12:44 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		three_values(t_lst **stack, t_lst **first)
{
	int	i;
	int	pos;

	i = 0;
	if (!check_if_sort(*stack))
	{
		pos = pos_not_good(*stack);
		if (pos == 1)
			swap(stack, first, 'a');
		if (pos == 2)
			reverse_rotate(stack, first, 'a');
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
