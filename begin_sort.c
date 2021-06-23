/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/23 16:31:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 0;
	get_info(uts);
	afficher_deux_stack(s_a, s_b);
	get_last_three(s_a, s_b, first, uts);
	afficher_deux_stack(s_a, s_b);

	little_sort(s_a, &((*first)->fst_a));

	afficher_deux_stack(s_a, s_b);

	
	
}

void	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	// if (uts->size <= 10)
	// 	little_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 100)
	// 	medium_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	// else
		nightmare_size(s_a, s_b, first, uts);
}