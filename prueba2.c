#include "minishell.h"

void    process_exit(char *s, int *i)
{
        if (finder(s, "exit") == 1)
                *i = 1;
        else
                *i = 0;
}

int     finder(char *s, char *find)
{
        int     i;
        int     y;

        i = 0;
        y = 0;
        if (!s)
                return (0);
        while (s[i])
        {
                while (s[i] == find[y])
                {
                        y++;
                        i++;
                        if (find[y] == '\0')
                                return (1);
                }
                y = 0;
                i++;
        }
        return (0);
}

int	extreme_finder(char *s, char *find)
{
        int     i;
        int     y;

        i = 0;
        y = 0;
        if (!s)
                return (0);
	while (s[i] == ' ')
		i++;
	while (s[i] == find[y])
	{
		y++;
		i++;
		if (find[y] == '\0')
			return (1);
	}
        return (0);
}

void	process_string(char *s, t_general_data *gen_data, char *const env[], int y)
{
	char	**com;
	int	i;

	i = 0;
	process_sing_red(gen_data, s, y);
	process_in_red(gen_data, s, y);
	check_builtins(s, gen_data, y);
	com = ft_split(s, ' ');
	if (finder(com[0], "./") == 1)
	{
		if (check_cmllas(com[0]) == 1)
			com[0] = gest_cmllas(com[i]);
		gen_data->cmd[y].cmd = com[0];
		process_args(s, gen_data, y);
		return ;
	}
	while (com[i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
		i++;
	}
	gen_data->cmd[y].cmd = check_cmd(com[0], env);
	i = 0;
	process_args(s, gen_data, y);
	while (com[i])
		free(com[i++]);
}

void	process_args(char *s, t_general_data *gen_data, int y)
{
	char 	**com;
	int	i;

	i = 0;
	com = ft_split(s, ' ');
	while (com[i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
		i++;
	}
	gen_data->cmd[y].args = com;
}

void	process_input(char *s, t_general_data *gen_data, char *const env[])
{
	char	**aux;
	int		i;

	i = 0;
	aux = ft_split(s, ' ');
//	check_builtins(s, gen_data, 0);
//	if (gen_data->built == 1)
//		return ;
	if (finder(s, "|") == 1 || finder(s, "&") == 1)
		process_string_with_pipes(gen_data, s, env);
	else
		process_string(s, gen_data, env, 0);
	while (aux[i])
		free(aux[i++]);
	free(aux);
}

void	needed_free_cmd(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->cmd[i].cmd)
		free(gen_data->cmd[i++].cmd);
}

static void	handle_sigint(int sig)
{
	if (sig == SIGINT)
	{
		ioctl(STDIN_FILENO, TIOCSTI, "\n"); // STDIN_FILENO: File descriptor terminal TIOCSTI: Simulation of stdin of the terminal
		rl_replace_line("", 0); // Unsave in the history in the case we don´t finish the command
		rl_on_new_line();
	}
}

int     main(int argc, char **argv,  char *env[])
{
	int             i;
	char            *s;
	int		y;
	int		z;
	t_general_data    gen_data;

	if (argc == 0 || !argv)
			return (0);
	gen_data.env = get_env(env);
	i = 0;
	y = 0;
	z = 0;
	while (i == 0)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		gen_data.n_pipes = 0;
		gen_data.n_built = 0;
		gen_data.built = 0;
		s = readline("Minishell> ");
		if (s)
		{
			if (s[0])
			{
				add_history(s);
				n_pipes(&gen_data, s);
				gen_data.cmd = malloc(sizeof(t_cmd_data) * (gen_data.n_pipes + 1));
				gen_data.blt = malloc(sizeof(t_builtin_data) * (gen_data.n_pipes + 1));
				process_input(s, &gen_data, gen_data.env);
			/*	printf("%s\n",gen_data.blt.blt);
				printf("%s\n",gen_data.blt.args[0]);
				printf("%s\n",gen_data.blt.args[1]);
				*/
//				ft_check_comand(&gen_data);
				/*while (y <= gen_data.n_pipes)
				{
					printf("%s\n", gen_data.blt[y].blt);
//					printf("%d\n", gen_data.cmd[y].dred);
					z = 0;
					y++;
				}*/
				y = 0;
				process_exit(s, &i);
				free(s);
			}
		}
		else
		{
			printf("exit\n");
			i = 1;
		}
	}
	printf("exit\n");
	return (0);
}
  
