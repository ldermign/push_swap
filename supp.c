/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:15:49 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/22 16:53:56 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int ope; ////////////////////////////////////////////////////////////////

void	afficher_infos(int ac)
{
	printf(KGRN"._______________________________________.\n");
	printf(KGRN"|\t\t\t\t\t|\n");
	printf(KGRN"|\t\tchiffres = [%d]\t\t|\n", ac);
	printf(KGRN"|\tNombre d'operations = [%d]\t|\n", ope);
	printf(KGRN"!_______________________________________!\n");
}

void	afficher_stack_med(t_lst **med)
{
	int		i;
	t_lst	*first_med;
	i = 0;
	first_med = *med;
	if (*med == NULL)
		exit (0);
	printf(KCYN"._______________________________.\n");
	printf(KCYN"|\t\t\t\t|\n");
	printf(KCYN"|\t\tMEDIANES\t|\n");
	while (*med != NULL)
	{
		printf(KCYN"|\t[%d] --> %d\t\t|\n", i, (*med)->nbr);
		*med = (*med)->next;
		i++;
	}
	*med = first_med;
	printf(KCYN"!_______________________________!\n");
}

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
