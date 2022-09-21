# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sam <sam@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:05:57 by sle-huec          #+#    #+#              #
#    Updated: 2022/09/21 16:36:20 by sam              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -MMD -Wall -Wextra -Werror -g -pthread

SRCS = ${addprefix $(SRCS_PATH), \
		handle_struct.c \
		utils_libft.c \
		check_input.c \
		philo.c}

INCLUDE = -I./

SRCS_PATH= ./srcs/
OBJ_PATH = ./objs/

OBJ = $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.o)
DEP = $(SRCS:$(SRCS_PATH)%.c=$(OBJ_PATH)%.d)

all: $(NAME)

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -o ${NAME}


$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

clean:
	rm -rf ${OBJ} ${DEPS}

fclean: clean
	rm -rf ${NAME}
	rm -rf ${OBJ_PATH}

re : fclean
	make -C.
	make all

grind: ${NAME}
		valgrind --tool=helgrind --track-fds=yes --leak-check=full -s ./philo

.PHONY: clean, fclean, re, grind

-include ${DEPS}