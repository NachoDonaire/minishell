SRCS	=	prueba2.c utils.c ft_split.c ft_calloc.c ft_memcpy.c comillas.c   n_pipes.c check_builtins.c ft_strjoin.c check_cmd.c check_pipes.c reds.c

OBJS	=	${SRCS:.c=.o}
NAME	=	minishell
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror 
all:	${NAME}
$(NAME):	${OBJS}
	${CC} ${CFLAGS}  -o ${NAME} ${OBJS} -lreadline
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} ${NAME}
re: fclean all
.PHONY: all clean fclean re
