NAME		= push_swap

CHECKER		= checker

SRCS_DIR	= srcs/

CHK_DIR		= bonuspart/

SRCS		=	${SRCS_DIR}algo_utils.c \
				${SRCS_DIR}algo.c \
				${SRCS_DIR}lst.c \
				${SRCS_DIR}main.c \
				${SRCS_DIR}operations_duo.c \
				${SRCS_DIR}operations.c \
				${SRCS_DIR}prog.c \
				${SRCS_DIR}tabsort.c \
				${SRCS_DIR}send_back.c \
				${SRCS_DIR}push_chunks.c \
				${SRCS_DIR}sort_three_from_b.c \
				${SRCS_DIR}b_to_a.c \
				${SRCS_DIR}sort.c \
				${SRCS_DIR}valid.c

CHK			=	${CHK_DIR}checker.c \
				${CHK_DIR}get_next_line.c \
				${CHK_DIR}main_bonus.c \
				${SRCS_DIR}operations.c \
				${SRCS_DIR}prog.c \
				${SRCS_DIR}lst.c \
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

BNS			= ${CHK:.c=.o}

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

bonus:		all ${BNS}
		${CC} ${CFLAGS} ${BNS} -o ${CHECKER}

.PHONY:		all clean fclean re bonus