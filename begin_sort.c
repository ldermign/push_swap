/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/26 16:31:55 by ldermign         ###   ########.fr       */
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
}

int	sort_100_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	t_chk	*chk;

	chk = malloc(sizeof(t_chk));
	if (chk == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	(void)s_a;
	(void)s_b;
	(void)uts;
	get_chunks(s_a, chk);
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