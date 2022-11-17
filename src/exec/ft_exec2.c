/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:16:43 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 20:40:32 by sasalama         ###   ########.fr       */
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
	if (gen_data->cmd[position].can_exec == 0)
		exit (1);
	exec = execve(gen_data->cmd[position].cmd,
			gen_data->cmd[position].args, gen_data->env);
	if (exec < 0)
	{
		ft_putstr_fd("Minishell: command not found: ", 2);
		ft_putstr_fd(gen_data->cmd[position].cmd, 2);
		ft_putstr_fd("\n", 2);
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}

void	ft_child(t_general_data *gen_data, int position, int n_built)
{
	char	*s3[2];

	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	dup_in_reds(gen_data, position, n_built);
	if (gen_data->n_pipes == 0)
		ft_child_not_pipes(gen_data, position, n_built);
	else
		ft_child_pipes(gen_data);
	dup_reds(gen_data, position, n_built);
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		s3[0] = gen_data->cmd[position].cmd;
		if (gen_data->cmd[position].can_exec == 0)
			exit (1);
		execve(s3[0], gen_data->cmd[position].args, gen_data->env);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		s3[1] = gen_data->blt[n_built].blt;
		s3[1] = check_cmd(s3[1], gen_data);
		if (gen_data->blt[n_built].can_exec == 0)
			exit (1);
		execve(s3[1], gen_data->blt[n_built].args, gen_data->env);
	}
}

void	ft_father(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	i = 0;
	(void)position;
	(void)n_built;
	if (gen_data->n_pipes != 0)
	{
		if (gen_data->pipe_pos != gen_data->n_pipes)
		{
			close(gen_data->pipe[gen_data->pipe_pos][1]);
		}
		else if (gen_data->exec_pos == gen_data->n_pipes)
		{
			while (i <= gen_data->n_pipes)
			{
				close(gen_data->pipe[i][0]);
				close(gen_data->pipe[i++][1]);
			}	
		}
	}
	gen_data->pipe_pos++;
	gen_data->exec_pos++;
}

void	ft_exec2(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	gen_data->pid = fork();
	if (gen_data->pid == 0)
	{
		ft_child(gen_data, position, n_built);
		ft_status_error(gen_data, position, n_built);
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
	else
	{
		ft_father(gen_data, position, n_built);
		i = gen_data->sort[gen_data->exec_pos - 1];
		if (i == '1' && gen_data->sort[gen_data->exec_pos])
			ft_exec(gen_data, position + 1, n_built);
		else if (i == '0' && gen_data->sort[gen_data->exec_pos])
			ft_exec(gen_data, position, n_built + 1);
		wait(NULL);
	}
}
