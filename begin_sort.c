/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/28 14:50:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	int	i;

	i = 0;
	get_info(uts);
	get_three_max(s_a, s_b, first, uts);
	sort_three_values(s_a, &((*first)->fst_a));
	afficher_deux_stack(s_a, s_b);
	
	
	
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	afficher_deux_stack(s_a, s_b);
	if (check_if_sort(*s_a))
		return (SUCCESS);
	if (uts->size == 3)
		sort_three_values(s_a, &((*first)->fst_a));
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, first);
	// if (uts->size <= 10)
	// 	little_sort(s_a, &((*first)->fst_a), 'a');
	// else if (uts->size <= 100)
	// 	medium_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	else
		nightmare_size(s_a, s_b, first, uts);
	return (SUCCESS);
}