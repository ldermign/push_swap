/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:26:49 by ldermign          #+#    #+#             */
/*   Updated: 2021/08/10 15:21:53 by ldermign         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//#include <libc.h>

# include "libft.h"
# define ERROR 0
# define SUCCESS 1

//# include <libc.h>
 #define KRED  "\x1B[0;31m" // ROUGE
 #define KGRN  "\x1B[0;32m" // VERT
 #define KYEL  "\x1B[0;33m" // JAUNE
 #define KBLU  "\x1B[0;34m" // BLEU
 #define KMAG  "\x1B[0;35m" // MAGENTA
 #define KCYN  "\x1B[0;36m" // CYAN
 #define KWHT  "\x1B[0;37m" // BLANC
 #define KGRE  "\x1b[1;30m" // VERT
 #define CLR_COLOR "\x1b[0m" // CLEAR COLOR


/*
**	STRUCTURES
*/

typedef struct s_lst
{
	int				nbr;
	struct s_lst	*next;
}	t_lst;

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
	int		here;
	int		tmp;
}	t_utils;

typedef struct t_chunks
{
	int	size;
	int	*chk;
	int	*last_nbr;
	int	hold_first;
	int	hold_second;
	int	ret;
	int	tmp;
}	t_chk;

/*
**	CHECK
*/

int		check_arg(int ac, char **av);
int		ft_doublon(char **tab);
int		check_tab_arg(char **tab);

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
**	SORT CHUNKS 100
*/

void	get_chunks(t_lst **s_a, t_chk *chk, int size);
void	fill_chunk_know_last(t_lst **s_a, t_chk *chk, int size);
void	sort_stack_with_chunks(t_lst **s_a, t_lst **s_b, t_chk *chk, int size);
void	get_in_order(t_lst **s_b, t_chk *chk);
void	check_order_before_push(t_lst **s_b, t_chk *chk, int nbr_push);

/*
**	LITTLE SORT
*/

int		begin_sort(t_lst **s_a, t_lst **s_b, t_utils *uts);
int		sort_three_values_inv(t_lst **s_a);
void	sort_50_values(t_lst **s_a, t_lst **s_b, t_utils *uts);
void	sort_three_with_more(t_lst **stack);
int		where_to_change(t_lst **s_b, int nbr_push);
void	minimum(t_lst **stack, t_utils *uts);

/*
**	UTILS CHUNKS
*/

void	eject_two_mini(t_lst **s_a, t_lst **s_b, t_utils *uts);
void	pos_five_max(t_lst **stack, t_utils *uts);
void	push_all_except_five_to(t_lst **s_a, t_lst **s_b, t_utils *uts);
void	push_all_five_to(t_lst **s_a, t_lst **s_b, t_utils *uts);
void	push_max(t_lst **s_a, t_lst **s_b, t_utils *uts);
void	push_only_max(t_lst **s_a, t_lst **s_b, t_utils *uts);

/*
**	UTILS RADIX
*/

int		how_many_down(t_lst *stack, int nb_stack);
void	simu_rotate_a(t_lst **rad_a, t_lst **rad_ope);
void	simu_push_a(t_lst **rad_b, t_lst **rad_a, t_lst **rad_ope);
void	simu_push_b(t_lst **rad_a, t_lst **rad_b, t_lst **rad_ope);
void	get_list_nbr(t_lst **s_a, t_lst **rad);
void	get_operations(t_lst **rad_a, t_lst **rad_b, t_lst **rad_ope);

/*
**	UTILS
*/

int		get_nbr_pos(t_lst **stack, int pos);
int		check_if_sort(t_lst *stack);
int		check_if_sort_inv(t_lst *stack);
int		max_val(t_lst *stack);
int		max_with_max(t_lst *stack, int size, int no);
int		min_val(t_lst *stack, int size);
int		min_with_min(t_lst *stack, int size, int no);
int		get_info(t_utils *uts);
int		size_stack(t_lst *stack);
t_lst	*new_nbr(int nbr);
void	add_nbr_back(t_lst **stack, int nbr);
void	add_nbr_front(t_lst **begin, int nbr);
int		somme(int *all, int size);
void	free_lst(t_lst **stack);

void	afficher_deux_stack(t_lst **one, t_lst **two);
void	afficher_une_stack(t_lst **s);
void	afficher_stack_et_rad(t_lst **stack, t_lst **rad);
#endif