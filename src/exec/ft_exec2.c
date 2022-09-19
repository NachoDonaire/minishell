/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:16:43 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/19 20:03:39 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_child_pipes(t_general_data *gen_data, int position)
{
	int x;

	x = 0;
	while (gen_data->cmd[position].fd_out[x + 1])
	{
		dup2(gen_data->cmd[position].fd_out[x], 1);
		close(gen_data->cmd[position].fd_out[x]);
		x++;
	}
	if (position == 0)
	{
		close(gen_data->pipe[position][0]);
		dup2(gen_data->pipe[position][1], 1);
		close(gen_data->pipe[position][1]);
	}
	else if (position > 0 && position < gen_data->n_cmd - 1)
	{
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
	}
}

void	ft_child_not_pipes(t_general_data *gen_data, int position)
{
	int	exec;
	int	x;

	exec = 0;
	x = 0;
	while (gen_data->cmd[position].fd_out[x])
	{
		dup2(gen_data->cmd[position].fd_out[x], 1);
		close(gen_data->cmd[position].fd_out[x]);
		x++;
	}
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

void	ft_child(t_general_data *gen_data, int position)
{
	int	exec;

	exec = 0;
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (gen_data->n_pipes == 0)
		ft_child_not_pipes(gen_data, position);
	else
		ft_child_pipes(gen_data, position);
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

void	ft_father(t_general_data *gen_data, int position)
{
	if (gen_data->n_pipes != 0)
	{
		if (position == 0)
			close(gen_data->pipe[position][1]);
		else
		{
			close(gen_data->pipe[position - 1][0]);
			close(gen_data->pipe[position][1]);
		}
	}
	gen_data->exec_pos++;
}

void	ft_exec2(t_general_data *gen_data, int position)
{
	gen_data->pid = fork();
	if (gen_data->pid == 0)
		ft_child(gen_data, position);
	else
	{
		ft_father(gen_data, position);
		wait(NULL);
		ft_exec(gen_data, position + 1);
	}
}
