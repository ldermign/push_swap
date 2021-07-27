/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/27 15:40:44 by ldermign         ###   ########.fr       */
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
	for (int j = 0 ; j < 5 ; j++)
		printf("chk->chk[%d] = %d\n", j, chk->chk[j]);
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
	no = 2147483647;
	chk->size = size_stack(*s_a);
	chk->last_nbr = malloc(sizeof(int) * 5);
	if (chk->last_nbr == NULL)
		return ;
	while (i < 5)
	{
		tmp = chk->chk[i];
		while (tmp != 0)
		{
			// printf("size_stack = %d\n", chk->size);
			// printf("minWTmin = %d\n", min_with_min(*s_a, chk->size, min));
			// nbr = min_with_min(*s_a, chk->size, no);
			// printf("nbr = %d, min = %d, minWTmin = %d\n", nbr, min, min_with_min(*s_a, chk->size, min));
			chk->last_nbr[i] = min_with_min(*s_a, chk->size, no);
			no = chk->last_nbr[i];
			tmp--;
		}
		i++;
	}
	for (int j = 0 ; j < 5 ; j++)
		printf("chk->last_nbr[%d] = %d\n", j, chk->last_nbr[j]);
}

int	sort_100_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	(void)s_b;
	(void)uts;
	t_chk	*chk;

	chk = malloc(sizeof(t_chk));
	if (chk == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	get_chunks(s_a, chk);
	fill_chunk_know_last(s_a, chk);
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
		sort_100_values(s_a, s_b, uts);
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