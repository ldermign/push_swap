/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/01 10:39:45 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int ope = 0; ///////////////////////////////////////////////////////////////////

void	init_liste_a(t_lst **begin, t_lst **first, char **tab, t_utils *uts)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (tab[i])
	{
		nbr = ft_atoi(tab[i]);
		add_nbr_back(begin, first, nbr);
		i++;
	}
	uts->size = i;
	*begin = *first;
}

int	get_stack_char(t_lst **stack, t_utils *uts)
{
	int		i;
	t_lst	*first;

	i = 0;
	first = *stack;
	uts->size = size_stack(*stack) + 1;
	uts->s_int = malloc(sizeof(int) * uts->size);
	if (uts->s_int == NULL)
		return (ERROR);
	while (i < uts->size)
	{
		uts->s_int[i] = (*stack)->nbr;
		i++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (SUCCESS);
}

int	ft_push_swap(int ac, char **av)
{
	t_lst	*s_a;
	t_lst	*s_b;
	t_first	*f;
	t_utils	*uts;

	s_a = NULL;
	s_b = NULL;
	f = NULL;
	uts = NULL;
	if (!check_arg(ac, &av[1]) || !ft_doublon(&av[1]))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	f = malloc(sizeof(t_first));
	uts = malloc(sizeof(t_utils));
	ft_bzero(uts, 0);
	init_liste_a(&s_a, &(f->fst_a), &av[1], uts);
	if (f == NULL || uts == NULL || !get_stack_char(&s_a, uts))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	afficher_deux_stack(&s_a, &s_b);
	begin_sort(&s_a, &s_b, &f, uts);
	afficher_deux_stack(&s_a, &s_b);
	afficher_infos(ac - 1);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (SUCCESS);
	else
		ft_push_swap(ac, av);
	return (SUCCESS);
}
