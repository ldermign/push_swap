/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/03 17:26:20 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_doublon(char **tab)
{
	int				i;
	int				j;
	long long int	tmp;
	long long int	tmp2;

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
			if (tmp == tmp2 || tmp > 2147483647 || tmp2 > 2147483647
				|| tmp < -2147483648 || tmp2 < -2147483648)
				return (ERROR);
		}
		i = j + 1;
	}
	return (SUCCESS);
}

int	check_if_tab_char(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]) && str[i] != ' ' && str[i] != '-')
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

int	check_arg(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2 && !check_if_tab_char(av[1]))
		return (ERROR);
	if (ac > 2 && !ft_doublon(&av[1]))
		return (ERROR);
	if (ac > 2)
	{
		while (i != ac && av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (!ft_is_digit(av[i][j]) && av[i][j] != '-')
					return (ERROR);
				j++;
			}
			i++;
		}
	}
	return (SUCCESS);
}

int	check_tab_arg(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '-' && !ft_is_digit(tab[i][j]))
				return (ERROR);
			if (tab[i][j] == '-')
				j++;
			if (!ft_is_digit(tab[i][j]))
				return (ERROR);
			while (ft_is_digit(tab[i][j]))
			{
				j++;
				if (!ft_is_digit(tab[i][j]) && tab[i][j] != '\0')
					return (ERROR);
			}
		}
		i++;
	}
	return (SUCCESS);
}