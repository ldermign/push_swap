/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/04 12:03:45 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_doublon(int ac, char **tab)
{
	(void)ac;
	(void)tab;
	int i;

	i = 0;
	return (SUCCESS);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
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