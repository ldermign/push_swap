/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/20 16:27:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_lst **s_a, t_lst *f_a)
{
	int		i;
	int		tmp;
	int		max;

	i = 0;
	*s_a = f_a;
	while ((*s_a)->next)
	{
		tmp = (*s_a)->nbr;
		printf("tmp\n");
		*s_a = (*s_a)->next;
		printf("next\n");
		i++;
		printf("i\n");
		if (tmp < (*s_a)->nbr)
			max = i;
		printf("fin\n");
	}
	*s_a = f_a;
	return (max);
}

void	nightmare_size(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{	
	(void)s_b;
	int	i;
	int	j;

	i = 0;
	j = 0;
	get_info(uts);
	uts->max = max(s_a, (*first)->fst_a);
	printf("uts->max = %d, uts->med = %f\n", uts->max, uts->med);
	if (uts->max < uts->middle)
	{
		while (j < uts->max)
		{
			rotate(s_a, &((*first)->fst_a), 'a');
			j++;
		}
	}
	else
	{
		while (j < (uts->size - uts->max))
		{
			reverse_rotate(s_a, &((*first)->fst_a), 'a');
			j++;
		}
	}
}

void	begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts)
{
	(void)s_a;
	(void)s_b;
	(void)first;
	(void)uts;
	// if (uts->size <= 10)
	// 	little_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 100)
	// 	medium_size(&s_a, &s_b, first, uts);
	// else if (uts->size <= 500)
	// 	big_size(&s_a, &s_b, first, uts);
	// else
		nightmare_size(s_a, s_b, first, uts);
}