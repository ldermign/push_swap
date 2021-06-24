/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/24 16:10:20 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_up(t_lst **stack, t_lst **first, int size)
{
	int	pos;

	pos = pos_not_good(*stack);
	while (!check_if_sort)
	{

	}
}

void	little_sort(t_lst **stack, t_lst **first)
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
			go_up(stack, first, size);
		// rotate(stack, first, 'a');
	}
}
