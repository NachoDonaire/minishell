/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 10:39:34 by sasalama         ###   ########.fr       */
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
	ft_change_good_status(env, gen_data);
}

static void	ft_error_cd(char *arguments, char **env, t_general_data *gen_data)
{
	if (access(arguments, F_OK) != -1)
		printf("cd: %s: Permission denied\n", arguments);
	else
		printf("cd: no such file or directory: %s\n", arguments);
	ft_change_permission_status(env, gen_data);
}

void	ft_cd(t_general_data *gen_data, int p)
{
	char	*tmp;

	if (!gen_data->blt[p].args[0])
	{
		tmp = getcwd(NULL, 0);
		if (chdir(getenv("HOME")) != 0)
		{
			printf("minishell : cd: HOME not set\n");
			ft_change_permission_status(gen_data->env, gen_data);
		}
		else
			ft_change_oldpwd(gen_data->env, tmp, gen_data);
		free(tmp);
	}
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(gen_data->blt[p].args[0]) != 0)
			ft_error_cd(gen_data->blt[p].args[0], gen_data->env, gen_data);
		else
			ft_change_oldpwd(gen_data->env, tmp, gen_data);
		free(tmp);
	}
}
