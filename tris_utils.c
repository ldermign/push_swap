/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 07:51:05 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/28 15:03:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	max(t_lst **stack, t_lst **f_a, t_utils *uts, int last)
{
	int		i;
	int		tmp;
	int		nbr;

	i = 0;
	tmp = 0;
	nbr = 0;
	*stack = *f_a;
	while (i < last && (*stack)->next)
	{
		tmp = (*stack)->nbr;
		*stack = (*stack)->next;
		if (tmp > nbr)
		{
			nbr = tmp;
			uts->max = i;
		}
		i++;
	}
	*stack = *f_a;
}

int	get_med(t_lst **stack)
{
	int	min;
	int	max;
	int	size;
	int	med;

	size = size_stack(*stack);
	med = 0;
	while ((*stack)->next)
	{
		
	}
	return (med);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)(size - 1))
	{
		j = 0;
		while (j + 1 && j < (int)(size - i - 1))
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int	get_info(t_utils *uts)
{
	bubble_sort(uts->s_int, uts->size);
	if ((uts->size % 2) == 0)
	{
		uts->middle = uts->size / 2;
		uts->med = ((uts->s_int[(uts->size / 2) - 1]
					+ uts->s_int[uts->size / 2]) / 2);
	}
	else
	{
		uts->middle = (uts->size + 1) / 2;
		uts->med = uts->s_int[((uts->size + 1) / 2) - 1];
	}
	return (SUCCESS);
}
