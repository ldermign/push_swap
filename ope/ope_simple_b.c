/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_simple_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:40:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:40:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_lst **s_b)
{
	t_lst	*ret;
	t_lst	*first_add;
	t_lst	*second_add;
	t_lst	*third_add;

	if (size_stack(*s_b) < 1)
		return ;
	first_add = *s_b;
	second_add = first_add->next;
	third_add = second_add->next;
	first_add->next = third_add;
	second_add->next = first_add;
	ret = second_add;
	*s_b = ret;
	ft_printf("sb\n");
}

void	push_b(t_lst **s_a, t_lst **s_b)
{
	t_lst	*tmp_add_supp;

	if (*s_a == NULL)
		return ;
	add_nbr_front(s_b, (*s_a)->nbr);
	tmp_add_supp = *s_a;
	*s_a = (*s_a)->next;
	free(tmp_add_supp);
	ft_printf("pb\n");
}

void	rotate_b(t_lst **s_b)
{
	t_lst	*ret;
	t_lst	*address_prev;

	if (size_stack(*s_b) < 1)
		return ;
	address_prev = *s_b;
	ret = (*s_b)->next;
	while ((*s_b)->next)
		*s_b = (*s_b)->next;
	(*s_b)->next = address_prev;
	address_prev->next = NULL;
	*s_b = ret;
	ft_printf("rb\n");
}

void	reverse_rotate_b(t_lst **s_b)
{
	t_lst	*address_prev;
	t_lst	*futur_second;

	if (size_stack(*s_b) < 2)
		return ;
	futur_second = *s_b;
	while ((*s_b)->next)
	{
		address_prev = *s_b;
		*s_b = (*s_b)->next;
	}
	(*s_b)->next = futur_second;
	address_prev->next = NULL;
	ft_printf("rrb\n");
}
