/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:26:49 by ldermign          #+#    #+#             */
/*   Updated: 2021/06/29 14:41:35 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# define ERROR 0
# define SUCCESS 1

/*
**	STRUCTURES
*/

typedef struct s_lst
{
	int				nbr;
	struct s_lst	*next;
}	t_lst;

typedef struct s_first
{
	t_lst	*fst_a;
	t_lst	*fst_b;
}	t_first;

typedef struct s_utils
{
	int		*s_int;
	double	med;
	int		size;
	int		middle;
	int		max;
	int		pos1;
	int		pos2;
	int		pos3;
}	t_utils;

/*
**	CHECK
*/

int		check_arg(int ac, char **av);
int		ft_doublon(char **tab);

/*
**	OPERATIONS
*/

void	swap(t_lst **stack, t_lst **first, char s);
void	rotate(t_lst **stack, t_lst **first, char s);
void	reverse_rotate(t_lst **stack, t_lst **first, char s);
void	push(t_lst **s_give, t_lst **s_get, t_lst **f_get, char s);
void	swap_ss(t_lst **s_a, t_lst **s_b, t_first **first);
void	rotate_rr(t_lst **s_a, t_lst **s_b, t_first **first);
void	reverse_rotate_rrr(t_lst **s_a, t_lst **s_b, t_first **first);

/*
**	TRIS
*/

void	sort_five_values(t_lst **s_a, t_lst **s_b, t_first **first);
int		sort_three_values(t_lst **stack, t_lst **first);
int		begin_sort(t_lst **s_a, t_lst **s_b, t_first **first, t_utils *uts);
void	three_sort(t_lst **stack, t_lst **first, char s);

/*
**	TRIS UTILS
*/

int	get_nbr_pos(t_lst **stack, int pos);
int		get_med(t_lst **stack);
// int		pos_not_good(t_lst *stack);
// int		how_many_not_good(t_lst *stack);
int		check_if_sort(t_lst *stack);
int		max_val(t_lst *stack);
int		max_with_max(t_lst *stack, int max);

/*
**	UTILS
*/

int		get_info(t_utils *uts);
int		size_stack(t_lst *stack);
t_lst	*new_nbr(int nbr);
void	add_nbr_back(t_lst **stack, t_lst **first, int nbr);
void	add_nbr_front(t_lst **begin, t_lst **first, int nbr);

/*
**	SUPPRIMER
*/

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
void	afficher_infos(int ac);
void	afficher_une_stack(t_lst **s);
void	afficher_deux_stack(t_lst **one, t_lst **two);

#endif