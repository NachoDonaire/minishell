SRCS = minishell.c main.c ft_comprobar_comandos.c utils.c

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
			@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${FLAGS} -lreadline ${OBJS} -o ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re