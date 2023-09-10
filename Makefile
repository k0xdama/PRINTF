# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmateo <pmateo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/10 16:50:41 by pmateo            #+#    #+#              #
#    Updated: 2023/09/10 17:44:24 by pmateo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
RM		= rm -f

SRCS	=		SRCS/ft_printf.c \
				SRCS/ft_char.c   \
				SRCS/ft_hexa.c	 \
				SRCS/ft_nbr.c    \
				SRCS/ft_ptr.c    \
				SRCS/ft_str.c    \
				SRCS/ft_unbr.c   \
				SRCS/ft_utils.c  \

OBJS	= ${SRCS:.c=.o}

NAME = libftprintf.a

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all: ${NAME}

bonus: ${OBJS}
	${AR} ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}
re: fclean all

.PHONY: all clean fclean re