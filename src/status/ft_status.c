/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/06 14:07:27 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_check_status(t_general_data *gen_data, int position)
{
	char	*path;
	char	*copy;
	char	**tmp;
	int		x;

	ft_change_good_status(gen_data->env, gen_data);
	if (gen_data->n_cmd != 0)
	{
		x = ft_strlen(gen_data->cmd[position].cmd);
		copy = ft_substr(gen_data->cmd[position].cmd, 0, x);
		tmp = ft_split(copy, '/');
		free(copy);
		x = ft_nb_arguments(tmp) - 1;
		copy = ft_substr(tmp[x], 0, ft_strlen(tmp[x]));
		ft_free_arg(tmp);
		ft_path(copy, gen_data->env, &path);
		if (path == NULL)
			ft_change_bad_status(gen_data->env, gen_data);
		free(path);
		free(copy);
	}
	else if (gen_data->n_built != 0)
	{
		x = ft_strlen(gen_data->blt[position].blt);
		copy = ft_substr(gen_data->blt[position].blt, 0, x);
		tmp = ft_split(copy, '/');
		free(copy);
		x = ft_nb_arguments(tmp) - 1;
		copy = ft_substr(tmp[x], 0, ft_strlen(tmp[x]));
		ft_free_arg(tmp);
		ft_path(copy, gen_data->env, &path);
		if (path == NULL)
			ft_change_bad_status(gen_data->env, gen_data);
		free(path);
		free(copy);
	}
	if (gen_data->n_built != 0)
	{
		x = gen_data->n_pipes;
		if (ft_strncmp(gen_data->blt[position].blt, "pwd", 3) == 0
			&& gen_data->blt[position].args[0] && x > 0)
			ft_change_bad_status(gen_data->env, gen_data);
	}
}

void	ft_change_bad_status(char **env, t_general_data *gen_data)
{
	int	x;

	gen_data->good_status = 127;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("?=", ft_itoa(gen_data->good_status));
		}
		x++;
	}
}

void	ft_change_permission_status(char **env, t_general_data *gen_data)
{
	int	x;

	gen_data->good_status = 126;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("?=", ft_itoa(gen_data->good_status));
		}
		x++;
	}
}

void	ft_change_good_status(char **env, t_general_data *gen_data)
{
	int	x;

	gen_data->good_status = 0;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("?=", ft_itoa(gen_data->good_status));
		}
		x++;
	}
}
