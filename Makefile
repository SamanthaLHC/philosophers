# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sle-huec <sle-huec@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/16 15:05:57 by sle-huec          #+#    #+#              #
#    Updated: 2022/10/11 14:09:16 by sle-huec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -MMD -Wall -Wextra -Werror -g3 -pthread

SRCS = ${addprefix $(SRCS_PATH), \
		handle_struct.c \
		handle_mutexes.c \
		utils_libft.c \
		check_input.c \
		fork.c \
		routine.c \
		get_time.c \
		key_moment.c \
		generate.c}

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

hellgrind: ${NAME}
		valgrind --tool=helgrind ./philo 4 800 200 200

valgrind: ${NAME}
		valgrind ./philo 4 800 200 200

test: $(NAME)
	./$(NAME) 4 800 200 200 7
	
test1: $(NAME)
	./$(NAME) 5 800 200 200
	
test2: $(NAME)
	./$(NAME) 3 610 200 100

test3: $(NAME)
	./$(NAME) 2 400 210 100

test4: $(NAME)
	./$(NAME) 1 800 200 200

testp: $(NAME)
		./test_input.sh

.PHONY: clean fclean re grind test testp

-include ${DEPS}
