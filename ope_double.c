/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ope_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 08:21:30 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/23 16:20:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_lst **s_a, t_lst **s_b, t_first **first)
{
	if (size_stack(*s_a) < 1 || size_stack(*s_b) < 1)
		return ;
	swap(s_a, &((*first)->fst_a), 'a');
	swap(s_b, &((*first)->fst_b), 'b');
}

void	rotate_rr(t_lst **s_a, t_lst **s_b, t_first **first)
{
	if (size_stack(*s_a) < 1 || size_stack(*s_b) < 1)
		return ;
	rotate(s_a, &((*first)->fst_a), 'a');
	rotate(s_b, &((*first)->fst_b), 'b');
}

void	reverse_rotate_rrr(t_lst **s_a, t_lst **s_b, t_first **first)
{
	if (size_stack(*s_a) < 1 || size_stack(*s_b) < 1)
		return ;
	reverse_rotate(s_a, &((*first)->fst_a), 'a');
	reverse_rotate(s_b, &((*first)->fst_b), 'b');
}