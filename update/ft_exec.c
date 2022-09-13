/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/13 13:20:54 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
void ft_child(t_general_data *gen_data, int position)
{
	int		process;
	char	**copy;
	int		i;

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	i = 0;
	gen_data->good_status = 0;
	copy = gen_data->cmd[position].args;
	while (gen_data->cmd[position].fd_in[i] > 0)
		dup2(gen_data->cmd[position].fd_in[i++], 0);
	if (position < gen_data->n_cmd - 1)
	{
		close(gen_data->pipe[0]);
		dup2(gen_data->pipe[1], 1);
		ft_exec(gen_data, position + 1);
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
*/
void ft_child(t_general_data *gen_data, int position)
{
	int	exec;

	exec = 0;
	if (gen_data->n_pipes == 0)
	{
		exec = execve(gen_data->cmd[position].cmd, gen_data->cmd[position].args, gen_data->env);
		if (exec < 0)
		{
			printf("Minishell: command not found: %s\n", gen_data->cmd[position].cmd);
			gen_data->good_status = 127;
			exit (gen_data->good_status);
		}
	}
	else
	{
		if (position == 0)
		{
			write(2, "aaa\n", 4);
			close(gen_data->pipe[position][0]);
			dup2(gen_data->pipe[position][1], 1);
			close(gen_data->pipe[position][1]);
		}
		else if (position > 0 && position <= gen_data->n_cmd - 1)
		{
			write(2, "iii\n", 4);
			close(gen_data->pipe[position][0]);
			dup2(gen_data->pipe[position - 1][0], 0);
			close(gen_data->pipe[position - 1][0]);
			dup2(gen_data->pipe[position][1], 1);
			close(gen_data->pipe[position][1]);
		}
		else
		{
			dup2(gen_data->pipe[position - 1][0], 0);
			close(gen_data->pipe[position - 1][0]);
			write(2, "eeee", 4);
		}
	}
	exec = execve(gen_data->cmd[position].cmd, gen_data->cmd[position].args, gen_data->env);
	if (exec < 0)
	{
		printf("Minishell: command not found: %s\n", gen_data->cmd[position].cmd);
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}

int	ft_exec(t_general_data *gen_data, int position)
{
	int		pid;
	int		i;
	int		n_wait;

	n_wait = gen_data->exec_pos;
	while (gen_data->sort[n_wait])
		n_wait++;
	n_wait = n_wait - gen_data->exec_pos;
	i = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (gen_data->cmd[position].cmd)
	{
		while (gen_data->sort[gen_data->exec_pos] == '1' && gen_data->sort[gen_data->exec_pos])
		{
			gen_data->exec_pos++;
			pid = fork();
			if (pid == 0)
			{
				if (gen_data->sort[gen_data->exec_pos + 1] == '1' || gen_data->n_pipes == 1) 
				{
					pipe(gen_data->pipe[position]);
					write(2, "w", 1);
				}
				ft_child(gen_data, position);
			}
			else
			{
				ft_exec(gen_data, position + 1);
			}
		}
		wait(NULL);
		wait(NULL);
		wait(NULL);
	}
	wait(NULL);
	printf("--%d--\n",gen_data->good_status);
	return (position);
}
