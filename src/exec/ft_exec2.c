/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:16:43 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/19 20:23:06 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_child_pipes(t_general_data *gen_data)
{
	if (gen_data->pipe_pos == 0)
	{
		close(gen_data->pipe[gen_data->pipe_pos][0]);
		dup2(gen_data->pipe[gen_data->pipe_pos][1], 1);
		close(gen_data->pipe[gen_data->pipe_pos][1]);
	}
	else if (gen_data->pipe_pos > 0 && gen_data->pipe_pos < gen_data->n_pipes)
	{
		close(gen_data->pipe[gen_data->pipe_pos][0]);
		dup2(gen_data->pipe[gen_data->pipe_pos - 1][0], 0);
		close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
		dup2(gen_data->pipe[gen_data->pipe_pos][1], 1);
		close(gen_data->pipe[gen_data->pipe_pos][1]);
	}
	else
	{
		dup2(gen_data->pipe[gen_data->pipe_pos - 1][0], 0);
		close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
	}
}

void	ft_child_not_pipes(t_general_data *gen_data, int position, int n_built)
{
	int	exec;

	exec = 0;
	dup_reds(gen_data, position, n_built);
	exec = execve(gen_data->cmd[position].cmd,
			gen_data->cmd[position].args, gen_data->env);
	if (exec < 0)
	{
		printf("Minishell: command not found: %s\n",
			gen_data->cmd[position].cmd);
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}

void	ft_child(t_general_data *gen_data, int position, int  n_built)
{
	int	exec;

	exec = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	dup_in_reds(gen_data, position, n_built);
	if (gen_data->n_pipes == 0)
		ft_child_not_pipes(gen_data, position, n_built);
	else
		ft_child_pipes(gen_data);
//	if (gen_data->cmd[position].fd_out[0] != 1 || gen_data->blt[n_built].fd_out[0] != 1)
	dup_reds(gen_data, position, n_built);
       	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		exec = execve(gen_data->cmd[position].cmd, gen_data->cmd[position].args, gen_data->env);
	}
        else if (gen_data->sort[gen_data->exec_pos] == '0')
        {
		gen_data->blt[n_built].blt = check_cmd(gen_data->blt[n_built].blt, gen_data->env);
                exec = execve(gen_data->blt[n_built].blt, gen_data->blt[n_built].args, gen_data->env);
        }

	if (exec < 0)
	{
		if (gen_data->sort[gen_data->exec_pos] == '1')
			printf("Minishell: command not found: %s\n", gen_data->cmd[position].cmd);
		else if (gen_data->sort[gen_data->exec_pos] == '0')
			printf("Minishell: command not found: %s\n", gen_data->blt[n_built].blt);
		
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}

void	ft_father(t_general_data *gen_data, int position, int n_built)
{
	if (gen_data->n_pipes != 0 && gen_data->exec_pos != gen_data->n_pipes)
	{
		if (gen_data->pipe_pos == 0)
			close(gen_data->pipe[gen_data->pipe_pos][1]);
		else
		{
			close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
			close(gen_data->pipe[gen_data->pipe_pos][1]);
		}
	}
	dup_reds(gen_data, position, n_built);
	gen_data->pipe_pos++;
	gen_data->exec_pos++;
}

void	ft_exec2(t_general_data *gen_data, int position, int n_built)
{
	gen_data->pid = fork();
	if (gen_data->pid == 0)
		ft_child(gen_data, position, n_built);
	else
	{
		wait(NULL);
		ft_father(gen_data, position, n_built);
		if (gen_data->sort[gen_data->exec_pos - 1] == '1' && gen_data->sort[gen_data->exec_pos])
			ft_exec(gen_data, position + 1, n_built);
		else if (gen_data->sort[gen_data->exec_pos - 1] == '0' && gen_data->sort[gen_data->exec_pos])
		{
			ft_exec(gen_data, position , n_built + 1);
		}

	}
}
