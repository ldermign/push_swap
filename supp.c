/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 17:15:49 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/22 15:41:15 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	afficher_une_stack(t_lst **s)
{
	t_lst	*first;

	first = NULL;
	if (*s == NULL)
		exit (0);
	while (*s != NULL)
	{
		printf("\t\t--> %d\n", (*s)->nbr);
		*s = (*s)->next;
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
	ft_printf("First [a]\n");
	if (*one == NULL)
		printf("\t\t///\n");
	while (*one != NULL)
	{
		printf("[%d]\t\t--> %d\n", i, (*one)->nbr);
		*one = (*one)->next;
		i++;
	}
	i = 0;
	printf("Second [b]\n");
	if (*two == NULL)
		printf("\t\t///\n");
	while (*two != NULL)
	{
		printf("[%d]\t\t--> %d\n", i, (*two)->nbr);
		*two = (*two)->next;
		i++;
	}
	ft_printf("\n");
	*one = fone;
	*two = ftwo;
}
