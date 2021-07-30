/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:26:49 by ldermign          #+#    #+#             */
/*   Updated: 2021/07/30 16:06:06 by ldermign         ###   ########.fr       */
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

// 65 = 1500
// 65 = 439

typedef struct s_utils
{
	int		*s_int;
	double	med;
	int		size;
	int		middle;
	int		max;
	char	stack;
	int		min1;
	int		min2;
	int		pos1;
	int		pos2;
	int		pos3;
	int		pos4;
	int		pos5;
	int		here;
	int		inf;
	int		sup;
	int		tmp;
	int		first;
	int		pos_first;
	int		last_push;
	int		ret;
}	t_utils;

typedef struct t_chunks
{
	int	size;
	int	*chk;
	int	*last_nbr;
	int	hold_first;
	int hold_second;
	int	ret;
	int	if_move1;
	int if_move2;
	int	if_move3;
	int	if_move4;
}	t_chk;

/*
**	CHECK
*/

int		check_arg(int ac, char **av);
int		ft_doublon(char **tab);

/*
**	OPERATIONS
*/

void	swap_a(t_lst **s_a);
void	push_a(t_lst **s_b, t_lst **s_a);
void	rotate_a(t_lst **s_a);
void	reverse_rotate_a(t_lst **s_a);
void	swap_b(t_lst **s_b);
void	push_b(t_lst **s_a, t_lst **s_b);
void	rotate_b(t_lst **s_b);
void	reverse_rotate_b(t_lst **s_b);
void	swap_ss(t_lst **s_a, t_lst **s_b);
void	rotate_rr(t_lst **s_a, t_lst **s_b);
void	reverse_rotate_rrr(t_lst **s_a, t_lst **s_b);

/*
**	SORT
*/

int		begin_sort(t_lst **s_a, t_lst **s_b, t_utils *uts);
int		sort_five_values(t_lst **s_a, t_lst **s_b, t_utils *uts);
int		sort_three_values(t_lst **s_a);
int		sort_three_values_inv(t_lst **s_a);
void	sort_50_values(t_lst **s_a, t_lst **s_b, t_utils *uts);

/*
**	DEEP SORT
*/

void	sort_three_with_more(t_lst **stack);

/*
**	SORT UTILS
*/

int	how_many_not_good(t_lst *stack);
int	pos_not_good(t_lst *stack);

void	by_order_5(t_utils *uts);
void	by_order_3(t_utils *uts);
void	by_order_2(t_utils *uts);
int		get_nbr_pos(t_lst **stack, int pos);
int		get_med(t_lst **stack, int max, t_utils *uts);
int		check_if_sort(t_lst *stack);
int		check_if_sort_inv(t_lst *stack);
int		max_val(t_lst *stack);
int		max_with_max(t_lst *stack, int size, int no);
// int		min_val(t_lst *stack);
int		min_val(t_lst *stack, int size);
int		min_with_min(t_lst *stack, int size, int no);
void	eject_two_mini(t_lst **s_a, t_lst **s_b, t_utils *uts);
int		less_in_med(t_lst *hmn);

/*
**	UTILS
*/

int		get_info(t_utils *uts);
int		size_stack(t_lst *stack);
t_lst	*new_nbr(int nbr);
void	add_nbr_back(t_lst **stack, int nbr);
void	add_nbr_front(t_lst **begin, int nbr);
void	supp_elemt(t_lst **stack);
void	supp_last_elemt(t_lst **stack);
int	somme(int *all, int size);

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
void	afficher_stack_med(t_lst **med);

#endif