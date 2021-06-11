/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/11 11:58:36 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	supp_in_stack(t_lst *stack, t_lst **first)
// {
// 	t_lst *supp;

// 	if (stack == NULL)
// 		exit (0);
// 	if (first != NULL)
// 	{
// 		supp = *first;
// 		first = &stack->next;
// 		free(supp);
// 	}
// }

t_lst	*new_nbr(int nbr)
{
	t_lst	*elem;

	elem = malloc(sizeof(t_lst));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}

int	add_nbr_back(t_lst **begin, t_lst **first, int nbr)
{
	if (!(*begin))
	{
		*begin = new_nbr(nbr);
		*first = *begin;
	}
	else
	{
		*first = *begin;
		while ((*begin)->next)
			*begin = (*begin)->next;
		(*begin)->next = new_nbr(nbr);
	}
	(*begin) = *first;
	return (1);
}

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

#include <libc.h>

void	afficher_stack_a(t_lst *s_a)
{
	if (s_a == NULL)
		exit (0);
	while (s_a != NULL)
	{
		ft_printf("\t\t--> %d\n", s_a->nbr);
		s_a = s_a->next;
	}
}

int	ft_push_swap(int ac, char **av)
{
	int	size;
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
	size = ft_how_many(&av[1]);
	f = malloc(sizeof(t_first));
	init_liste_a(&s_a, &(f->fst_a), &av[1]);
	// afficher_stack_a(s_a);
	// swap(&s_a, &(f->fst_a));
	afficher_stack_a(s_a);
	rotate(&s_a, &(f->fst_a));
	afficher_stack_a(s_a);
	reverse_rotate(&s_a, &(f->fst_a));
	afficher_stack_a(s_a);
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
