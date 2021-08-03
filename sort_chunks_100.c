/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks_100.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:02:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/03 19:25:49 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_first_and_second(t_lst **s_a, t_chk *chk, int j)
{
	int		i;
	t_lst	*first;

	i = 0;
	first = *s_a;
	// printf("last_nbr = %d\n", chk->last_nbr[j]);
	while (*s_a != NULL)
	{
		if ((*s_a)->nbr <= chk->last_nbr[j])
		{
			chk->hold_first = i;
			break ;
		}
		*s_a = (*s_a)->next;
		i++;
	}
	while (*s_a != NULL)
	{
		if ((*s_a)->nbr <= chk->last_nbr[j])
			chk->hold_second = i;
		*s_a = (*s_a)->next;
		i++;
	}
	*s_a = first;
}

void	get_in_order(t_lst **s_b, t_chk *chk)
{
	// printf("avant trs\n");
	// afficher_une_stack(s_b);
	chk->tmp = max_val(*s_b);
	// printf("size = %d, size/2 = %d, tmp = %d, size-ret = %d\n", size_stack(*s_b), size_stack(*s_b) / 2, chk->tmp, size_stack(*s_b) - chk->tmp);
	if (max_val(*s_b) != 0)
	{
		if (chk->tmp < size_stack(*s_b) / 2)
		{
			while (chk->tmp > 0)
			{
				rotate_b(s_b);
				chk->tmp--;
			}
		}
		else
		{
			chk->tmp = size_stack(*s_b) - chk->tmp;
			while (chk->tmp >= 0)
			{
				reverse_rotate_b(s_b);
				chk->tmp--;
			}
		}
	}
	// printf("apres tris\n");
	// afficher_une_stack(s_b);
}

void	rotate_before_push(t_lst **s_a, t_chk *chk)
{
	int	pos;

	chk->size = size_stack(*s_a);
	// printf("hold_first = %d, hold_second = %d\n", chk->hold_first, chk->hold_second);
	if (chk->hold_first != 0 && chk->hold_second != 0
		&& chk->hold_first <= (chk->size - chk->hold_second))
	{
		pos = chk->hold_first;
		while (pos > 0)
		{
			rotate_a(s_a);
			pos--;
		}
	}
	else if (chk->hold_first != 0 && chk->hold_second != 0
		&& chk->hold_first > (chk->size - chk->hold_second))
	{
		pos = chk->size - chk->hold_second;
		while (pos >= 0)
		{
			reverse_rotate_a(s_a);
			pos--;
		}
	}
}

void	flip_and_push(t_lst **s_a, t_lst **s_b, t_chk *chk)
{
	rotate_before_push(s_a, chk);
	check_order_before_push(s_b, chk, (*s_a)->nbr);
	push_b(s_a, s_b);
	if (min_val(*s_b, size_stack(*s_b)) == 0)
		rotate_b(s_b);
	if (size_stack(*s_b) >= 1 && (*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
}

void	sort_stack_with_chunks(t_lst **s_a, t_lst **s_b, t_chk *chk, int size)
{
	int	i;
	int	ret;

	i = 0;
	// printf("WTFFF\n");
	while (i < size)
	{
		ret = chk->chk[i];
		while (ret != 0)
		{
			get_first_and_second(s_a, chk, i);
			flip_and_push(s_a, s_b, chk);
			// afficher_une_stack(s_a);

			get_in_order(s_b, chk);
			// afficher_deux_stack(s_a, s_b);
			// if (ret == 1)
			// 	break ;
			ret--;
		}
		// if (i == 0)
		// 	break ;
		i++;
	}
	// afficher_deux_stack(s_a, s_b);
}
