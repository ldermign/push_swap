# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:10:10 by ldermign          #+#    #+#              #
#    Updated: 2021/08/10 19:34:33 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c \
			./ope/ope_simple_a.c \
			./ope/ope_simple_b.c \
			./ope/ope_double.c \
			./sort/begin_sort.c \
			./sort/little_sort.c \
			./sort/sort_chunks_100.c \
			./sort/radix_simu.c \
			./sort/sort_radix_500.c \
			./utils/ps_check.c \
			./utils/tris_utils.c \
			./utils/stack_utils.c \
			./utils/stack_utils_2.c \
			./utils/sort_chunks_100_utils.c \
			./utils/max_min_utils.c

INCS	=	-I ./ -I ./libft/includes/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror ${DIR}

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
