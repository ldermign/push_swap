/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:55:17 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:56:04 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_val(t_lst *stack, int size)
{
	int		i;
	int		tmp;
	long	nbr;
	int		min;

	i = 0;
	nbr = 2147483648;
	min = 0;
	while (stack != NULL && i <= size)
	{
		tmp = stack->nbr;
		stack = stack->next;
		if (tmp < nbr)
		{
			nbr = tmp;
			min = i;
		}
		i++;
	}
	return (min);
}

int	min_with_min(t_lst *stack, int size, int no)
{
	int		i;
	int		tmp;
	long	nbr;
	int		min;

	i = 0;
	nbr = 2147483648;
	min = 0;
	while (stack != NULL && i <= size)
	{
		tmp = stack->nbr;
		stack = stack->next;
		if (tmp < nbr && tmp > no)
		{
			nbr = tmp;
			min = i;
		}
		i++;
	}
	return (min);
}

int	max_val(t_lst *stack)
{
	int		i;
	int		tmp;
	long	nbr;
	int		max;

	i = 0;
	tmp = 0;
	nbr = -2147483649;
	max = 0;
	while (stack != NULL)
	{
		tmp = stack->nbr;
		stack = stack->next;
		if (tmp > nbr)
		{
			nbr = tmp;
			max = i;
		}
		i++;
	}
	return (max);
}

int	max_with_max(t_lst *stack, int size, int no)
{
	int		i;
	int		tmp;
	long	nbr;
	int		max;

	i = 0;
	tmp = 0;
	nbr = -2147483649;
	max = 0;
	while (stack != NULL && i <= size)
	{
		tmp = stack->nbr;
		stack = stack->next;
		if (tmp > nbr && tmp < no)
		{
			nbr = tmp;
			max = i;
		}
		i++;
	}
	return (max);
}
