/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/07 18:47:59 by ndonaire         ###   ########.fr       */
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
	char	*s;

	i = 0;
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		while (gen_data->cmd[position].in[i])
		{
			if (gen_data->cmd[position].in_dred[i] == 0)
				dup2(gen_data->cmd[position].fd_in[i], 0);
			else if (gen_data->cmd[position].in_dred[i] == 1)
			{
				s = readline("");
				while (finder(s, gen_data->cmd[position].in[i]) == 0)
					s = readline("");
			}
			if (s)
				free(s);
			i++;
		}
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		while (gen_data->blt[n_built].in[i])
		{
			if (gen_data->blt[n_built].in_dred[i] == 0)
				dup2(gen_data->blt[n_built].fd_in[i], 0);
			else if (gen_data->blt[n_built].in_dred[i] == 1)
			{
				s = readline("");
				while (finder(s, gen_data->blt[n_built].in[i]) == 0)
					s = readline("");
				if (s)
					free(s);
			}
			i++;
		}	
	}
}

void	ft_check_blt_args(t_general_data *gen_data, int n_built)
{
	int	x;

	x = ft_strncmp(gen_data->blt[n_built].blt, "pwd", 3);
	if (x == 0 && gen_data->blt[n_built].args[1])
	{
		printf("pwd: too many arguments\n");
		gen_data->good_status = 127;
		exit (gen_data->good_status);
	}
}
