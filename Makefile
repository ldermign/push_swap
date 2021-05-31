# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldermign <ldermign@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/31 11:10:10 by ldermign          #+#    #+#              #
#    Updated: 2021/05/31 15:18:55 by ldermign         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c

INCS	=	-I ./push_swap.h -I ./libft/includes/

OBJS	=	${SRCS:.c=.o}

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address

RM		=	rm -rf

all:		${NAME}

.c.o:
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS} #${INCS}
			${MAKE} -C libft
			${CC} ${CFLAGS} ${INCS} $^ -o $@

clean:
			${MAKE} -C libft clean
			${RM} ${OBJS}

fclean:		clean
			${MAKE} -C libft fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re