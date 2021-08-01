/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   by_order_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:58:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:59:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	by_order_5(t_utils *uts)
{
	int	*tab;

	tab = malloc(sizeof(int) * 5);
	if (tab == NULL)
		return ;
	tab[0] = uts->pos1;
	tab[1] = uts->pos2;
	tab[2] = uts->pos3;
	tab[3] = uts->pos4;
	tab[4] = uts->pos5;
	bubble(tab, 5);
	uts->pos1 = tab[0];
	uts->pos2 = tab[1];
	uts->pos3 = tab[2];
	uts->pos4 = tab[3];
	uts->pos5 = tab[4];
	free(tab);
}

void	by_order_3(t_utils *uts)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp1 = little(uts->pos1, uts->pos2, uts->pos3);
	tmp2 = medium(uts->pos1, uts->pos2, uts->pos3);
	tmp3 = big(uts->pos1, uts->pos2, uts->pos3);
	uts->pos1 = tmp1;
	uts->pos2 = tmp2;
	uts->pos3 = tmp3;
}

void	by_order_2(t_utils *uts)
{
	int	tmp1;
	int	tmp2;

	if (uts->min1 < uts->min2)
	{
		tmp1 = uts->min1;
		tmp2 = uts->min2;
	}
	else
	{
		tmp2 = uts->min1;
		tmp1 = uts->min2;
	}
	uts->min1 = tmp1;
	uts->min2 = tmp2;
}
