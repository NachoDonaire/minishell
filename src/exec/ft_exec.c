/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 10:07:40 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec(t_general_data *gen_data, int position, int n_built)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (gen_data->sort[gen_data->exec_pos])
	{
		if (gen_data->sort[gen_data->exec_pos + 1] && gen_data->n_pipes > 0)
		{
			if (pipe(gen_data->pipe[gen_data->pipe_pos]) < 0)
				write(1, "error\n", 6);
		}
		ft_exec2(gen_data, position, n_built);
	}
	return (position);
}

void	dup_reds(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	i = 0;
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		while (gen_data->cmd[position].fd_out[i] > 0)
			dup2(gen_data->cmd[position].fd_out[i++], 1);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		while (gen_data->blt[n_built].fd_out[i] > 2)
			dup2(gen_data->blt[n_built].fd_out[i++], 1);
	}
}

void	dup_in_reds(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	i = 0;
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		while (gen_data->cmd[position].fd_in[i] > 0)
			dup2(gen_data->cmd[position].fd_in[i++], 0);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		while (gen_data->blt[n_built].fd_in[i] > 0)
			dup2(gen_data->blt[n_built].fd_in[i++], 0);
	}
}

void	ft_father(t_general_data *gen_data, int position, int n_built)
{
	int	i;

	i = 0;
	if (n_built == 23)
		write(1, "a", 1);
	if (gen_data->n_pipes != 0)
	{
		if (gen_data->pipe_pos == 0)
			close(gen_data->pipe[gen_data->pipe_pos][1]);
		else
		{
			close(gen_data->pipe[gen_data->pipe_pos - 1][0]);
			close(gen_data->pipe[gen_data->pipe_pos][1]);
		}
	}
	while (gen_data->cmd[position].fd_out[i])
		i++;
	i--;
	dup2(gen_data->cmd[position].fd_out[i], 1);
	gen_data->pipe_pos++;
	gen_data->exec_pos++;
}
