/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:59:03 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/23 15:11:25 by ldermign         ###   ########.fr       */
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
	t_lst	*ret;
	t_lst	*adrs_tmp;

	adrs_tmp = new_nbr(nbr);
	adrs_tmp->next = (*stack);
	ret = adrs_tmp;
	*stack = ret;
}

void	supp_elemt(t_lst **stack)
{
	t_lst	*tmp_add_supp;

	if (*stack == NULL)
		return ;
	tmp_add_supp = *stack;
	*stack = (*stack)->next;
	free(tmp_add_supp);
}

void	supp_last_elemt(t_lst **stack)
{
	t_lst	*first;
	t_lst	*last;
	t_lst	*tmp_add_supp;

	if (*stack == NULL)
		return ;
	first = *stack;
	while ((*stack)->next)
	{
		last = *stack;
		*stack = (*stack)->next;
	}
	tmp_add_supp = *stack;
	last->next = NULL;
	free(tmp_add_supp);
	*stack = first;
}