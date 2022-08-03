/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobar_comandos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:00:30 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/03 18:25:07 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_comprobar_env(char *s, char **envp)
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
	int	x;

	x = 0;
	x += ft_comprobar_pwd(s);
	x += ft_comprobar_cd(s, tmp);
	x += ft_comprobar_echo(s, tmp);
	x += ft_comprobar_export(s, tmp);
	x += ft_comprobar_unset(s, tmp);
	x += ft_comprobar_env(s, tmp);

	return (x);
}
