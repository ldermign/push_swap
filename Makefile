# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:10:10 by ldermign          #+#    #+#              #
#    Updated: 2021/08/10 15:47:47 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c \
			ps_check.c \
			stack_utils.c \
			stack_utils_2.c \
			ope_simple_a.c \
			ope_simple_b.c \
			ope_double.c \
			tris_utils.c \
			begin_sort.c \
			little_sort.c \
			sort_radix_500.c \
			radix_simu.c \
			sort_chunks_100.c \
			sort_chunks_100_utils.c \
			max_min_utils.c

INCS	=	-I ./push_swap.h -I ./libft/includes/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g3

RM		=	rm -rf

all:		${NAME}

${NAME}:	${OBJS}
			${MAKE} -C libft
			${CC} ${CFLAGS} ${INCS} $^ -o $@ ./libft/libft.a

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@


clean:
			${MAKE} -C libft clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
