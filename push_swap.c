/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/04 12:03:50 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	if (!check_arg(ac, av) || !ft_doublon(ac, av))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	size = ft_how_many(ac, av);
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