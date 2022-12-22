/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:16:43 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/16 20:16:32 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_child_pipes(t_general_data *gen_data, int position, int n_built)
{
	if (gen_data->pipe_pos == 0)
	{
		close(gen_data->pipe[gen_data->pipe_pos][0]);
		if (check_xlacara(gen_data, position, n_built) != 23)
			dup2(gen_data->pipe[gen_data->pipe_pos][1], 1);
		close(gen_data->pipe[gen_data->pipe_pos][1]);
	}
	else if (gen_data->pipe_pos > 0 && gen_data->pipe_pos < gen_data->n_pipes)
	{
		if (check_xlacara(gen_data, position, n_built) != 23)
		{
			dup2(gen_data->pipe[gen_data->pipe_pos - 1][0], 0);
			dup2(gen_data->pipe[gen_data->pipe_pos][1], 1);
			gen_data->raskolnikof++;
		}
		close(gen_data->pipe[gen_data->pipe_pos][0]);
	//	dup2(gen_data->pipe[gen_data->pipe_pos - 1][0], 0);
		close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
	//	dup2(gen_data->pipe[gen_data->pipe_pos][1], 1);
		close(gen_data->pipe[gen_data->pipe_pos][1]);
	}
	else
	{
		if (check_xlacara(gen_data, position, n_built) != 23)
			dup2(gen_data->pipe[gen_data->pipe_pos - 1][0], 0);
		close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
	}
	dup_in_reds(gen_data, position, n_built);
}

void	ft_child_not_pipes(t_general_data *gen_data, int position, int n_built)
{
	int	exec;

	exec = 0;
	dup_in_reds(gen_data, position, n_built);
	if (gen_data->cmd[position].can_exec != 0)
		dup_reds(gen_data, position, n_built);
	if (gen_data->cmd[position].can_exec == 0)
	{
		if (gen_data->cmd[position].syn_er == 23)
		{
			perror("Syntax error ");
		}
		exit (1);
	}
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
	//dup_in_reds(gen_data, position, n_built);
	if (gen_data->n_pipes == 0)
		ft_child_not_pipes(gen_data, position, n_built);
	else
		ft_child_pipes(gen_data, position, n_built);
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		if (gen_data->cmd[position].can_exec != 0)
		{
			dup_reds(gen_data, position, n_built);
			s3[0] = gen_data->cmd[position].cmd;
		}
		if (gen_data->cmd[position].can_exec == 0)
		{
			error_can_exec(gen_data, n_built, position, 0);
		}
		ft_child_2(gen_data, s3, position);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		dup_reds(gen_data, position, n_built);
		s3[1] = gen_data->blt[n_built].blt;
		s3[1] = check_cmd(s3[1], gen_data);
		if (gen_data->blt[n_built].can_exec == 0)
			error_can_exec(gen_data, n_built, position, 1);
		execve(s3[1], gen_data->blt[n_built].args, gen_data->env);
	}
}

void	ft_father(t_general_data *gen_data)
{
	int	i;

	i = 0;
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
		ft_father(gen_data);
		i = gen_data->sort[gen_data->exec_pos - 1];
		wait(NULL);
		if (i == '1' && gen_data->sort[gen_data->exec_pos])
			ft_exec(gen_data, position + 1, n_built);
		else if (i == '0' && gen_data->sort[gen_data->exec_pos])
			ft_exec(gen_data, position, n_built + 1);
		//wait(NULL);
	}
}
