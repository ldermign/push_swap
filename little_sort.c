/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 12:39:55 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/23 16:16:09 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	little_sort(t_lst **stack, t_lst **first)
{
	(void)first;
	int	i;
	int	size;

	i = 0;
	size = size_stack(*stack);
	if (check_if_good_sort(*stack))
		return ;
	if (check_if_bad_sort(*stack))
	{
		while (!check_if_good_sort(*stack))
		{
			int i = 0;
			printf("i = %d\n", i);
			rotate(stack, first, 'a');
		}
	}
}