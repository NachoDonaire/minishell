/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:40:22 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/12 14:10:46 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_status_error(t_general_data *gen_data, int position, int n_built)
{
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		ft_putstr_fd("Minishell: command not found: ", 2);
		ft_putstr_fd(gen_data->cmd[position].cmd, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		ft_putstr_fd("Minishell: command not found: ", 2);
		ft_putstr_fd(gen_data->blt[n_built].blt, 2);
		ft_putstr_fd("\n", 2);
	}
}

void	ft_dup_in_reds_exit(char *s, int *pipedo)
{
	free(s);
	close(pipedo[1]);
	exit(0);
}

void	ft_dup_in_reds_wait(int piddy_gonzalez, int *pipedo,
	t_general_data *gen_data)
{
	waitpid(piddy_gonzalez, NULL, 0);
	if (gen_data->n_pipes != 0)
	{
		dup2(pipedo[0], 0);
		dup2(pipedo[1], 1);
	}
	else
		dup2(pipedo[0], 0);
	close(pipedo[1]);
	close(pipedo[0]);
}

void	ft_dup_in_reds_cmd(t_general_data *gen_data, int position,
		int *pipedo, int ref)
{
	int		i;

	(void)ref;
	i = -1;
	while (gen_data->cmd[position].in[++i])
	{
		if (gen_data->cmd[position].in_dred[i] == 0
			&& gen_data->cmd[position].syn_er != 23
			&& gen_data->cmd[position].in_dred[i + 1] != 1)
			dup2(gen_data->cmd[position].fd_in[i], 0);
		else if (gen_data->cmd[position].in_dred[i] == 1
			&& gen_data->cmd[position].syn_er != 23)
			ft_dup_in_reds_cm2(gen_data, position, pipedo, i);
	}
}

void	ft_dup_in_reds_blt(t_general_data *gen_data, int n_built, int *pipedo)
{
	int		i;

	i = -1;
	while (gen_data->blt[n_built].in[++i])
	{
		if (gen_data->blt[n_built].in_dred[i] == 0)
			dup2(gen_data->blt[n_built].fd_in[i], 0);
		else if (gen_data->blt[n_built].in_dred[i] == 1)
			ft_dup_in_reds_blt2(gen_data, n_built, pipedo, i);
	}
}
