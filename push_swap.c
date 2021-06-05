/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/05 14:38:26 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	supp_in_stack(t_liste *stack)
{
	t_liste *supp;

	if (stack == NULL)
		exit (0);
	if (stack->first != NULL)
	{
		supp = stack->first;
		stack->first = stack->next;
		free(supp);
	}
}

void	init_stack_a(t_liste *stk_a, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		stk_a->nbr = atoi(tab[i]);
		stk_a->next = stk_a->first;
		stk_a->first = stk_a;
		i++;
	}
}

t_liste	*init_liste(char **tab)
{
	t_liste	*stack;

	stack = malloc(sizeof(*stack));
	if (stack == NULL)
		return (ERROR);
	stack->nbr = 0;
	stack->next = NULL;
	stack->first = stack;
	return (stack);
}

void	afficher_stack_a(t_liste *stk_a)
{
	t_liste	
	if (stk_a == NULL)
		exit (0);
	
}

int	ft_push_swap(int ac, char **av)
{
	int	size;
	t_liste	*stk_a;
	t_liste	*stk_b;

	if (!check_arg(ac, &av[1]) || !ft_doublon(&av[1]))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	size = ft_how_many(&av[1]);
	stk_a = init_liste(&av[1]);
	stk_b = init_liste(&av[1]);
	init_stack_a(stk_a, &av[1]);
	afficher_stack_a(stk_a);
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