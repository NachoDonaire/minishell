/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:35:02 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 17:06:55 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reserva(t_general_data *gen_data)
{
	gen_data->cmd = malloc(sizeof(t_cmd_data) * (gen_data->n_pipes + 2));
	gen_data->blt = malloc(sizeof(t_builtin_data) * (gen_data->n_pipes + 1));
	gen_data->sort = malloc(sizeof(char) * (gen_data->n_pipes + 2));
}

void	ft_free_built_0(t_general_data *gen_data)
{
	int	i;

	i = 0;
	if (gen_data->n_built == 0)
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
		if (gen_data->blt[i].dred)
			free(gen_data->blt[i].dred);
		if (gen_data->blt[i].in_dred)
			free(gen_data->blt[i].in_dred);
		return ;
	}
}

void	ft_free_built(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (i < gen_data->n_built)
	{
		if (gen_data->blt[i].blt)
			free(gen_data->blt[i].blt);
		if (gen_data->blt[i].args)
			ft_free_arg(gen_data->blt[i].args);
		if (gen_data->blt[i].fd_out)
			free(gen_data->blt[i].fd_out);
		if (gen_data->blt[i].fd_in)
			free(gen_data->blt[i].fd_in);
		if (gen_data->blt[i].out)
			ft_free_arg(gen_data->blt[i].out);
		if (gen_data->blt[i].in)
			ft_free_arg(gen_data->blt[i].in);
		if (gen_data->blt[i].dred)
			free(gen_data->blt[i].dred);
		if (gen_data->blt[i].in_dred)
			free(gen_data->blt[i].in_dred);
		i++;
	}
}

void	frio_cmd(t_general_data *gen_data, int i)
{
	if (gen_data->cmd[i].cmd)
		free(gen_data->cmd[i].cmd);
	if (gen_data->cmd[i].args)
		ft_free_arg(gen_data->cmd[i].args);
	if (gen_data->cmd[i].fd_out)
		free(gen_data->cmd[i].fd_out);
	if (gen_data->cmd[i].fd_in)
		free(gen_data->cmd[i].fd_in);
	if (gen_data->cmd[i].out)
		ft_free_arg(gen_data->cmd[i].out);
	if (gen_data->cmd[i].in)
		ft_free_arg(gen_data->cmd[i].in);
	if (gen_data->cmd[i].dred)
		free(gen_data->cmd[i].dred);
	if (gen_data->cmd[i].in_dred)
		free(gen_data->cmd[i].in_dred);
}

void	ft_free_cmd(t_general_data *gen_data, int y)
{
	int	i;

	i = 0;
	while (i < y)
	{
		if (gen_data->cmd[i].syn_er == 420 || gen_data->cmd[i].syn_er == 23)
		{
			free_heredoc(gen_data, i);
		}
		else
			frio_cmd(gen_data, i);
		i++;
	}
}
