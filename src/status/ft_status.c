/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:23 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:51:03 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_file(t_general_data *gen_data, int position, int cmd)
{
	int	i;

	i = 1;
	if (cmd == 0)
	{
		while (gen_data->cmd[position].args[i])
		{
			if (gen_data->cmd[position].args[i]
				&& access(gen_data->cmd[position].args[i], F_OK) != 1
				&& gen_data->cmd[position].args[i][0] != '-')
				ft_change_permission_status(gen_data->env, gen_data);
			i++;
		}
	}
	else
	{
		while (gen_data->blt[position].args[i])
		{
			if (gen_data->blt[position].args[i]
				&& access(gen_data->blt[position].args[i], F_OK) != 1
				&& gen_data->blt[position].args[i][0] != '-')
				ft_change_permission_status(gen_data->env, gen_data);
			i++;
		}
	}
}

void	ft_status_blt(t_general_data *gen_data, int position)
{
	char	*path;
	char	*copy;
	char	**tmp;
	int		x;

	x = ft_strlen(gen_data->cmd[position].cmd);
	copy = ft_substr(gen_data->cmd[position].cmd, 0, x);
	tmp = ft_split(copy, '/');
	free(copy);
	if (!tmp)
		return ;
	x = ft_nb_arguments(tmp) - 1;
	copy = ft_substr(tmp[x], 0, ft_strlen(tmp[x]));
	ft_free_arg(tmp);
	ft_path(copy, gen_data->env, &path);
	if (path == NULL)
	{
		free(copy);
		ft_change_bad_status(gen_data->env, gen_data);
		return ;
	}
	free(path);
	free(copy);
	ft_file(gen_data, position, 0);
}

void	ft_status_cmd(t_general_data *gen_data, int position)
{
	char	*path;
	char	*copy;
	char	**tmp;
	int		x;

	x = ft_strlen(gen_data->blt[position].blt);
	copy = ft_substr(gen_data->blt[position].blt, 0, x);
	tmp = ft_split(copy, '/');
	free(copy);
	x = ft_nb_arguments(tmp) - 1;
	copy = ft_substr(tmp[x], 0, ft_strlen(tmp[x]));
	ft_free_arg(tmp);
	ft_path(copy, gen_data->env, &path);
	if (path == NULL)
	{
		free(copy);
		ft_change_bad_status(gen_data->env, gen_data);
		return ;
	}
	free(path);
	free(copy);
	ft_file(gen_data, position, 1);
}

void	ft_check_status(t_general_data *gen_data, int position)
{
	ft_change_good_status(gen_data->env, gen_data);
	if (gen_data->n_cmd != 0)
	{
		if (gen_data->cmd[position].syn_er == 23
			|| gen_data->cmd[position].syn_er == 420)
			return ;
		ft_status_blt(gen_data, position);
	}
	else if (gen_data->n_built != 0)
	{
		ft_status_cmd(gen_data, gen_data->n_built - 1);
	}
}
