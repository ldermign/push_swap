/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:10:24 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/23 17:15:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many_not_good(t_lst *stack)
{
	int	tmp;
	int	nbr;

	tmp = 0;
	nbr = 0;
	while (stack->next)
	{
		tmp = stack->nbr;
		stack = stack->next;
		if (tmp > stack->nbr)
			nbr++;
	}
	return (nbr);
}