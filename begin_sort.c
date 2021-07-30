/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/30 16:20:47 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_chunks(t_lst **s_a, t_chk *chk)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	chk->chk = malloc(sizeof(int) * 5);
	if (chk->chk == NULL)
		return ;
	chk->size = size_stack(*s_a) + 1;
	while (i < 5)
	{
		chk->chk[i] = chk->size / 5;
		i++;
	}
	i = 0;
	ret = somme(chk->chk, 5);
	while (ret != chk->size)
	{
		chk->chk[i] += 1;
		ret = somme(chk->chk, 5);
		i++;
	}
	// for (int j = 0 ; j < 5 ; j++)
	// 	printf("chk->chk[%d] = %d\n", j, chk->chk[j]);
}

void	fill_chunk_know_last(t_lst **s_a, t_chk *chk)
{
	int	i;
	int	tmp;
	int	nbr;
	int no;

	i = 0;
	tmp = 0;
	nbr = 0;
	no = -2147483648;
	chk->size = size_stack(*s_a);
	chk->last_nbr = malloc(sizeof(int) * 5);
	if (chk->last_nbr == NULL)
		return ;
	while (i < 5)
	{
		tmp = chk->chk[i];
		while (tmp != 0)
		{
			chk->last_nbr[i] = get_nbr_pos(s_a, min_with_min(*s_a, chk->size, no));
			no = chk->last_nbr[i];
			tmp--;
		}
		i++;
	}
	// for (int j = 0 ; j < 5 ; j++)
	// 	printf("chk->last_nbr[%d] = %d\n", j, chk->last_nbr[j]);
}

void	get_first_and_second(t_lst **s_a, t_chk *chk, int j)
{
	int		i;
	t_lst	*first;

	i = 0;
	first = *s_a;
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
	// printf("hold_first = %d, hold_second = %d\n", chk->hold_first, chk->hold_second);
}

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
	if (size_stack(*s_b) == 1 && (*s_b)->nbr < (*s_b)->next->nbr)
	{
		swap_b(s_b);
		return ;
	}
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
	// printf("here = %d\n", here);
	change_with_here(s_b, here);
}

void	get_in_order(t_lst **s_b, t_chk *chk)
{
	if (max_val(*s_b) != 0)
	{
		if (chk->ret < size_stack(*s_b) / 2)
		{
			while (chk->ret > 0)
			{
				rotate_b(s_b);
				chk->ret--;
			}
		}
		else
		{
			chk->ret = size_stack(*s_b) - chk->ret;
			while (chk->ret > 0)
			{
				reverse_rotate_b(s_b);
				chk->ret--;
			}
		}
	}
}

void	flip_and_push(t_lst **s_a, t_lst **s_b, t_chk *chk)
{
	int	pos;

	chk->size = size_stack(*s_a);
	if (chk->hold_first != 0 && chk->hold_second != 0
		&& chk->hold_first <= (chk->size - chk->hold_second))
	{
		pos = chk->hold_first;
		while (pos >= 0)
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
	check_order_before_push(s_b, chk, (*s_a)->nbr);
	push_b(s_a, s_b);
	if (size_stack(*s_b) >= 1 && (*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
}

void	check_witch_is_faster(t_lst **s_a, t_lst **s_b, t_chk *chk)
{
	int	next_nbr;
	int	pos_max;

	if (*s_a == NULL)
		return ;
	next_nbr = (*s_a)->nbr;
	pos_max = max_val(*s_b);
	afficher_une_stack(s_b);
	printf("next_nbr = %d, pos_max = %d, size_stack = %d\n", next_nbr, pos_max, size_stack(*s_b));
	chk->if_move1 = where_to_change(s_b, next_nbr);
	// chk->if_move2 = ;
	// printf("chk->if_move1 = %d, chk->if_move2 = %d, chk->if_move3 = %d, chk->if_move4 = %d\n", chk->if_move1, chk->if_move2, chk->if_move3, chk->if_move4);
}

void	sort_stack_with_chunks(t_lst **s_a, t_lst **s_b, t_chk *chk)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 5)
	{
		ret = chk->chk[i];
		while (ret != 0)
		{
			get_first_and_second(s_a, chk, i);
			flip_and_push(s_a, s_b, chk);
			check_witch_is_faster(s_a, s_b, chk);
			get_in_order(s_b, chk);
			ret--;
		}
		i++;
	}
}

int	sort_100_values(t_lst **s_a, t_lst **s_b)
{
	t_chk	*chk;

	chk = malloc(sizeof(t_chk));
	if (chk == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_bzero(chk, 0);
	get_chunks(s_a, chk);
	fill_chunk_know_last(s_a, chk);
	sort_stack_with_chunks(s_a, s_b, chk);
	chk->ret = max_val(*s_b) - 1;
	get_in_order(s_b, chk);
	chk->size = size_stack(*s_b);
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
	if (uts->size == 3)
		sort_three_values(s_a);
	else if (uts->size == 5)
		sort_five_values(s_a, s_b, uts);
	else if (uts->size <= 50)
		sort_50_values(s_a, s_b, uts);
	else if (uts->size <= 100)
		sort_100_values(s_a, s_b);
	// else if (uts->size <= 100)
	// 	sort_100_values(s_a, s_b, uts);
	// else if (uts->size <= 50)
	// 	sort_under_50(s_a, s_b, uts);
	// else if (uts->size <= 100)
	// 	sort_under_100(s_a, s_b, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, uts);
	// else
	// 	nightmare_size(s_a, s_b, uts);
	return (SUCCESS);
}