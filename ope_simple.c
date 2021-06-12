/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:15:42 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/12 18:28:25 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack, t_lst **first)
{
	t_lst	*first_add;
	t_lst	*second_add;
	t_lst	*third_add;

	first_add = *stack;
	second_add = (*stack)->next;
	*stack = (*stack)->next;
	third_add = (*stack)->next;
	*first = *stack;
	ft_printf("swap\n");
}

void	push(void *v)
{
	(void)v;
}

void	rotate(t_lst **stack, t_lst **first)
{
	t_lst	*address_prev;

	address_prev = *first;
	*first = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = address_prev;
	address_prev->next = NULL;
	*stack = *first;
	ft_printf("rotate\n");
}

void	reverse_rotate(t_lst **stack, t_lst **first)
{
	t_lst	*address_prev;

	while ((*stack)->next)
	{
		address_prev = *stack;
		*stack = (*stack)->next;
	}
	(*stack)->next = *first;
	address_prev->next = NULL;
	ft_printf("reverse rotate\n");
}
