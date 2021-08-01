/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_simple.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:15:42 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:40:29 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_lst **s_a)
{
	t_lst	*ret;
	t_lst	*first_add;
	t_lst	*second_add;
	t_lst	*third_add;

	if (size_stack(*s_a) < 1)
		return ;
	first_add = *s_a;
	second_add = first_add->next;
	third_add = second_add->next;
	first_add->next = third_add;
	second_add->next = first_add;
	ret = second_add;
	*s_a = ret;
	ft_printf("sa\n");
}

void	push_a(t_lst **s_b, t_lst **s_a)
{
	t_lst	*tmp_add_supp;

	if (*s_b == NULL)
		return ;
	add_nbr_front(s_a, (*s_b)->nbr);
	tmp_add_supp = *s_b;
	*s_b = (*s_b)->next;
	free(tmp_add_supp);
	ft_printf("pa\n");
}

void	rotate_a(t_lst **s_a)
{
	t_lst	*ret;
	t_lst	*address_prev;

	if (size_stack(*s_a) < 2)
		return ;
	address_prev = *s_a;
	ret = (*s_a)->next;
	while ((*s_a)->next)
		*s_a = (*s_a)->next;
	(*s_a)->next = address_prev;
	address_prev->next = NULL;
	*s_a = ret;
	ft_printf("ra\n");
}

void	reverse_rotate_a(t_lst **s_a)
{
	t_lst	*address_prev;
	t_lst	*futur_second;

	if (size_stack(*s_a) < 1)
		return ;
	futur_second = *s_a;
	while ((*s_a)->next)
	{
		address_prev = *s_a;
		*s_a = (*s_a)->next;
	}
	(*s_a)->next = futur_second;
	address_prev->next = NULL;
	ft_printf("rra\n");
}
