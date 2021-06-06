/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/06 15:09:04 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	supp_in_stack(t_liste *stack)
// {
// 	t_liste *supp;

// 	if (stack == NULL)
// 		exit (0);
// 	if (stack->first != NULL)
// 	{
// 		supp = stack->first;
// 		stack->first = stack->next;
// 		free(supp);
// 	}
// }

t_stk	*init_stack_a(t_stk *s_a, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		s_a->elmnt->nbr = ft_atoi(tab[i]);
		s_a->elmnt->next = s_a->lst->first;
		s_a->lst->first = s_a->elmnt;
		
		i++;
	}
	// s_a->elmnt->next = NULL;
	return (s_a);
}

t_stk	*init_liste(t_stk *stack)
{
	stack = malloc(sizeof(t_stk));
	stack->lst = malloc(sizeof(t_liste));
	stack->elmnt = malloc(sizeof(t_elmnt));
	if (stack->lst == NULL || stack->elmnt == NULL)
		return (ERROR);
	stack->elmnt->nbr = 0;
	stack->elmnt->next = NULL;
	stack->lst->first = stack->elmnt;
	return (stack);
}

void	afficher_stack_a(t_stk *s_a)
{
	if (s_a->elmnt->next == NULL)
		exit (0);
	while (s_a->elmnt->next != NULL)
	{
		ft_printf("\t\t--> %d\n", s_a->elmnt->nbr);
		s_a->elmnt = s_a->elmnt->next;
	}
}

int	ft_push_swap(int ac, char **av)
{
	int	size;
	t_stk *s_a;
	t_stk *s_b;

	s_a = NULL;
	s_b = NULL;
	if (!check_arg(ac, &av[1]) || !ft_doublon(&av[1]))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	size = ft_how_many(&av[1]);
	s_a = init_liste(s_a);
	s_b = init_liste(s_b);
	s_a = init_stack_a(s_a, &av[1]);
	afficher_stack_a(s_a);
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
