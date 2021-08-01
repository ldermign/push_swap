/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 14:42:34 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/01 14:54:18 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_sort(t_lst *stack)
{
	int	nbr_tmp;

	nbr_tmp = 0;
	if (stack == NULL)
		return (ERROR);
	while (stack->next)
	{
		nbr_tmp = stack->nbr;
		stack = stack->next;
		if (nbr_tmp > stack->nbr)
			return (ERROR);
	}
	return (SUCCESS);
}

int	check_if_sort_inv(t_lst *stack)
{
	int	nbr_tmp;

	nbr_tmp = 0;
	if (stack == NULL)
		return (ERROR);
	while (stack->next)
	{
		nbr_tmp = stack->nbr;
		stack = stack->next;
		if (nbr_tmp < stack->nbr)
			return (ERROR);
	}
	return (SUCCESS);
}

int	size_stack(t_lst *stack)
{
	int	size;

	size = 0;
	if (stack == NULL)
		return (size);
	while (stack->next)
	{
		stack = stack->next;
		size++;
	}
	return (size);
}

int	get_nbr_pos(t_lst **stack, int pos)
{
	int		i;
	int		nbr;
	t_lst	*first;

	i = 0;
	nbr = 0;
	first = *stack;
	while ((*stack)->nbr && i < pos)
	{
		*stack = (*stack)->next;
		i++;
	}
	nbr = (*stack)->nbr;
	*stack = first;
	return (nbr);
}

int	get_pos_nbr(t_lst **stack, int pos)
{
	int		i;
	int		nbr;
	t_lst	*first;

	i = 0;
	nbr = 0;
	first = *stack;
	while ((*stack)->nbr && i < pos)
	{
		*stack = (*stack)->next;
		i++;
	}
	nbr = (*stack)->nbr;
	*stack = first;
	return (nbr);
}
