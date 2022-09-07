/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 16:53:41 by sasalama         ###   ########.fr       */
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

static void	ft_change_variable_oldpwd(char **env, char *tmp)
{
	int		x;
	int		oldpwd;
	char	*buf;

	x = 0;
	oldpwd = 0;
	buf = getcwd(NULL, 0);
	while (env[++x])
	{
		if (ft_strncmp(env[x], "OLDPWD=", 7) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("OLDPWD=", tmp);
			oldpwd = 1;
		}
	}
	if (oldpwd == 0)
	{
		printf("minishell : cd: OLDPWD not set\n");
		chdir(tmp);
	}
	else if (oldpwd == 1)
		ft_change_pwd(env, buf);
	free(buf);
	ft_change_good_status(env);
}

static void	ft_error_arguments_cd(char *arguments, char **env)
{
	if (access(arguments, F_OK) != -1)
		printf("cd: %s: Permission denied\n", arguments);
	else
		printf("cd: no such file or directory: %s\n", arguments);
	ft_change_permission_status(env);
}

void	ft_cd(t_general_data *gen_data, int position)
{
	char	*tmp;

	if (!gen_data->blt[position].args[0])
	{
		tmp = getcwd(NULL, 0);
		if (chdir(getenv("HOME")) != 0)
		{
			printf("minishell : cd: HOME not set\n");
			ft_change_permission_status(gen_data->env);
		}
		else
			ft_change_variable_oldpwd(gen_data->env, tmp);
		free(tmp);
	}
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(gen_data->blt[position].args[0]) != 0)
			ft_error_arguments_cd(gen_data->blt[position].args[0], gen_data->env);
		else
			ft_change_variable_oldpwd(gen_data->env, tmp);
		free(tmp);
	}
}
