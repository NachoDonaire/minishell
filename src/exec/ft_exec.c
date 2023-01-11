/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/11 10:48:57 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec(t_general_data *gen_data, int position, int n_built)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (gen_data->exec_pos <= gen_data->n_pipes)
	{
		if (gen_data->exec_pos < gen_data->n_pipes && gen_data->n_pipes > 0)
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
		if (gen_data->cmd[position].syn_er != 23)
		{
			while (gen_data->cmd[position].fd_out[i] > 0)
				dup2(gen_data->cmd[position].fd_out[i++], 1);
		}
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		if (gen_data->blt[n_built].syn_er != 23)
		{
			while (gen_data->blt[n_built].fd_out[i] > 0)
				dup2(gen_data->blt[n_built].fd_out[i++], 1);
		}
	}
}

void	ft_dup_in_reds_cm2(t_general_data *gen_data, int p, int *pipedo, int i)
{
	int		piddy_gonzalez;

	piddy_gonzalez = fork();
	if (piddy_gonzalez == 0)
		ft_dup_in_reds_cm3(gen_data, p, pipedo, i);
	else
		ft_dup_in_reds_wait(piddy_gonzalez, pipedo, gen_data);
}

void	ft_dup_in_reds_blt2(t_general_data *gen_data, int n_b, int *p, int i)
{
	int		piddy_gonzalez;

	piddy_gonzalez = fork();
	if (piddy_gonzalez == 0)
		ft_dup_in_reds_blt3(gen_data, n_b, p, i);
	else
		ft_dup_in_reds_wait(piddy_gonzalez, p, gen_data);
}

void	dup_in_reds(t_general_data *gen_data, int position,
		int n_built, int ref)
{
	int		pipedo[2];

	pipe(pipedo);
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		if (gen_data->cmd[position].syn_er != 23
			&& gen_data->cmd[position].in[0])
			ft_dup_in_reds_cmd(gen_data, position, pipedo, ref);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		if (gen_data->blt[n_built].syn_er != 23 && gen_data->blt[n_built].in[0])
			ft_dup_in_reds_blt(gen_data, n_built, pipedo);
	}
}
