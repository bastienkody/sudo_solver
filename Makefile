INC = ./inc/sudo_solver.h

SRC_DIR = ./src/

SRCS =	${SRC_DIR}main.c\
		${SRC_DIR}parsing.c\
		${SRC_DIR}grid_utils.c\
		${SRC_DIR}verifier.c\
		${SRC_DIR}solver.c\

OBJS =	${SRCS:.c=.o}

NAME =	sudo_solver

CC =	cc

CFLAGSDEV =	-Wall -Wextra -Werror -g3

CFLAGS =	-Wall -Wextra -Werror

LDFLAGS =	-L./libft -lft

.c.o:	
		@echo "\033[32m\c"
		${CC} ${CFLAGSDEV} -c $< -o ${<:.c=.o}
		@echo "\033[0m\c"

all:	${NAME}

${NAME}:	${OBJS} ${INC} 
			@make -C libft/
			@echo "\033[33mlibft compiled\033[0m"
			@echo "\033[32m\c"
			${CC} -o ${NAME} ${OBJS} ${LDFLAGS}
			@echo "Link complete --> \033[36;1m${NAME}\033[0m"

clean:
		@rm -rf ${OBJS}
		@echo "\033[32m${NAME} .o cleaned"
		@make clean -C libft/
		@echo "\033[33mlibft .o cleaned\033[0m"

fclean:		clean
		@rm -rf ${NAME}
		@echo "\033[32m${NAME} fcleaned"
		@make fclean -C libft/
		@echo "\033[33mlibft.a fcleaned\033[0m"

re:		fclean all

.PHONY:	all clean bonus re
