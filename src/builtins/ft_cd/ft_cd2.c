/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:02:53 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 21:03:40 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_change_pwd(char **env)
{
	int		x;
	char	*buf;

	x = 0;
	buf = getcwd(0, 0);
	while (env[++x])
	{
		if (ft_strncmp(env[x], "PWD=", 4) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("PWD=", buf);
		}
	}
	free(buf);
}

void	ft_change_oldpwd_2(char *tmp, t_general_data *gen_data, int x, int y)
{
	if (x == ft_nb_arguments(gen_data->s_env))
	{
		x = ft_nb_arguments(gen_data->s_env);
		gen_data->s_env[x] = ft_strjoin("OLDPWD=", tmp);
		x++;
		gen_data->s_env[x] = 0;
		y = 1;
	}
	if (y == 0)
	{
		x = ft_nb_arguments(gen_data->env);
		gen_data->env[x++] = ft_strjoin("OLDPWD=", tmp);
		gen_data->env[x] = 0;
		x = ft_nb_arguments(gen_data->s_env);
		gen_data->s_env[x++] = ft_strjoin("OLDPWD=", tmp);
		gen_data->s_env[x] = 0;
	}
	ft_change_pwd(gen_data->env);
	ft_change_good_status(gen_data->env, gen_data);
}

void	ft_change_oldpwd(char *tmp, t_general_data *gen_data)
{
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (gen_data->env[++x])
	{
		if (ft_strncmp(gen_data->env[x], "OLDPWD=", 7) == 0)
		{
			free(gen_data->env[x]);
			gen_data->env[x] = ft_strjoin("OLDPWD=", tmp);
			y = 1;
		}
	}
	x = -1;
	while (gen_data->s_env[++x])
	{
		if (ft_strncmp(gen_data->s_env[x], "OLDPWD=", 7) == 0)
		{
			free(gen_data->s_env[x]);
			gen_data->s_env[x] = ft_strjoin("OLDPWD=", tmp);
		}
	}
	ft_change_oldpwd_2(tmp, gen_data, x, y);
}

void	ft_error_cd(char *arguments, char **env, t_general_data *gen_data)
{
	if (access(arguments, F_OK) != -1)
	{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(arguments, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else
	{
		ft_putstr_fd("cd: no such file or directory: ", 2);
		ft_putstr_fd(arguments, 2);
		ft_putstr_fd("\n", 2);
	}
	ft_change_permission_status(env, gen_data);
}

void	ft_reset_pwd_2(t_general_data *gen_data, char *buf, int y)
{
	if (y == ft_nb_arguments(gen_data->env))
	{
		gen_data->env[y++] = ft_strjoin("PWD=", buf);
		gen_data->env[y] = 0;
	}
}
