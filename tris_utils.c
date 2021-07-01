/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 07:51:05 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/01 15:47:03 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbr_pos(t_lst **stack, int pos)
{
	int		i;
	t_lst	*first;

	i = 0;
	first = *stack;
	while ((*stack)->nbr && i < pos)
	{
		*stack = (*stack)->next;
		i++;
	}
	pos = (*stack)->nbr;
	*stack = first;
	return (pos);
}

int	max_val(t_lst *stack)
{
	int		i;
	int		tmp;
	int		nbr;
	int		max;

	i = 0;
	tmp = 0;
	nbr = 0;
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

int	max_with_max(t_lst *stack, int no)
{
	int		i;
	int		tmp;
	int		nbr;
	int		max;

	i = 0;
	tmp = 0;
	nbr = 0;
	max = 0;
	while (stack != NULL)
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

int	get_med(t_lst **stack)
{
	// int	min;
	// int	max;
	int	size;
	int	med;

	size = size_stack(*stack);
	med = 0;
	while ((*stack)->next)
	{
		
	}
	return (med);
}

void	bubble_sort(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)(size - 1))
	{
		j = 0;
		while (j + 1 && j < (int)(size - i - 1))
		{
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}

int	get_info(t_utils *uts)
{
	bubble_sort(uts->s_int, uts->size);
	if ((uts->size % 2) == 0)
	{
		uts->middle = uts->size / 2;
		uts->med = ((uts->s_int[(uts->size / 2) - 1]
					+ uts->s_int[uts->size / 2]) / 2);
	}
	else
	{
		uts->middle = (uts->size + 1) / 2;
		uts->med = uts->s_int[((uts->size + 1) / 2) - 1];
	}
	return (SUCCESS);
}


int	pos_not_good(t_lst *stack)
{
	int	nbr;
	int	here;

	nbr = 0;
	here = 0;
	while (stack->next)
	{
		nbr = stack->nbr;
		stack = stack->next;
		here++;
		if (nbr > stack->nbr)
			break ;
	}
	return (here);
}

int	how_many_not_good(t_lst *stack)
{
	int	tmp;
	int	nbr;

	tmp = 0;
	nbr = 0;
	while (stack->next)
	{
		tmp = stack->nbr;
		stack = stack->next;
		if (tmp > stack->nbr)
			nbr++;
	}
	return (nbr);
}