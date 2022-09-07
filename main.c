#include "includes/minishell.h"

static int	ft_check_exit(char *s)
{
	if (ft_strncmp(s, "exit", 5) == 0)
		return (1);
	return (0);
}

static void	ft_exit(char *texto, char **tmp)
{
	int	x;

	x = 0;
	if (texto)
		printf("%s\n", texto);
	else
		printf("exit\n");
	while (tmp[x])
		free(tmp[x++]);
	free(tmp);
	exit(0);
}

int	finder(char *s, char *find)
{
	int	i;
	int	y;

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
	int	i;
	int	y;

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

void	process_string(char *s, t_general_data *gen_data, char *env[], int y)
{
	char	**com;
	int		i;

	i = 0;
	process_sing_red(gen_data, s, y);
	process_in_red(gen_data, s, y);
	gen_data->built = 0;
	check_builtins(s, gen_data, y);
	gen_data->sort[0] = '0';
	if (gen_data->built == 0)
	{
		gen_data->sort[0] = '1';
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
}

void	process_args(char *s, t_general_data *gen_data, int y)
{
	char	**com;
	int		i;

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

void	process_input(char *s, t_general_data *gen_data, char *env[])
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
	char			*s;
	t_general_data	gen_data;
	char			*tmp;
	int				y;

	y = 0;
	gen_data.env = get_env(env);
	while (argc && argv)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, SIG_IGN);
		gen_data.n_pipes = 0;
		gen_data.built = 0;
		gen_data.n_built = 0;
		gen_data.n_cmd = 1;
		s = readline("Minishell> ");
		if (s)
		{
			if (s[0])
			{
				tmp = s;
				s = ft_substr(s, 0, ft_strlen(s));
				free(tmp);
				add_history(s);
				n_pipes(&gen_data, s);
				reserva(&gen_data);
				if (ft_check_exit(s) == 1)
					ft_exit(s, gen_data.env);
				process_input(s, &gen_data, gen_data.env);
			//	while (gen_data.cmd->args[y])
			//		printf("%s\n", gen_data.cmd->args[y++]);
			//	printf("--%d--\n", gen_data.n_cmd);
				ft_check_comand(&gen_data);
				y = 0;
				/*while (y <= gen_data.n_pipes && finder(s, "<") == 1)
				{
					while (gen_data.cmd[y].in[z])
						printf("%s\n", gen_data.cmd[y].in[z++]);
					printf("%d\n", gen_data.cmd[y].dred);
					z = 0;
					y++;
				}*/
				free(gen_data.sort);
				free(s);
				needed_free(&gen_data, gen_data.n_cmd);
			}
		//	printf("%s\n", gen_data.cmd[0].cmd);
		}
		else
			ft_exit(s, gen_data.env);
	}
	printf("exit\n");
	return (0);
}
