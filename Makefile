SRCS	=	src/main.c src/utils/utils.c src/memory.c src/status/ft_status.c src/env/ft_get_env.c \
			src/lexer/comillas.c src/lexer/n_pipes.c src/lexer/check_builtins.c src/lexer/check_cmd.c src/lexer/check_pipes.c src/lexer/out_reds.c src/lexer/in_reds.c \
			src/funciones_libft/ft_split.c src/funciones_libft/ft_calloc.c src/funciones_libft/ft_memcpy.c src/funciones_libft/ft_strchr.c src/funciones_libft/ft_strlen.c src/funciones_libft/ft_strjoin.c \
			src/funciones_libft/ft_strncmp.c src/funciones_libft/ft_strrchr.c src/funciones_libft/ft_substr.c src/funciones_libft/ft_putchar_fd.c src/funciones_libft/ft_putstr_fd.c \
			src/builtins/ft_pwd/ft_pwd.c src/builtins/ft_cd/ft_cd.c src/builtins/ft_echo/ft_echo.c src/builtins/ft_unset/ft_unset.c \
			src/builtins/ft_echo/ft_echo2.c src/builtins/ft_echo/ft_echo3.c  src/builtins/ft_export/ft_export2.c src/builtins/ft_export/ft_export.c \
			src/exec/ft_check_commands.c src/exec/ft_check_builtins.c src/exec/ft_exec.c src/exec/ft_path.c \


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
