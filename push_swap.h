/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:29:32 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/06 15:05:41 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define ERROR 0
# define SUCCESS 1

/*
**	STRUCTURES
*/

typedef struct s_operation
{
	int sa;
	int sb;
	int ss;
	int pa;
	int pb;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
}	t_ope;

/*
**	LISTES CHAINEES
*/

typedef struct s_element
{
	int nbr;
	struct s_element *next;
} t_elmnt;

typedef struct s_liste
{
	t_elmnt *first;
} t_liste;

typedef struct s_stack
{
	t_liste *lst;
	t_elmnt *elmnt;
} t_stk;

/*
**	CHECK
*/

int	check_arg(int ac, char **av);
int	ft_doublon(char **tab);

/*
**	UTILS
*/

int	ft_how_many(char **tab);






#endif