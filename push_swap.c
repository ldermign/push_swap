/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/13 18:18:58 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_liste_a(t_lst **begin, t_lst **first, char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		add_nbr_back(begin, first, ft_atoi(tab[i]));
		i++;
	}
}

int	ft_push_swap(int ac, char **av)
{
	t_lst *s_a;
	t_lst *s_b;
	t_first *f;

	s_a = NULL;
	s_b = NULL;
	f = NULL;
	if (!check_arg(ac, &av[1]) || !ft_doublon(&av[1]))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	f = malloc(sizeof(t_first));
	init_liste_a(&s_a, &(f->fst_a), &av[1]);
	afficher_deux_stack(s_a, s_b);
	swap(&s_a, &(f->fst_a));				// swap
	afficher_une_stack(s_a);
	rotate(&s_a, &(f->fst_a));			// rotate
	afficher_une_stack(s_a);
	reverse_rotate(&s_a, &(f->fst_a));	// reverse rotate
	afficher_une_stack(s_a);
	push(&s_a, &s_b, &(f->fst_b));
	afficher_deux_stack(s_a, s_b);
	push(&s_a, &s_b, &(f->fst_b));
	afficher_deux_stack(s_a, s_b);
	push(&s_a, &s_b, &(f->fst_b));
	afficher_deux_stack(s_a, s_b);
	swap_ss(&s_a, &s_b, f);
	afficher_deux_stack(s_a, s_b);
	rotate_rr(&s_a, &s_b, f);
	afficher_deux_stack(s_a, s_b);
	reverse_rotate_rrr(&s_a, &s_b, f);
	afficher_deux_stack(s_a, s_b);
	return (SUCCESS);
}

int main(int ac, char **av)
{
	if (ac <= 1)
		return (SUCCESS);
	else
		ft_push_swap(ac, av);
	return (SUCCESS);
}
