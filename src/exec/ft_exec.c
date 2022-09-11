/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 18:57:36 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_child(t_general_data *gen_data, int position)
{
//	char	*path;
	int		process;
	char	**copy;
//	char	*tmp;
//	int		i;

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

	/*while (gen_data->cmd[position].fd_in[i] > 0)
	{
		dup2(gen_data->cmd[position].fd_in[i++], 0);
	}*/
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
	pipe(gen_data->pipe);
	if (gen_data->cmd[position].cmd)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_child(gen_data, position);
		}
		else
		{
			wait(NULL);
			wait(NULL);
		}
	}
	printf("--%d--\n",gen_data->good_status);
}
