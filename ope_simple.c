/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:15:42 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/11 12:00:12 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack, t_lst **first)
{
	int	tmp_nbr;
	int	tmp_nbr2;

	tmp_nbr = (*stack)->nbr;
	*stack = (*stack)->next;
	tmp_nbr2 = (*stack)->nbr;
	(*stack)->nbr = tmp_nbr;
	(*stack) = (*first);
	(*stack)->nbr = tmp_nbr2;
	ft_printf("swap\n");
}

void	push(void *v)
{
	(void)v;
}

#include <libc.h>

void	rotate(t_lst **stack, t_lst **first)
{
	int	tmp_nbr;
	int	first_nbr;

	first_nbr = (*first)->nbr;
	while ((*stack)->next)
	{
		tmp_nbr = (*stack)->next->nbr;
		(*stack)->nbr = tmp_nbr;
		*stack = (*stack)->next;
	}
	(*stack)->nbr = first_nbr;
	*stack = *first;
	ft_printf("rotate\n");
}

void	reverse_rotate(t_lst **stack, t_lst **first)
{
	int	tmp_nbr;
	int	previous;
	int	last_nbr;

	while ((*stack)->next)
		*stack = (*stack)->next;
	last_nbr = (*stack)->nbr;
	*stack = *first;
	previous = last_nbr;
	while ((*stack)->next)
	{
		tmp_nbr = (*stack)->nbr;
		(*stack)->nbr = previous;
		*stack = (*stack)->next;
		previous = (*stack)->nbr;
		(*stack)->nbr = tmp_nbr;
	}
	*stack = *first;
	(*stack)->nbr = last_nbr;
	ft_printf("reverse rotate\n");
}
