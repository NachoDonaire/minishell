SRCS	=	prueba2.c utils.c ft_split.c funciones_libft/ft_calloc.c ft_memcpy.c comillas.c  \
			n_pipes.c check_builtins.c ft_strjoin.c check_cmd.c check_pipes.c out_reds.c in_reds.c \
			funciones_libft/ft_strchr.c funciones_libft/ft_strlen.c funciones_libft/ft_strncmp.c \
			funciones_libft/ft_strrchr.c funciones_libft/ft_substr.c funciones_libft/ft_putchar_fd.c funciones_libft/ft_putstr_fd.c \
			builtins/ft_pwd/ft_pwd.c builtins/ft_cd/ft_cd.c builtins/ft_echo/ft_echo.c builtins/ft_unset/ft_unset.c  \
			builtins/ft_echo/ft_echo2.c builtins/ft_echo/ft_echo3.c  builtins/ft_export/ft_export2.c builtins/ft_export/ft_export.c \
			ft_status.c get_env.c ft_check_commands.c ft_check_builtins.c ft_exec.c ft_path.c \
			memory.c 


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
