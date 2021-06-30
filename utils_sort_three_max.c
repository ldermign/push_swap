/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:10:24 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/30 13:15:16 by ldermign         ###   ########.fr       */
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

void	by_order(t_utils *uts)
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
