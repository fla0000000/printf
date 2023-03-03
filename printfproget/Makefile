# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbiondo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 13:28:47 by fbiondo           #+#    #+#              #
#    Updated: 2023/02/06 14:24:07 by fbiondo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wextra -Werror -Wall

NAME = libftprintf.a

SRCS = ft_printf.c ft_printf1.c ft_printf2.c

OBJS = ${SRCS:.c=.o}

CC = gcc ${FLAGS}
RM = rm -f

.c.o:
	${CC} -g  -c $< -o ${<:.c=.o}

${NAME} : ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME} 
re: fclean all
