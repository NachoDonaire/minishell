SRCS	=	main.c utils/utils.c memory.c status/ft_status.c env/ft_get_env.c \
			lexer/comillas.c lexer/n_pipes.c lexer/check_builtins.c lexer/check_cmd.c lexer/check_pipes.c lexer/out_reds.c lexer/in_reds.c \
			funciones_libft/ft_split.c funciones_libft/ft_calloc.c funciones_libft/ft_memcpy.c funciones_libft/ft_strchr.c funciones_libft/ft_strlen.c funciones_libft/ft_strjoin.c \
			funciones_libft/ft_strncmp.c funciones_libft/ft_strrchr.c funciones_libft/ft_substr.c funciones_libft/ft_putchar_fd.c funciones_libft/ft_putstr_fd.c \
			builtins/ft_pwd/ft_pwd.c builtins/ft_cd/ft_cd.c builtins/ft_echo/ft_echo.c builtins/ft_unset/ft_unset.c \
			builtins/ft_echo/ft_echo2.c builtins/ft_echo/ft_echo3.c  builtins/ft_export/ft_export2.c builtins/ft_export/ft_export.c \
			exec/ft_check_commands.c exec/ft_check_builtins.c exec/ft_exec.c exec/ft_path.c \


OBJS	=	${SRCS:.c=.o}
NAME	=	minishell
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror 
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS}  -o ${NAME} ${OBJS} -lreadline -L ~/.brew/Cellar/readline/8.1.2/lib -I ~/.brew/Cellar/readline/8.1.2/include
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
