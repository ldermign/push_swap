/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/04 15:03:54 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_liste(char **tab)
{
	t_liste	*liste_a;
	t_liste	*liste_b;

	liste_a = malloc(sizeof(*liste_a));
	liste_b = malloc(sizeof(*liste_b));
	if (liste_a == NULL || liste_b == NULL)
		return (ERROR);
	liste_a->nbr = 0;
	liste_b->nbr = 0;
	liste_a->next = NULL;
	liste_b->next = NULL;
	liste_a->first = liste_a;
	liste_b->first = liste_b;
}

int	ft_push_swap(int ac, char **av)
{
	int	size;

	if (!check_arg(ac, &av[1]) || !ft_doublon(&av[1]))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	size = ft_how_many(&av[1]);
	if (!init_liste(&av[1]))
		return (ERROR);
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