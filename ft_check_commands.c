/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/24 10:57:08 by sasalama         ###   ########.fr       */
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
		ft_exec(s, env); // ! NOT FUNCTIONAL (TEMPORARY)
}
