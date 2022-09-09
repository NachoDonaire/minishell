/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:35:02 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 14:05:21 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reserva(t_general_data *gen_data)
{
	gen_data->cmd = malloc(sizeof(t_cmd_data) * (gen_data->n_pipes + 1));
	gen_data->blt = malloc(sizeof(t_builtin_data) * (gen_data->n_pipes + 1));
	gen_data->sort = malloc(sizeof(char) * (gen_data->n_pipes + 1));
/*	gen_data->cmd->fd_out = malloc(1);
	gen_data->blt->fd_out = malloc(1);
	gen_data->cmd->fd_out[0] = STDOUT_FILENO;
	gen_data->cmd->fd_out[1] = 0;
	gen_data->blt->fd_out[0] = STDOUT_FILENO;
	gen_data->blt->fd_out[1] = 0;
	*/
}

void	needed_free(t_general_data *gen_data, int y)
{
	int	i;
	int	z;
	int	w;

	w = 0;
	z = 0;
	i = 0;
	while (i < gen_data->n_built - 1)
	{
		if (gen_data->blt[i].blt)
			free(gen_data->blt[i].blt);
		if (gen_data->blt[i].args[0])
			ft_free_arg(gen_data->blt[i].args);
		if (gen_data->blt[i].fd_out)
			free(gen_data->blt[i].fd_out);
		if (gen_data->blt[i].fd_in)
			free(gen_data->blt[i].fd_in);
		if (gen_data->blt[i].out[0])
			ft_free_arg(gen_data->blt[i].out);
		if (gen_data->blt[i].in[0])
			ft_free_arg(gen_data->blt[i].in);

		i++;
	}
	i = 0;
	while (i < y)
	{
		if (gen_data->cmd[i].cmd)
			free(gen_data->cmd[i].cmd);
		if (gen_data->cmd[i].args[0])
			ft_free_arg(gen_data->cmd[i].args);
		if (gen_data->cmd[i].fd_out)
			free(gen_data->cmd[i].fd_out);
		if (gen_data->cmd[i].fd_in)
			free(gen_data->cmd[i].fd_in);
		if (gen_data->cmd[i].out[0])
			ft_free_arg(gen_data->cmd[i].out);
		if (gen_data->cmd[i].in[0])
			ft_free_arg(gen_data->cmd[i].in);
		i++;
	}
}
