/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:23:44 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 15:41:37 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_fds2(t_general_data *gen_data)
{
	int	y;
	int	i;

	i = -1;
	while (++i < gen_data->n_cmd)
	{
		y = 0;
		if (gen_data->cmd[i].syn_er != 420 && gen_data->cmd[i].syn_er != 23)
		{
			while (gen_data->cmd[i].fd_in[y] > 2 && gen_data->cmd[i].fd_in[y])
				close(gen_data->cmd[i].fd_in[y++]);
		}
	}
	i = -1;
	while (++i < gen_data->n_cmd)
	{
		y = 0;
		if (gen_data->cmd[i].syn_er != 420 && gen_data->cmd[i].syn_er != 23)
		{
			while (gen_data->cmd[i].fd_out[y] > 2 && gen_data->cmd[i].fd_out[y])
				close(gen_data->cmd[i].fd_out[y++]);
		}
	}
}

void	close_fds(t_general_data *gen_data)
{
	int	i;
	int	y;

	i = -1;
	while (++i < gen_data->n_built)
	{
		y = 0;
		while (gen_data->blt[i].fd_in[y] > 2)
			close(gen_data->blt[i].fd_in[y++]);
	}
	i = -1;
	while (++i < gen_data->n_built)
	{
		y = 0;
		while (gen_data->blt[i].fd_out[y] > 2)
			close(gen_data->blt[i].fd_out[y++]);
	}
	close_fds2(gen_data);
}

void	needed_free_cmd(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->cmd[i].cmd)
		free(gen_data->cmd[i++].cmd);
}

void	ft_free_all(t_general_data *gen_data, char *s)
{
	free(s);
	needed_free(gen_data, gen_data->n_cmd - gen_data->n_built);
}

void	free_heredoc(t_general_data *gen_data, int i)
{
	if (gen_data->cmd[i].in)
		ft_free_arg(gen_data->cmd[i].in);
	if (gen_data->cmd[i].in_dred)
		free(gen_data->cmd[i].in_dred);
	if (gen_data->cmd[i].out)
		ft_free_arg(gen_data->cmd[i].out);
	if (gen_data->cmd[i].fd_in)
		free(gen_data->cmd[i].fd_in);
	if (gen_data->cmd[i].dred)
		free(gen_data->cmd[i].dred);
	if (gen_data->cmd[i].fd_out)
		free(gen_data->cmd[i].fd_out);
}
