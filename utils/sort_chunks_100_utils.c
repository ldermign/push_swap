/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks_100_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 12:03:49 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:24:40 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	where_to_change(t_lst **s_b, int nbr_push)
{
	int		pos;
	int		before;
	int		after;
	t_lst	*first;

	pos = 0;
	first = *s_b;
	if (size_stack(*s_b) <= 1)
		return (0);
	while ((*s_b)->next != NULL)
	{
		before = (*s_b)->nbr;
		*s_b = (*s_b)->next;
		after = (*s_b)->nbr;
		if (before > nbr_push && nbr_push > after)
		{
			*s_b = first;
			return (pos);
		}
		pos++;
	}
	*s_b = first;
	return (pos);
}

void	change_with_here(t_lst **s_b, int here)
{
	if (here == 0)
		return ;
	if (here < size_stack(*s_b) / 2)
	{
		while (here >= 0)
		{
			rotate_b(s_b);
			here--;
		}
	}
	else
	{
		here = size_stack(*s_b) - here;
		while (here >= 0)
		{
			reverse_rotate_b(s_b);
			here--;
		}
	}
}

void	get_chunks(t_lst **s_a, t_chk *chk, int size)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	chk->chk = malloc(sizeof(int) * size);
	if (chk->chk == NULL)
		return ;
	chk->size = size_stack(*s_a) + 1;
	while (i < size)
	{
		chk->chk[i] = chk->size / size;
		i++;
	}
	i = 0;
	ret = somme(chk->chk, size);
	while (ret != chk->size)
	{
		chk->chk[i] += 1;
		ret = somme(chk->chk, size);
		i++;
	}
}

void	fill_chunk_know_last(t_lst **s_a, t_chk *chk, int size)
{
	int	i;
	int	tmp;
	int	nbr;
	int	no;

	i = 0;
	tmp = 0;
	nbr = 0;
	no = -2147483648;
	chk->size = size_stack(*s_a);
	chk->last_nbr = malloc(sizeof(int) * size);
	if (chk->last_nbr == NULL)
		return ;
	while (i < size)
	{
		tmp = chk->chk[i];
		while (tmp != 0)
		{
			chk->last_nbr[i] = get_nbr_pos(s_a,
					min_with_min(*s_a, chk->size, no));
			no = chk->last_nbr[i];
			tmp--;
		}
		i++;
	}
}

void	check_order_before_push(t_lst **s_b, t_chk *chk, int nbr_push)
{
	int	here;
	int	before;
	int	after;

	if (*s_b == NULL || size_stack(*s_b) == 0)
		return ;
	here = 0;
	chk->ret = 0;
	before = (*s_b)->nbr;
	after = (*s_b)->next->nbr;
	if (get_nbr_pos(s_b, min_val(*s_b, size_stack(*s_b))) > nbr_push)
	{
		while (min_val(*s_b, size_stack(*s_b) != size_stack(*s_b)))
			reverse_rotate_b(s_b);
		return ;
	}
	if (get_nbr_pos(s_b, max_val(*s_b)) < nbr_push)
	{
		while (max_val(*s_b) != 0)
			reverse_rotate_b(s_b);
		return ;
	}
	here = where_to_change(s_b, nbr_push);
	change_with_here(s_b, here);
}
