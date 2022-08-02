SRCS = get_env.c main.c ft_comprobar_comandos.c utils.c ft_comprobar_builtins.c builtins/ft_pwd.c builtins/ft_cd.c builtins/ft_echo.c builtins/ft_unset.c builtins/ft_export.c \
		 funciones_libft/ft_calloc.c funciones_libft/ft_split.c funciones_libft/ft_strchr.c funciones_libft/ft_strjoin.c funciones_libft/ft_strlen.c funciones_libft/ft_strncmp.c \
		 funciones_libft/ft_strrchr.c funciones_libft/ft_substr.c

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