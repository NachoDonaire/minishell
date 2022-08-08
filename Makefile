SRCS = get_env.c main.c ft_comprobar_comandos.c utils.c ft_comprobar_builtins.c builtins/ft_pwd/ft_pwd.c builtins/ft_cd/ft_cd.c builtins/ft_echo/ft_echo.c builtins/ft_unset/ft_unset.c builtins/ft_export/ft_export.c \
		builtins/ft_echo/ft_echo2.c builtins/ft_echo/ft_echo3.c  builtins/ft_export/ft_export2.c \
		funciones_libft/ft_calloc.c funciones_libft/ft_split.c funciones_libft/ft_strchr.c funciones_libft/ft_strjoin.c funciones_libft/ft_strlen.c funciones_libft/ft_strncmp.c \
		funciones_libft/ft_strrchr.c funciones_libft/ft_substr.c funciones_libft/ft_putchar_fd.c funciones_libft/ft_putstr_fd.c

OBJS = ${SRCS:.c=.o}

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror

RM = rm -f

%.o: %.c
			@${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJS}
		${CC} ${FLAGS} ${OBJS} -o ${NAME} -lreadline -L /Users/sasalama/.brew/Cellar/readline/8.1.2/lib -I /Users/sasalama/.brew/Cellar/readline/8.1.2/include
all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re