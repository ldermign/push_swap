/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_simu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 19:52:04 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/09 13:46:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simu_rotate_a(t_lst **rad_a, t_lst **rad_ope)
{
	t_lst	*ret;
	t_lst	*address_prev;

	if (size_stack(*rad_a) < 2)
		return ;
	address_prev = *rad_a;
	ret = (*rad_a)->next;
	while ((*rad_a)->next)
		*rad_a = (*rad_a)->next;
	(*rad_a)->next = address_prev;
	address_prev->next = NULL;
	*rad_a = ret;
	add_nbr_back(rad_ope, 0);
}

void	simu_push_b(t_lst **rad_a, t_lst **rad_b, t_lst **rad_ope)
{
	t_lst	*tmp_add_supp;

	if (*rad_a == NULL)
		return ;
	add_nbr_front(rad_b, (*rad_a)->nbr);
	tmp_add_supp = *rad_a;
	*rad_a = (*rad_a)->next;
	free(tmp_add_supp);
	add_nbr_back(rad_ope, 1);
}

void	simu_push_a(t_lst **rad_b, t_lst **rad_a, t_lst **rad_ope)
{
	t_lst	*tmp_add_supp;

	if (*rad_b == NULL)
		return ;
	add_nbr_front(rad_a, (*rad_b)->nbr);
	tmp_add_supp = *rad_b;
	*rad_b = (*rad_b)->next;
	free(tmp_add_supp);
	add_nbr_back(rad_ope, 2);
}
