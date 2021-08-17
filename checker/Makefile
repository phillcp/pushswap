INCDIR	= ./inc

GCLDIR	= ./get_next_line

LIBDIR	= ./libft

SRCS	=	main.c \
			checker.c \
			actions/px.c \
			actions/rrx.c \
			actions/rx.c \
			actions/sx.c \
			${GCLDIR}/get_next_line.c \
			${GCLDIR}/get_next_line_utils.c
OBJS	= ${SRCS:.c=.o}

MAKE	= make

AR		= ar rcs

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

RM		= rm -rf

NAME	= checker.a

.c.o:
			${CC} ${CFLAGS} -I${INCDIR} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${MAKE} -C ${LIBDIR}
			cp ${LIBDIR}/libft.a ./${NAME}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

fcleanall:	clean
			${RM} ${NAME} ${LIBDIR}/${OBJS} ${GCLDIR}/${OBJS}

re:			fclean all

.PHONY:		all clean fclean re
