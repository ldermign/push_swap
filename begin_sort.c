/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 16:12:23 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# include <libc.h>
 #define KRED  "\x1B[0;31m" // ROUGE
 #define KGRN  "\x1B[0;32m" // VERT
 #define KYEL  "\x1B[0;33m" // JAUNE
 #define KBLU  "\x1B[0;34m" // BLEU
 #define KMAG  "\x1B[0;35m" // MAGENTA
 #define KCYN  "\x1B[0;36m" // CYAN
 #define KWHT  "\x1B[0;37m" // BLANC
 #define KGRE  "\x1b[1;30m" // VERT
 #define CLR_COLOR "\x1b[0m" // CLEAR COLOR


void	afficher_une_stack(t_lst **s)
 {
 	int		i;
 	t_lst	*first;

 	i = 0;
 	first = *s;
 	if (*s == NULL)
 		exit (0);
 	while (*s != NULL)
 	{
 		printf(CLR_COLOR"\t[%d]\t--> %d\n", i, (*s)->nbr);
 		*s = (*s)->next;
 		i++;
 	}
 	*s = first;
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
	afficher_une_stack(s_a);
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
		sort_100_values_chunks(s_a, s_b, 5);
	else if (uts->size <= 500)
		sort_100_values_chunks(s_a, s_b, 11);
	return (SUCCESS);
}
