SRCS = minishell.c main.c

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror -lreadline

RM = rm -f

%.o: %.c
			@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re