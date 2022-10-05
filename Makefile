SRCS	=	src/main.c src/utils/utils.c src/utils/utils2.c src/free/memory.c src/status/ft_status.c src/env/ft_get_env.c \
			src/lexer/input/comillas.c src/lexer/pipes/n_pipes.c src/lexer/builtins/check_builtins.c src/lexer/cmd/check_cmd.c src/lexer/pipes/check_pipes.c src/lexer/redirects/out_reds.c  src/lexer/redirects/out_reds2.c src/lexer/redirects/in_reds.c \
			src/lexer/redirects/in_reds2.c src/funciones_libft/ft_split.c src/funciones_libft/ft_calloc.c src/funciones_libft/ft_memcpy.c src/funciones_libft/ft_strchr.c src/funciones_libft/ft_strlen.c src/funciones_libft/ft_strjoin.c \
			src/funciones_libft/ft_strncmp.c src/funciones_libft/ft_strrchr.c src/funciones_libft/ft_substr.c src/funciones_libft/ft_putchar_fd.c src/funciones_libft/ft_putstr_fd.c src/lexer/redirects/out_reds3.c \
			src/builtins/ft_pwd/ft_pwd.c src/builtins/ft_cd/ft_cd.c src/builtins/ft_echo/ft_echo.c src/builtins/ft_unset/ft_unset.c src/builtins/ft_unset/ft_unset2.c src/lexer/redirects/in_reds3.c \
			src/builtins/ft_echo/ft_echo2.c  src/builtins/ft_export/ft_export2.c src/builtins/ft_export/ft_export.c \
			src/exec/ft_check_commands.c src/exec/ft_check_builtins.c src/exec/ft_exec.c src/exec/ft_path.c src/funciones_libft/ft_itoa.c src/exec/ft_exec2.c \
			src/signal/ft_signal.c src/exit/ft_exit.c src/lexer/input/ft_process_input.c src/lexer/redirects/fd_reds.c \
			src/gnl/get_next_line_utils.c src/gnl/get_next_line.c src/lexer/redirects/fd_reds2.c  \
			src/lexer/redirects/d_red.c src/lexer/builtins/check_builtins2.c


OBJS	=	${SRCS:.c=.o}
NAME	=	minishell
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror #-fsanitize=address
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS}  -o ${NAME} ${OBJS} -lreadline -L ~/.brew/Cellar/readline/8.1.2/lib -I ~/.brew/Cellar/readline/8.1.2/include
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
