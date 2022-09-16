# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:05:57 by sle-huec          #+#    #+#              #
#    Updated: 2022/09/16 15:26:34 by sle-huec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = ${addprefix srcs/, \
		philo.c}

OBJS = ${SRCS:srcs/%.c=build/%.o}
DEPS = ${SRCS:srcs/%.c=build/%.d}

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

build/%.o: srcs/%.c
		mkdir -p ${dir $@}
		${CC} ${CFLAGS} -c $< -o -$@

clean:
	rm -rf ${OBJS} ${DEPS} build

fclean: clean
	rm -rf ${NAME}

re : fclean
	make -C.

grind: ${NAME}
		valgrind --track-fds=yes --leak-check=full -s ./philo
	

.PHONY: clean, fclean, re, grind

-include ${DEPS}