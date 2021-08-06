/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:14:48 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/06 18:19:16 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_five_values(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	if (uts->size == 4)
	{
		while (min_val(*s_a, size_stack(*s_a)) != 0)
			rotate_a(s_a);
		push_b(s_a, s_b);
		sort_three_values(s_a);
		push_a(s_b, s_a);
		return (SUCCESS);
	}
	minimum(s_a, uts);
	eject_two_mini(s_a, s_b, uts);
	sort_three_values(s_a);
	if ((*s_b)->nbr < (*s_b)->next->nbr)
		swap_b(s_b);
	push_a(s_b, s_a);
	push_a(s_b, s_a);
	return (SUCCESS);
}

int	sort_100_values_chunks(t_lst **s_a, t_lst **s_b, int size)
{
	t_chk	*chk;

	chk = malloc(sizeof(t_chk));
	if (chk == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_bzero(chk, 0);
	get_chunks(s_a, chk, size);
	fill_chunk_know_last(s_a, chk, size);
	sort_stack_with_chunks(s_a, s_b, chk, size);
	chk->ret = max_val(*s_b) - 1;
	get_in_order(s_b, chk);
	chk->size = size_stack(*s_b);
	while (chk->size >= 0)
	{
		push_a(s_b, s_a);
		chk->size--;
	}
	return (1);
}

void	get_list_nbr(t_lst **s_a, t_lst **rad)
{
	int		i;
	int		ret;
	int		nbr;
	t_lst	*first;

	i = 0;
	ret = 0;
	nbr = 0;
	first = *s_a;
	while (ret <= size_stack(*s_a))
	{
		i = 0;
		while (*s_a != NULL && i < ret)
		{
			*s_a = (*s_a)->next;
			i++;
		}
		nbr = (*s_a)->nbr;
		*s_a = first;
		add_nbr_back(rad, how_many_down(*s_a, nbr));
		ret++;
	}
	*s_a = first;
	// afficher_stack_et_rad(s_a, rad);
}

void	conv_radix_to_bits(t_lst **rad)
{
	int		i;
	int		nbr;
	int		char_nbr[8];
	t_lst	*first;

	i = 0;
	nbr = 0;
	first = *rad;
	while (*rad != NULL)
	{
		i = 7;
		//  char_nbr = ft_itoa((*rad)->nbr);
		nbr = (*rad)->nbr;
				printf("nbr = %d\n", nbr);
		// printf("rad->nbr = %d\n", nbr);
		// printf("char_nbr = %s\n", char_nbr);
		while (nbr > 0)
		{
			char_nbr[i] = nbr % 2;
			// printf("char_nbr[i] = %d\n", char_nbr[i]);
			nbr = nbr / 2;
			i--;
		}
		while (i >= 0)
		{
			char_nbr[i] = 0;
			i--;
		}
		for (i = 0 ; i < 8 ; i++)
			printf("char_nbr = %d\n", char_nbr[i]);
		// (*rad)->nbr = ft_atoi(char_nbr);
		// printf("rad->nbr = %d\n", (*rad)->nbr);
		// printf("char_nbr = %s\n", char_nbr);
		*rad = (*rad)->next;
	}
}

void bits(int nbr)
{
	  int tab[10], i;  

  
  for(i=0; nbr > 0; i++)  
  {  
    tab[i] = nbr%2;  
    nbr = nbr/2;  
  } 
  
  printf("\nLe nombre binaire est = ");
  
  for(i=i-1; i >= 0; i--)  
  {  
    printf("%d",tab[i]);  
  } 

}

int	sort_500_values(t_lst **s_a, t_lst **s_b)
{
	(void)s_b;
	t_lst	*rad;

	rad = NULL;
	get_list_nbr(s_a, &rad);
	conv_radix_to_bits(&rad);
	// printf("8>>1 = %d, 5>>2 = %d, 2>>4 = %d, 87>>3 = %d, 5&10 = %d, 12&23 = %d\n", 8>>1, 5>>2, 2>>4, 87>>3, 5&10, 12&23);
	return (SUCCESS);
}

int	begin_sort(t_lst **s_a, t_lst **s_b, t_utils *uts)
{
	get_info(uts);
	if (check_if_sort(*s_a))
		return (SUCCESS);
	else if (uts->size == 2)
	{
		if ((*s_a)->nbr > (*s_a)->next->nbr)
			swap_a(s_a);
		return (SUCCESS);
	}
	else if (uts->size == 3)
		sort_three_values(s_a);
	else if (uts->size <= 5)
		sort_five_values(s_a, s_b, uts);
	else if (uts->size <= 100)
		sort_100_values_chunks(s_a, s_b, 10);
	else if (uts->size <= 500)
		sort_500_values(s_a, s_b);
	//afficher_deux_stack(s_a, s_b);
	return (SUCCESS);
}
