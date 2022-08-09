/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobar_comandos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:20 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 17:03:15 by sasalama         ###   ########.fr       */
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

void	ft_check_comand(char *s, char **tmp)
{
	int	x;

	x = 0;
	x += ft_check_pwd(s);
	x += ft_check_cd(s, tmp);
	x += ft_check_echo(s, tmp);
	x += ft_check_export(s, tmp);
	x += ft_check_unset(s, tmp);
	x += ft_check_env(s, tmp);
}
