/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/15 19:45:23 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_doublon(char **tab)
{
	int	i;
	int	j;
	int	tmp;
	int	tmp2;

	i = 0;
	j = 0;
	while (tab[i] && tab[i + 1])
	{
		j = i;
		tmp = ft_atoi(tab[i]);
		while (tab[i + 1])
		{
			i++;
			tmp2 = ft_atoi(tab[i]);
			if (tmp == tmp2)
				return (ERROR);
		}
		i = j + 1;
	}
	return (SUCCESS);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (i != ac && av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_is_digit(av[i][j]))
				return (ERROR);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
