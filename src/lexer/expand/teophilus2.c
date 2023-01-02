/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:39:57 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/21 10:45:15 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*variable_pwd(t_general_data *gen_data)
{
	int		x;
	int		i;
	int		y;
	char	*jutels;

	i = 0;
	y = 0;
	x = 0;
	while (gen_data->s_env[x])
	{
		if (ft_strncmp(gen_data->s_env[x], "PWD=", 4) == 0)
			break ;
		x++;
	}
	if (x == ft_nb_arguments(gen_data->s_env))
		return ("");
	while (gen_data->s_env[x][y]
		&& gen_data->s_env[x][y] != '=')
		y++;
	i = ft_strlen(&gen_data->s_env[x][y + 1]);
	jutels = ft_substr(&gen_data->s_env[x][y + 1], 0, i);
	return (jutels);
}

char	*variable_oldpwd(t_general_data *gen_data)
{
	int		x;
	int		i;
	int		y;
	char	*jutels;

	i = 0;
	y = 0;
	x = 0;
	while (gen_data->s_env[x])
	{
		if (ft_strncmp(gen_data->s_env[x], "OLDPWD=", 7) == 0)
			break ;
		x++;
	}
	if (x == ft_nb_arguments(gen_data->s_env))
		return ("");
	while (gen_data->s_env[x][y]
		&& gen_data->s_env[x][y] != '=')
		y++;
	i = ft_strlen(&gen_data->s_env[x][y + 1]);
	jutels = ft_substr(&gen_data->s_env[x][y + 1], 0, i);
	return (jutels);
}

char	*variable_path(t_general_data *gen_data)
{
	int		x;
	int		i;
	int		y;
	char	*jutels;

	i = 0;
	y = 0;
	x = 0;
	while (gen_data->s_env[x])
	{
		if (ft_strncmp(gen_data->s_env[x], "PATH=", 5) == 0)
			break ;
		x++;
	}
	if (x == ft_nb_arguments(gen_data->s_env))
		return ("");
	while (gen_data->s_env[x][y]
		&& gen_data->s_env[x][y] != '=')
		y++;
	i = ft_strlen(&gen_data->s_env[x][y + 1]);
	jutels = ft_substr(&gen_data->s_env[x][y + 1], 0, i);
	return (jutels);
}

int	variable_size(t_general_data *gen_data, char *c)
{
	int	i;

	i = 0;
	while (gen_data->env[i] && ft_strncmp(c, gen_data->env[i], lens(c)) != 0)
		i++;
	return (i);
}

char	*not_variable(t_general_data *gen_data, char *c)
{
	if (ft_strncmp(c, "PWD=", 4) == 0 && gen_data->path == 1)
	{
		free(c);
		return (variable_pwd(gen_data));
	}
	else if (ft_strncmp(c, "OLDPWD=", 7) == 0 && gen_data->path == 1)
	{
		free(c);
		return (variable_oldpwd(gen_data));
	}
	else if (ft_strncmp(c, "PATH=", 5) == 0 && gen_data->path == 1)
	{
		free(c);
		return (variable_path(gen_data));
	}
	free(c);
	return ("");
}
