/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/12 14:07:43 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_child(t_general_data *gen_data, int position)
{
//	char	*path;
	int		process;
	char	**copy;
//	char	*tmp;
	int		i;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	i = 0;
	gen_data->good_status = 0;
	copy = gen_data->cmd[position].args;
	/*if (ft_strncmp(copy[0], "./", 2) == 0)
	{
		path = getcwd(NULL, 0);
		tmp = ft_strjoin(path, "/");
		free(path);
		path = ft_strjoin(tmp, copy[0]);
		free(tmp);
		process = execve(path, copy, gen_data->env);
	}*/

	while (gen_data->cmd[position].fd_in[i] > 0)
	{
		dup2(gen_data->cmd[position].fd_in[i++], 0);
	}
	i = 0;
	if (position < gen_data->n_cmd - 1)
	{
		close(gen_data->pipe[0]);
		dup2(gen_data->pipe[1], 1);
	}
	if (position == gen_data->n_cmd - 1)
	{
		close(gen_data->pipe[1]);
		dup2(gen_data->pipe[0], 0);
	}
	//ft_path(copy[0], gen_data->env, &path);
	process = execve(gen_data->cmd[position].cmd, copy, gen_data->env);
	if (process == -1)
	{
		printf("Minishell: command not found: %s\n", copy[0]);
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}

void	ft_exec(t_general_data *gen_data, int position)
{
	int		pid;
	//int		i;

	//i = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (gen_data->cmd[position].cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			pipe(gen_data->pipe);
			ft_child(gen_data, position);
		}
		else
		{
		//	wait(NULL);
			wait(NULL);
		}
		waitpid(pid, NULL, 0);
	}
	printf("--%d--\n",gen_data->good_status);
}
