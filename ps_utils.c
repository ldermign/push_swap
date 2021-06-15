/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:03 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/15 11:50:35 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_lst	*new_nbr(int nbr)
{
	t_lst	*elem;

	elem = malloc(sizeof(t_lst));
	if (!elem)
		return (NULL);
	elem->nbr = nbr;
	elem->next = NULL;
	return (elem);
}

void	add_nbr_back(t_lst **stack, t_lst **first, int nbr)
{
	if (!(*stack))
	{
		*stack = new_nbr(nbr);
		*first = *stack;
	}
	else
	{
		*first = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = new_nbr(nbr);
	}
	(*stack) = *first;
}

void	add_nbr_front(t_lst **stack, t_lst **first, int nbr)
{
	t_lst	*adrs_tmp;

	adrs_tmp = new_nbr(nbr);
	adrs_tmp->next = (*stack);
	*first = adrs_tmp;
	*stack = *first;
}
