/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:35 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/16 12:08:11 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	needed_free_cmd(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->cmd[i].cmd)
		free(gen_data->cmd[i++].cmd);
}

void	ft_iniciate(t_general_data *gen_data)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	gen_data->n_pipes = 0;
	gen_data->built = 0;
	gen_data->smith_blt = 1;
	gen_data->n_built = 0;
	gen_data->n_cmd = 1;
	gen_data->exec_pos = 0;
	gen_data->pipe_pos = 0;
	gen_data->std_in = dup(0);
	gen_data->std_out = dup(1);
	gen_data->count_wait = 0;
}

void	ft_free_all(t_general_data *gen_data, char *s)
{
	free(s);
	needed_free(gen_data, gen_data->n_cmd - gen_data->n_built);
}

void	copy_dup(t_general_data	*gen_data)
{
	if (gen_data->n_pipes > 0)
	{
		dup2(gen_data->std_out, 1);
		dup2(gen_data->std_in, 0);
	}
}

int	check_spaces(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == ' ' && s[i])
		i++;
	if (i == ft_strlen(s))
		return (0);
	return (1);
}

void	ft_check_secret_env(t_general_data *gen_data)
{
	int		x;
	char	*s;

	x = 0;
	while (gen_data->secret_env[x])
	{
		if (ft_strncmp(gen_data->secret_env[x], "PATH=", 5) == 0)
			return ;
		x++;
	}
	s = ft_substr("PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.", 0, 48);
	gen_data->secret_env[x] = s;
	x++;
	gen_data->secret_env[x] = 0;
}

char	**check_env(char **env, char **envp)
{
	char	*buf;

	if (envp[0])
		return (env);
	ft_free_arg(env);
	env = malloc(sizeof(char *) * 5);
	buf = getcwd(NULL, 0);
	env[0] = ft_strjoin("PWD=", buf);
	free(buf);
	env[1] = ft_substr("SHLVL=1", 0, 8);
	env[2] = ft_substr("_=./minishell", 0, 14);
	env[3] = ft_substr("?=", 0, 3);
	env[4] = 0;
	return (env);
}

int	main(int argc, char **argv, char *env[])
{
	t_general_data	gen_data;

	gen_data.env = get_env(env);
	gen_data.env = check_env(gen_data.env, env);
	gen_data.secret_env = get_env(env);
	gen_data.secret_env = check_env(gen_data.secret_env, env);
	ft_check_secret_env(&gen_data);
	while (argc && argv)
	{
		ft_iniciate(&gen_data);
		gen_data.s = readline("Minishell> ");
		if (gen_data.s && gen_data.s[0] && check_spaces(gen_data.s) == 1)
		{
			add_history(gen_data.s);
			n_pipes(&gen_data, gen_data.s);
			if (ft_check_exit(gen_data.s) == 1)
				ft_exit(gen_data.s, gen_data.env);
			if (syntax_error(gen_data.s) == 0)
			{
				reserva(&gen_data);
				gen_data.s = teophilus(&gen_data);
				process_input(gen_data.s, &gen_data, gen_data.env);
				ft_check_comand(&gen_data);
				copy_dup(&gen_data);
				ft_free_all(&gen_data, gen_data.s);
			}
		}
		else if (!gen_data.s)
			ft_exit(gen_data.s, gen_data.env);
	}
	return (0);
}
