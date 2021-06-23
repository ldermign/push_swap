/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:15:42 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/23 16:53:14 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst **stack, t_lst **first, char s)
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
	ft_printf("p%c\n", s);
}

void	push(t_lst **s_give, t_lst **s_get, t_lst **f_get, char s)
{
	t_lst	*tmp_add_supp;

	if (*s_give == NULL)
		return ;
	add_nbr_front(s_get, f_get, (*s_give)->nbr);
	tmp_add_supp = *s_give;
	*s_give = (*s_give)->next;
	free(tmp_add_supp);
	ft_printf("p%c\n", s);
}

void	rotate(t_lst **stack, t_lst **first, char s)
{
	t_lst	*address_prev;

	if (size_stack(*stack) < 2)
		return ;
	address_prev = *stack;
	*first = (*stack)->next;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = address_prev;
	address_prev->next = NULL;
	*stack = *first;
	ft_printf("r%c\n", s);
}

void	reverse_rotate(t_lst **stack, t_lst **first, char s)
{
	t_lst	*address_prev;
	t_lst	*futur_second;

	if (size_stack(*stack) < 2)
		return ;
	futur_second = *stack;
	while ((*stack)->next)
	{
		address_prev = *stack;
		*stack = (*stack)->next;
	}
	*first = *stack;
	(*stack)->next = futur_second;
	address_prev->next = NULL;
	ft_printf("rr%c\n", s);
}