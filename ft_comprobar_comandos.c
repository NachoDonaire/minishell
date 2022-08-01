/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobar_comandos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:00:30 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/01 15:23:34 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_comprobar_cd(char *s, char **env)
{
	if (ft_strncmp(s, "cd", 3) == 0)
	{
		ft_cd(env);
		return (1);
	}
	return (0);
}

int	ft_comprobar_pwd(char *s)
{
	if (ft_strncmp(s, "pwd", 4) == 0)
	{
		ft_pwd();
		return (1);
	}
	return (0);
}

int	ft_comprobar_echo(char *s, char **env)
{
	if (ft_strncmp(s, "echo", 5) == 0)
	{
		ft_echo(env);
		return (1);
	}
	return (0);
}

int	ft_comprobar_export(char *s, char **env)
{
	if (ft_strncmp(s, "export", 7) == 0)
	{
		ft_export(env);
		return (1);
	}
	return (0);
}

int	ft_comprobar_unset(char *s, char **env)
{
	if (ft_strncmp(s, "unset", 6) == 0)
	{
		ft_unset(env);
		return (1);
	}
	return (0);
}

int	ft_comprobar_env(char *s, char **envp)
{
	if (ft_strncmp(s, "env", 4) == 0)
	{
		ft_env(envp);
		return (1);
	}
	return (0);
}

int	ft_comprobar_comando(char *s, char **tmp)
{
	int x;

	x = 0;
	x += ft_comprobar_pwd(s);
	x += ft_comprobar_cd(s, tmp);
	x += ft_comprobar_echo(s, tmp);
	x += ft_comprobar_export(s, tmp);
	x += ft_comprobar_unset(s, tmp);
	x += ft_comprobar_env(s, tmp);

	return (x);
}