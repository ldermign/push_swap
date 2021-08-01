/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:51:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_liste_a(t_lst **begin, char **tab)
{
	int		i;
	int		nbr;
	t_lst	*ret;

	i = 0;
	nbr = 0;
	ret = *begin;
	while (tab[i])
	{
		nbr = ft_atoi(tab[i]);
		add_nbr_back(begin, nbr);
		i++;
	}
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
	t_utils	*uts;

	s_a = NULL;
	s_b = NULL;
	uts = NULL;
	if (!check_arg(ac, &av[1]) || !ft_doublon(&av[1]))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	uts = malloc(sizeof(t_utils));
	ft_bzero(uts, 0);
	init_liste_a(&s_a, &av[1]);
	if (uts == NULL || !get_stack_char(&s_a, uts))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	begin_sort(&s_a, &s_b, uts);
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
