/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:35:02 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 12:30:01 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reserva(t_general_data *gen_data)
{
	gen_data->cmd = malloc(sizeof(t_cmd_data) * (gen_data->n_pipes + 1));
	gen_data->blt = malloc(sizeof(t_builtin_data) * (gen_data->n_pipes + 1));
	gen_data->sort = malloc(sizeof(char) * (gen_data->n_pipes + 1));
	gen_data->cmd->fd = malloc(1);
	gen_data->blt->fd = malloc(1);
	gen_data->cmd->fd[0] = STDOUT_FILENO;
	gen_data->blt->fd[0] = STDOUT_FILENO;
}

void	needed_free(t_general_data *gen_data, int y)
{
	int	i;

	i = 0;
	while (i < gen_data->n_built)
	{
		if (gen_data->blt[i].blt)
			free(gen_data->blt[i].blt);
		if (gen_data->blt[i].args)
			ft_free_arg(gen_data->blt[i].args);
		if (gen_data->blt[i].fd[0])
			free(gen_data->blt[i].fd);
		i++;
	}
	i = 0;
	while (i < y)
	{
		if (gen_data->cmd[i].cmd)
			free(gen_data->cmd[i].cmd);
		if (gen_data->cmd[i].args[0])
			ft_free_arg(gen_data->cmd[i].args);
		if (gen_data->cmd[i].fd[0])
			free(gen_data->cmd[i].fd);
		if (gen_data->cmd[i].out[0])
			ft_free_arg(gen_data->cmd[i].out);
		if (gen_data->cmd[i].in[0])
			ft_free_arg(gen_data->cmd[i].in);
		i++;
	}
}
