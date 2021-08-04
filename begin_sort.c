/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/04 19:16:13 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_100_values_chunks(t_lst **s_a, t_lst **s_b, int size)
{
	t_chk	*chk;

	chk = malloc(sizeof(t_chk));
	if (chk == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_bzero(chk, 0);
	// afficher_deux_stack(s_a, s_b);
	get_chunks(s_a, chk, size);
	fill_chunk_know_last(s_a, chk, size);
	sort_stack_with_chunks(s_a, s_b, chk, size);
	chk->ret = max_val(*s_b) - 1;
	get_in_order(s_b, chk);
	chk->size = size_stack(*s_b);
	// afficher_deux_stack(s_a, s_b);
	while (chk->size >= 0)
	{
		push_a(s_b, s_a);
		chk->size--;
	}
	return (1);
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	get_info(uts);
	if (check_if_sort(*s_a))
		return (SUCCESS);
	if (uts->size == 2)
	{
		if ((*s_a)->nbr > (*s_a)->next->nbr)
			swap_a(s_a);
		return (SUCCESS);
	}
	if (uts->size == 3)
		sort_three_values(s_a);
	if (uts->size == 4)
	{
		while (min_val(*s_a, size_stack(*s_a)) != 0)
			rotate_a(s_a);
		push_b(s_a, s_b);
		sort_three_values(s_a);
		push_a(s_b, s_a);
	}
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, uts);
	// else if (uts->size <= 50)
	// 	sort_50_values(s_a, s_b, uts);
	else if (uts->size <= 100)
		sort_100_values_chunks(s_a, s_b, 5);
	else if (uts->size <= 500)
		sort_100_values_chunks(s_a, s_b, 11);
	// afficher_deux_stack(s_a, s_b);
	return (SUCCESS);
}
