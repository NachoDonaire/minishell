/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobar_builtins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:15:33 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/02 13:17:10 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_comprobar_cd(char *s, char **env)
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
