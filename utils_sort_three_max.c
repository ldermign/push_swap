/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort_three_max.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:10:24 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:59:11 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	little(int one, int two, int three)
{
	int	little;

	little = 0;
	if (one < two && one < three)
		little = one;
	else if (two < one && two < three)
		little = two;
	else if (three < one && three < two)
		little = three;
	return (little);
}

int	medium(int one, int two, int three)
{
	int	medium;

	medium = 0;
	if ((one < two && one > three) || (one > two && one < three))
		medium = one;
	else if ((two < one && two > three) || (two > one && two < three))
		medium = two;
	else if ((three < one && three > two) || (three > one && three < two))
		medium = three;
	return (medium);
}

int	big(int one, int two, int three)
{
	int	big;

	big = 0;
	if (one > two && one > three)
		big = one;
	else if (two > one && two > three)
		big = two;
	else if (three > one && three > two)
		big = three;
	return (big);
}

void	bubble(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < (int)(size - 1))
	{
		j = 0;
		while (j + 1 && j < (int)(size - i - 1))
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}
