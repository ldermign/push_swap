/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/10 12:02:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_three_values(t_lst **s_a)
{
	int	three;

	if (s_a == NULL || size_stack(*s_a) != 2)
		return (ERROR);
	three = (*s_a)->next->next->nbr;
	if (!check_if_sort(*s_a))
	{
		if ((*s_a)->nbr < (*s_a)->next->nbr && (*s_a)->next->nbr > three)
		{
			reverse_rotate_a(s_a);
			if ((*s_a)->nbr > (*s_a)->next->nbr)
				swap_a(s_a);
		}
		else if ((*s_a)->nbr > (*s_a)->next->nbr
			&& (((*s_a)->next->nbr < three && (*s_a)->nbr < three)
				|| ((*s_a)->next->nbr > three && (*s_a)->nbr > three)))
		{
			swap_a(s_a);
			if ((*s_a)->nbr > three)
				reverse_rotate_a(s_a);
		}
		else
			rotate_a(s_a);
	}
	return (SUCCESS);
}

int	sort_under_five_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	if (uts->size == 4)
	{
		while (min_val(*s_a, size_stack(*s_a)) != 0)
			rotate_a(s_a);
		push_b(s_a, s_b);
		sort_three_values(s_a);
		push_a(s_b, s_a);
		return (SUCCESS);
	}
	minimum(s_a, uts);
	eject_two_mini(s_a, s_b, uts);
	sort_three_values(s_a);
	if ((*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
	push_a(s_b, s_a);
	push_a(s_b, s_a);
	return (SUCCESS);
}

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
	get_chunks(s_a, chk, size);
	fill_chunk_know_last(s_a, chk, size);
	sort_stack_with_chunks(s_a, s_b, chk, size);
	chk->ret = max_val(*s_b) - 1;
	get_in_order(s_b, chk);
	chk->size = size_stack(*s_b);
	while (chk->size >= 0)
	{
		push_a(s_b, s_a);
		chk->size--;
	}
	free(chk->chk);
	free(chk->last_nbr);
	free(chk);
	return (1);
}

void	sort_500_values_radix(t_lst **s_a, t_lst **s_b, t_lst **rad)
{
	t_lst	*rad_b;
	t_lst	*rad_ope;

	rad_b = NULL;
	rad_ope = NULL;
	get_list_nbr(s_a, rad);
	get_operations(rad, &rad_b, &rad_ope);
	while (rad_ope != NULL)
	{
		if (rad_ope != NULL && rad_ope->nbr == 0)
		{
			rotate_a(s_a);
			rad_ope = rad_ope->next;
		}
		if (rad_ope != NULL && rad_ope->nbr == 1)
		{
			push_b(s_a, s_b);
			rad_ope = rad_ope->next;
		}
		if (rad_ope != NULL && rad_ope->nbr == 2)
		{
			push_a(s_b, s_a);
			rad_ope = rad_ope->next;
		}
	}
	free(rad_b);
	free(rad_ope);
	// ft_lstclear(&rad_b, free);
	// ft_lstclear(&rad_ope, free);
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	t_lst	*rad;

	rad = NULL;
	get_info(uts);
	if (check_if_sort(*s_a))
		return (SUCCESS);
	else if (uts->size == 2)
	{
		if ((*s_a)->nbr > (*s_a)->next->nbr)
			swap_a(s_a);
	}
	else if (uts->size == 3)
		sort_three_values(s_a);
	if (uts->size <= 5)
		sort_under_five_values(s_a, s_b, uts);
	else if (uts->size <= 100)
		sort_100_values_chunks(s_a, s_b, 10);
	else if (uts->size <= 500)
		sort_500_values_radix(s_a, s_b, &rad);
	free(uts->s_int);
	free(uts);
	free(rad);
	// ft_lstclear(&rad, free);
	return (SUCCESS);
}
