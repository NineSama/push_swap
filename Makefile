NAME		= push_swap

SRCS_DIR	= srcs/

SRCS		=	${SRCS_DIR}algo_utils.c \
				${SRCS_DIR}algo.c \
				${SRCS_DIR}lst.c \
				${SRCS_DIR}operations_duo.c \
				${SRCS_DIR}operations.c \
				${SRCS_DIR}prog.c \
				${SRCS_DIR}tabsort.c \
				${SRCS_DIR}valid.c

_DEPS		= push_swap.h

INCL		= ./

DEPS		= $(patsubst %,$(INCL)/%,$(_DEPS))

OBJS		= ${SRCS:.c=.o}

CC			= clang

RM			= rm -rf

GREEN		= \033[1;32m

DEFAULT		= \033[0m

CFLAGS		= -Wall -Werror -Wextra -g3

.c.o:		${DEPS}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re bonus