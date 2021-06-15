/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:15:42 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/15 22:05:45 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack, t_lst **first)
{
	t_lst	*first_add;
	t_lst	*second_add;
	t_lst	*third_add;

	if (size_stack(*stack) < 1)
		return ;
	first_add = *stack;
	second_add = first_add->next;
	third_add = second_add->next;
	first_add->next = third_add;
	second_add->next = first_add;
	*first = second_add;
	*stack = *first;
	ft_printf("s\n");
}

void	push(t_lst **s_give, t_lst **s_get, t_lst **f_get)
{
	t_lst	*tmp_add_supp;

	if (*s_give == NULL)
		return ;
	add_nbr_front(s_get, f_get, (*s_give)->nbr);
	tmp_add_supp = *s_give;
	*s_give = (*s_give)->next;
	free(tmp_add_supp);
	ft_printf("p\n");
}

void	rotate(t_lst **stack, t_lst **first)
{
	t_lst	*address_prev;

	if (size_stack(*stack) < 1)
		return ;
	address_prev = *first;
	*first = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = address_prev;
	address_prev->next = NULL;
	*stack = *first;
	ft_printf("r\n");
}

void	reverse_rotate(t_lst **stack, t_lst **first)
{
	t_lst	*address_prev;

	if (size_stack(*stack) < 1)
		return ;
	while ((*stack)->next)
	{
		address_prev = *stack;
		*stack = (*stack)->next;
	}
	(*stack)->next = *first;
	address_prev->next = NULL;
	ft_printf("rr\n");
}