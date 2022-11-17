/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 11:52:12 by sasalama         ###   ########.fr       */
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

void	dup_in_reds(t_general_data *gen_data, int position, int n_built)
{
	int		i;
	int		pipedo[2];
	char	*s;
	int		piddy_gonzalez;
	int		x;

	i = -1;
	pipe(pipedo);
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		while (gen_data->cmd[position].in[++i])
		{
			if (gen_data->cmd[position].in_dred[i] == 0)
				dup2(gen_data->cmd[position].fd_in[i], 0);
			else if (gen_data->cmd[position].in_dred[i] == 1)
			{
				piddy_gonzalez = fork();
				if (piddy_gonzalez == 0)
				{
					close(pipedo[0]);
					s = readline("> ");
					x = lens(gen_data->cmd[position].in[i]);
					if (ft_strncmp(s, gen_data->cmd[position].in[i], x) != 0)
					{
						ft_putstr_fd(s, pipedo[1]);
						ft_putstr_fd("\n", pipedo[1]);
					}
					x = lens(gen_data->cmd[position].in[i]);
					while (ft_strncmp(s, gen_data->cmd[position].in[i], x) != 0)
					{
						{
							ft_putstr_fd(s, pipedo[1]);
							ft_putstr_fd("\n", pipedo[1]);
						}
						s = readline("> ");
						break ;
					}
					free(s);
					close(pipedo[1]);
					exit(0);
				}
				else
				{
					waitpid(piddy_gonzalez, NULL, 0);
					close(pipedo[1]);
					dup2(pipedo[0], 0);
				}
			}
		}
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		while (gen_data->blt[n_built].in[++i])
		{
			if (gen_data->blt[n_built].in_dred[i] == 0)
				dup2(gen_data->blt[n_built].fd_in[i], 0);
			else if (gen_data->blt[n_built].in_dred[i] == 1)
			{
				piddy_gonzalez = fork();
				if (piddy_gonzalez == 0)
				{
					close(pipedo[0]);
					s = readline("> ");
					x = lens(gen_data->blt[n_built].in[i]);
					if (ft_strncmp(s, gen_data->blt[n_built].in[i], x) != 0)
					{
						ft_putstr_fd(s, pipedo[1]);
						ft_putstr_fd("\n", pipedo[1]);
					}
					x = lens(gen_data->blt[n_built].in[i]);
					while (ft_strncmp(s, gen_data->blt[n_built].in[i], x) != 0)
					{
						ft_putstr_fd(s, pipedo[1]);
						ft_putstr_fd("\n", pipedo[1]);
						s = readline("> ");
					}
					free(s);
					close(pipedo[1]);
					exit(0);
				}
				else
				{
					waitpid(piddy_gonzalez, NULL, 0);
					close(pipedo[1]);
					dup2(pipedo[0], 0);
				}
			}
		}	
	}
}

void	ft_check_blt_args(t_general_data *gen_data, int n_built)
{
	int	x;

	x = ft_strncmp(gen_data->blt[n_built].blt, "pwd", 3);
	if (x == 0 && gen_data->blt[n_built].args[1])
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}
