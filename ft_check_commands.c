/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:20 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 12:42:58 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_env(char *s, char **envp)
{
	if (ft_strncmp(s, "env", 4) == 0)
	{
		ft_env(envp);
		return (1);
	}
	return (0);
}

void	ft_change_bad_status(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
			env[x] = ft_substr("?=127", 0, 6);
		x++;
	}
}

void	ft_change_permission_status(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
			env[x] = ft_substr("?=1", 0, 4);
		x++;
	}
}

void	ft_change_good_status(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
			env[x] = ft_substr("?=0", 0, 4);
		x++;
	}
}

void	ft_check_comand(char *s, char **env)
{
	int	x;

	x = 0;
	x += ft_check_pwd(s, env);
	x += ft_check_cd(s, env);
	x += ft_check_echo(s, env);
	x += ft_check_export(s, env);
	x += ft_check_unset(s, env);
	x += ft_check_env(s, env);
	if (x == 0)
		ft_change_bad_status(env);
}
