/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/02 18:50:26 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <libc.h>

int	get_char_in_int(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	(void)str;
	// while (str[i])
	// {

	// 	i++;
	// }
	return (SUCCES);
}

int	init_liste_a(t_lst **begin, int ac, char **tab)
{
	int		i;
	int		nbr;
	t_lst	*ret;

	i = 1;
	nbr = 0;
	ret = *begin;
	if (ac == 2)
	{
		if (!get_char_in_int(tab[1]))
			return (ERROR);
		return (SUCCESS);
	}
	while (tab[i])
	{
		nbr = ft_atoi(tab[i]);
		add_nbr_back(begin, nbr);
		i++;
	}
	return (SUCCESS);
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
	if (!check_arg(ac, av) || !init_liste_a(&s_a, ac, av))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	uts = malloc(sizeof(t_utils));
	ft_bzero(uts, 0);
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
