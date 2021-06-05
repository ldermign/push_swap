/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:03 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/05 14:28:42 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_how_many(char **tab)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (tab[i])
	{
		i++;
		size++;
	}
	ft_printf("Size = %d.\n", size);
	return (size);
}