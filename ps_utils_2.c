/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 17:10:24 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/25 11:57:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_not_good(t_lst *stack)
{
	int	nbr;
	int	here;

	nbr = 0;
	here = 0;
	while (stack->next)
	{
		nbr = stack->nbr;
		stack = stack->next;
		here++;
		if (nbr > stack->nbr)
			break ;
	}
	return (here);
}

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