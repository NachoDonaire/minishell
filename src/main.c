#include "../includes/minishell.h"

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
		process_string_w_pipes(gen_data, s, env);
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
