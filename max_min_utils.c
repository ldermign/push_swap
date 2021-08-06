/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:55:17 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/06 13:47:17 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	how_many_down(t_lst *stack, int nb_stack)
{
	int	hmn;
	int	nbr;

	hmn = 0;
	nbr = 0;
	while (stack != NULL)
	{
		nbr = stack->nbr;
		// printf("%d < %d\n", nbr, nb_stack);
		if (nbr < nb_stack)
			hmn++;
		stack = stack->next;
	}
	return (hmn);
}

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
