/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:15:33 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 12:36:41 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_cd(char *s, char **env)
{
	if (ft_strncmp(s, "cd", 3) == 0)
	{
		ft_cd(env);
		return (1);
	}
	return (0);
}

int	ft_check_pwd(char *s, char **env)
{
	if (ft_strncmp(s, "pwd", 4) == 0)
	{
		ft_pwd(env);
		return (1);
	}
	return (0);
}

int	ft_check_echo(char *s, char **env)
{
	if (ft_strncmp(s, "echo", 5) == 0)
	{
		ft_echo(env);
		return (1);
	}
	return (0);
}

int	ft_check_export(char *s, char **env)
{
	if (ft_strncmp(s, "export", 7) == 0)
	{
		ft_export(env);
		return (1);
	}
	return (0);
}

int	ft_check_unset(char *s, char **env)
{
	if (ft_strncmp(s, "unset", 6) == 0)
	{
		ft_unset(env);
		return (1);
	}
	return (0);
}
