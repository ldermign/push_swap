/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tris.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 07:51:05 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/15 14:08:07 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int median_even(int *tab, int size_stack, int med)
{
    (void)tab;
    (void)size_stack;
    int i = 0;

    (void)i;
    return (med);
}

void    bubble_sort(int *tab, int size)
{
    int i;
    int j;

    i = 0;
    while (i < (size - 1))
    {
        j = 0;
        while (j + 1 && j < (size - i - 1))
        {
            if (tab[j] > tab[j + 1])
                ft_swap(&tab[j], &tab[j + 1]);
            j++;
        }
        i++;
    }
}

void    get_info(t_utils *uts)
{
    bubble_sort(uts->s_int, uts->size);
    for (int k = 0 ; k < uts->size ; k++)
        printf("tab = [%d]\n", uts->s_int[k]);
    if ((uts->size % 2) == 0)
        uts->med = median_even(uts->s_int, uts->size, uts->med);
    else
        uts->med = uts->s_int[((uts->size + 1) / 2) - 1];
    printf("med = %d\n", uts->med);
}