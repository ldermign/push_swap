/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:21:30 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/15 11:49:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_lst **s_a, t_lst **s_b)
{
	if (size_stack(*s_a) < 1 || size_stack(*s_b) < 1)
		return ;
	swap_a(s_a);
	swap_b(s_b);
}

void	rotate_rr(t_lst **s_a, t_lst **s_b)
{
	if (size_stack(*s_a) < 1 || size_stack(*s_b) < 1)
		return ;
	rotate_a(s_a);
	rotate_b(s_b);
}

void	reverse_rotate_rrr(t_lst **s_a, t_lst **s_b)
{
	if (size_stack(*s_a) < 1 || size_stack(*s_b) < 1)
		return ;
	reverse_rotate_a(s_a);
	reverse_rotate_b(s_b);
}
