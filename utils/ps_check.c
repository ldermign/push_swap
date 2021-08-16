/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:59 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/16 19:19:32 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <libc.h>
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
		tmp = ft_atol(tab[i]);
		while (tab[i + 1])
		{
			i++;
			tmp2 = ft_atol(tab[i]);
			if (tmp == tmp2 || ft_len_int(tmp) > 10 || ft_len_int(tmp2) > 10
				|| tmp > 2147483647 || tmp < -2147483648
				|| tmp2 > 2147483647 || tmp2 < -2147483648)
				return (ERROR);
		}
		i = j + 1;
	}
	return (SUCCESS);
}

int	ft_doublon_char(char *str, int i, int j)
{
	long long int	tmp;
	long long int	tmp2;

	i = 0;
	j = 0;
	while (str[i])
	{
		tmp = ft_atol(&(str[i]));
		while (str[i] && (ft_is_digit(str[i]) || str[i] == '-'))
			i++;
		if (str[i] == ' ')
			i++;
		j = i;
		while (str[j])
		{
			tmp2 = ft_atol(&str[j]);
			if (tmp == tmp2 || tmp > 2147483647 || tmp < -2147483648
				|| tmp2 > 2147483647 || tmp2 < -2147483648)
				return (ERROR);
			while (str[j] && (ft_is_digit(str[j]) || str[j] == '-'))
				j++;
			if (str[j] == ' ')
				j++;
		}
	}
	return (SUCCESS);
}

int	check_if_tab_char(char *str)
{
	int	i;
	int	ret;

	i = 0;
	while (str[i])
	{
		if (!ft_is_digit(str[i]) && str[i] != '-')
			return (ERROR);
		if (str[i] == '-')
			i++;
		ret = 0;
		if (!ft_is_digit(str[i]))
			return (ERROR);
		while (ft_is_digit(str[i]) && ++ret)
			i++;
		if ((str[i] != ' ' && str[i] != '\0') || ret > 10)
			return (ERROR);
		if (str[i] == ' ' && str[i + 1])
			i++;
	}
	if (!ft_doublon_char(str, i, ret))
		return (ERROR);
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
