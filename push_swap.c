/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 12:01:21 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/03 19:27:39 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

# include <libc.h>
 #define KRED  "\x1B[0;31m" // ROUGE
 #define KGRN  "\x1B[0;32m" // VERT
 #define KYEL  "\x1B[0;33m" // JAUNE
 #define KBLU  "\x1B[0;34m" // BLEU
 #define KMAG  "\x1B[0;35m" // MAGENTA
 #define KCYN  "\x1B[0;36m" // CYAN
 #define KWHT  "\x1B[0;37m" // BLANC
 #define KGRE  "\x1b[1;30m" // VERT
 #define CLR_COLOR "\x1b[0m" // CLEAR COLOR

void	afficher_une_stack(t_lst **s)
 {
 	int		i;
 	t_lst	*first;

 	i = 0;
 	first = *s;
 	if (*s == NULL)
 		exit (0);
 	while (*s != NULL)
 	{
 		printf(CLR_COLOR"\t[%d]\t--> %d\n", i, (*s)->nbr);
 		*s = (*s)->next;
 		i++;
 	}
 	*s = first;
 }


void	afficher_deux_stack(t_lst **one, t_lst **two)
{
	t_lst	*fone;
	t_lst	*ftwo;

	fone = *one;
	ftwo = *two;
	int i = 0;
	ft_printf(CLR_COLOR"First [a]\n");
	if (*one == NULL)
		ft_printf("\t///\n");
	while (*one != NULL)
	{
		printf("[%d]\t--> %d\n", i, (*one)->nbr);
		*one = (*one)->next;
		i++;
	}
	i = 0;
	ft_printf("Second [b]\n");
	if (*two == NULL)
		ft_printf("\t///\n");
	while (*two != NULL)
	{
		printf("[%d]\t--> %d\n", i, (*two)->nbr);
		*two = (*two)->next;
		i++;
	}
	ft_printf("\n");
	*one = fone;
	*two = ftwo;
}

int	get_char_in_int(t_lst **begin, char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		nbr = ft_atoi(&str[i]);
		add_nbr_back(begin, nbr);
		if (str[i] == '-')
			i++;
		if (!ft_is_digit(str[i]))
			return (ERROR);
		while (ft_is_digit(str[i]))
			i++;
		if (str[i] != ' ' && str[i] != '\0')
			return (ERROR);
		while (str[i] == ' ')
			i++;
		if (str[i] != '-' && str[i] != '\0' && !ft_is_digit(str[i]))
			return (ERROR);
	}
	return (SUCCESS);
}

int	init_liste_a(t_lst **begin, int ac, char **tab)
{
	int		i;
	int		nbr;
	t_lst	*ret;

	i = 1;
	nbr = 0;
	ret = *begin;
	if (ac == 2)
	{
		if (!get_char_in_int(begin, tab[1]))
			return (ERROR);
		return (SUCCESS);
	}
	if (ac > 2 && !check_tab_arg(tab))
		return (ERROR);
	while (tab[i])
	{
		nbr = ft_atoi(tab[i]);
		add_nbr_back(begin, nbr);
		i++;
	}
	return (SUCCESS);
}

int	get_stack_char(t_lst **stack, t_utils *uts)
{
	int		i;
	t_lst	*first;

	i = 0;
	first = *stack;
	uts->size = size_stack(*stack) + 1;
	uts->s_int = malloc(sizeof(int) * uts->size);
	if (uts->s_int == NULL)
		return (ERROR);
	while (i < uts->size)
	{
		uts->s_int[i] = (*stack)->nbr;
		i++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (SUCCESS);
}

int	ft_push_swap(int ac, char **av)
{
	t_lst	*s_a;
	t_lst	*s_b;
	t_utils	*uts;

	s_a = NULL;
	s_b = NULL;
	uts = NULL;
	if (!check_arg(ac, av) || !init_liste_a(&s_a, ac, av))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	uts = malloc(sizeof(t_utils));
	ft_bzero(uts, 0);
	if (uts == NULL || !get_stack_char(&s_a, uts))
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	begin_sort(&s_a, &s_b, uts);
	// afficher_deux_stack(&s_a, &s_b);
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
		return (SUCCESS);
	else
		ft_push_swap(ac, av);
	return (SUCCESS);
}
