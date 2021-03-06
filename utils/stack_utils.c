/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:03 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/10 16:18:05 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_lst(t_lst *stack)
{
	t_lst	*tmp;

	if (!stack)
		return ;
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
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

void	add_nbr_back(t_lst **stack, int nbr)
{
	t_lst	*ret;

	if (!(*stack))
	{
		*stack = new_nbr(nbr);
		ret = *stack;
	}
	else
	{
		ret = *stack;
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = new_nbr(nbr);
	}
	*stack = ret;
}

void	add_nbr_front(t_lst **stack, int nbr)
{
	t_lst	*adrs_tmp;

	adrs_tmp = new_nbr(nbr);
	adrs_tmp->next = (*stack);
	*stack = adrs_tmp;
}
