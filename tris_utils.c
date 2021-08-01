/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 07:51:05 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:56:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	somme(int *all, int size)
{
	int	i;
	int	somme;

	i = 0;
	somme = 0;
	while (i < size)
	{
		somme += all[i];
		i++;
	}
	return (somme);
}
