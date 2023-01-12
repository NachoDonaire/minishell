SRCS	=	src/main.c src/utils/utils.c src/utils/utils2.c src/free/memory.c src/status/ft_status.c src/env/ft_get_env.c  src/env/ft_get_env2.c\
		src/lexer/input/comillas.c	src/lexer/pipes/n_pipes.c src/lexer/builtins/check_builtins.c src/lexer/cmd/check_cmd.c src/lexer/pipes/check_pipes.c src/lexer/redirects/out_reds.c  src/lexer/redirects/out_reds2.c src/lexer/redirects/in_reds.c \
			src/lexer/redirects/in_reds2.c src/funciones_libft/ft_split.c src/funciones_libft/ft_calloc.c src/funciones_libft/ft_memcpy.c src/funciones_libft/ft_strchr.c src/funciones_libft/ft_strlen.c src/funciones_libft/ft_strjoin.c \
			src/funciones_libft/ft_strncmp.c src/funciones_libft/ft_strrchr.c src/funciones_libft/ft_substr.c src/funciones_libft/ft_putchar_fd.c src/funciones_libft/ft_putstr_fd.c src/lexer/redirects/out_reds3.c \
			src/builtins/ft_pwd/ft_pwd.c src/builtins/ft_cd/ft_cd.c src/builtins/ft_echo/ft_echo.c src/builtins/ft_unset/ft_unset.c src/builtins/ft_unset/ft_unset2.c src/lexer/redirects/in_reds3.c \
			src/builtins/ft_echo/ft_echo2.c  src/builtins/ft_export/ft_export2.c src/builtins/ft_export/ft_export.c src/lexer/input/ft_process_input2.c  src/lexer/input/ft_process_input3.c src/lexer/input/ft_process_input4.c\
			src/exec/ft_check_commands.c src/exec/ft_check_builtins.c src/exec/ft_exec.c src/exec/ft_path.c src/funciones_libft/ft_itoa.c src/exec/ft_exec2.c \
			src/signal/ft_signal.c src/exit/ft_exit.c src/lexer/input/ft_process_input.c src/lexer/redirects/fd_reds.c src/exec/ft_exec3.c src/free/memory3.c\
			src/gnl/get_next_line_utils.c src/gnl/get_next_line.c src/lexer/redirects/fd_reds2.c  src/lexer/redirects/out_reds4.c src/exec/ft_exec5.c\
			src/lexer/redirects/d_red.c src/lexer/builtins/check_builtins2.c  src/lexer/redirects/in_reds4.c src/free/memory2.c src/exec/ft_exec4.c\
			src/lexer/input/syntax_error.c src/lexer/expand/teophilus.c src/lexer/input/syntax_error2.c src/lexer/input/syntax_error3.c src/builtins/ft_cd/ft_cd2.c src/lexer/redirects/out_reds5.c\
			src/lexer/expand/teophilus2.c src/lexer/expand/teophilus3.c src/lexer/expand/teophilus4.c src/lexer/expand/teophilus5.c src/lexer/expand/teophilus6.c src/lexer/input/dr_comillas.c src/lexer/input/le_llaman_el_comillas.c src/lexer/input/syntax_error4.c src/utils/utils3.c

OBJS	=	${SRCS:.c=.o}
NAME	=	minishell
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror# -fsanitize=address
all:	${NAME}

$(NAME):	${OBJS}
	@echo "\nCompiling minishell, please be patient..."
	@${CC} ${CFLAGS}  -o ${NAME} ${OBJS} -lreadline -L ~/.brew/Cellar/readline/8.2.1/lib -I ~/.brew/Cellar/readline/8.2.1/include
	@echo "Done!"

%.o: %.c
	@printf "Generating objects...\r"
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@echo "Removing objects..."
	@${RM} ${OBJS}
	@echo "Done!"
fclean: clean
	@echo "Removing all..."
	@${RM} ${NAME}
	@echo "Cleant"
re: fclean all

exec: fclean all
	clear
	./minishell
.PHONY: all clean fclean re exec
