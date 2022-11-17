/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 10:03:07 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_change_pwd(char **env, char *buf)
{
	int	x;

	x = 0;
	while (env[++x])
	{
		if (ft_strncmp(env[x], "PWD=", 4) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("PWD=", buf);
		}
	}
}

static void	ft_change_oldpwd(char **env, char *tmp, t_general_data *gen_data)
{
	int		x;
	char	*buf;
	int		y;

	x = -1;
	y = 0;
	buf = getcwd(NULL, 0);
	while (env[++x])
	{
		if (ft_strncmp(env[x], "OLDPWD=", 7) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("OLDPWD=", tmp);
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
		gen_data->env[x] = ft_strjoin("OLDPWD=", tmp);
		x++;
		gen_data->env[x] = 0;
		x = ft_nb_arguments(gen_data->s_env);
		gen_data->s_env[x] = ft_strjoin("OLDPWD=", tmp);
		x++;
		gen_data->s_env[x] = 0;
	}
	ft_change_pwd(env, buf);
	free(buf);
	ft_change_good_status(env, gen_data);
}

static void	ft_error_cd(char *arguments, char **env, t_general_data *gen_data)
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

void	ft_reset_pwd(t_general_data *gen_data)
{
	int		y;
	char	*buf;

	y = 0;
	buf = getcwd(NULL, 0);
	while (gen_data->env[y])
	{
		if (ft_strncmp(gen_data->env[y], "PWD=", 4) == 0)
		{
			free(gen_data->env[y]);
			gen_data->env[y] = ft_strjoin("PWD=", buf);
			free(buf);
			break ;
		}
		y++;
	}
	if (y == ft_nb_arguments(gen_data->env))
	{
		gen_data->env[y] = ft_strjoin("PWD=", buf);
		free(buf);
		y++;
		gen_data->env[y] = 0;
	}
	y = 0;
	buf = getcwd(NULL, 0);
	while (gen_data->s_env[y])
	{
		if (ft_strncmp(gen_data->s_env[y], "PWD=", 4) == 0)
		{
			free(gen_data->s_env[y]);
			gen_data->s_env[y] = ft_strjoin("PWD=", buf);
			free(buf);
			break ;
		}
		y++;
	}
	gen_data->s_env[y] = ft_strjoin("PWD=", buf);
	free(buf);
	y++;
	gen_data->s_env[y] = 0;
}

void	ft_cd(t_general_data *gen_data, int p)
{
	char	*tmp;

	if (!gen_data->blt[p].args[1])
	{
		tmp = getcwd(NULL, 0);
		if (chdir(getenv("HOME")) != 0)
		{
			ft_putstr_fd("minishell : cd: HOME not set\n", 2);
			ft_change_permission_status(gen_data->env, gen_data);
		}
		else
			ft_change_oldpwd(gen_data->env, tmp, gen_data);
		free(tmp);
	}
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(gen_data->blt[p].args[1]) != 0)
			ft_error_cd(gen_data->blt[p].args[1], gen_data->env, gen_data);
		else
			ft_change_oldpwd(gen_data->env, tmp, gen_data);
		free(tmp);
	}
	ft_reset_pwd(gen_data);
}
