/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/21 11:05:43 by sasalama         ###   ########.fr       */
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
		while (gen_data->cmd[position].fd_out[i] > 0)
			dup2(gen_data->cmd[position].fd_out[i++], 1);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		while (gen_data->blt[n_built].fd_out[i] > 0)
			dup2(gen_data->blt[n_built].fd_out[i++], 1);
	}
}

void	ft_dup_in_reds_cm2(t_general_data *gen_data, int p, int *pipedo, int i)
{
	int		piddy_gonzalez;
	char	*s;
	int		x;

	piddy_gonzalez = fork();
	if (piddy_gonzalez == 0)
	{
		close(pipedo[0]);
		s = readline("> ");
		x = lens(gen_data->cmd[p].in[i]);
		if (ft_strncmp(s, gen_data->cmd[p].in[i], x) != 0)
		{
			ft_putstr_fd(s, pipedo[1]);
			ft_putstr_fd("\n", pipedo[1]);
		}
		while (ft_strncmp(s, gen_data->cmd[p].in[i], x) != 0)
		{
			ft_putstr_fd(s, pipedo[1]);
			ft_putstr_fd("\n", pipedo[1]);
			s = readline("> ");
		}
		ft_dup_in_reds_exit(s, pipedo);
	}
	else
		ft_dup_in_reds_wait(piddy_gonzalez, pipedo);
}

void	ft_dup_in_reds_blt2(t_general_data *gen_data, int n_b, int *p, int i)
{
	char	*s;
	int		x;
	int		piddy_gonzalez;

	piddy_gonzalez = fork();
	if (piddy_gonzalez == 0)
	{
		close(p[0]);
		s = readline("> ");
		x = lens(gen_data->blt[n_b].in[i]);
		if (ft_strncmp(s, gen_data->blt[n_b].in[i], x) != 0)
		{
			ft_putstr_fd(s, p[1]);
			ft_putstr_fd("\n", p[1]);
		}
		while (ft_strncmp(s, gen_data->blt[n_b].in[i], x) != 0)
		{
			ft_putstr_fd(s, p[1]);
			ft_putstr_fd("\n", p[1]);
			s = readline("> ");
		}
		ft_dup_in_reds_exit(s, p);
	}
	else
		ft_dup_in_reds_wait(piddy_gonzalez, p);
}

void	dup_in_reds(t_general_data *gen_data, int position, int n_built)
{
	int		pipedo[2];

	pipe(pipedo);
	if (gen_data->sort[gen_data->exec_pos] == '1')
		ft_dup_in_reds_cmd(gen_data, position, pipedo);
	else if (gen_data->sort[gen_data->exec_pos] == '0')
		ft_dup_in_reds_blt(gen_data, n_built, pipedo);
}
