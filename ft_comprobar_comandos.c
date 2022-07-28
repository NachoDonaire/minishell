/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comprobar_comandos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 20:00:30 by salustianos       #+#    #+#             */
/*   Updated: 2022/07/28 20:01:29 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_comprobar_cd(char *s)
{
	if (ft_strncmp(s, "cd", 2) == 0)
	{
		ft_cd();
		return (1);
	}
	return (0);
}

int	ft_comprobar_pwd(char *s)
{
	if (ft_strncmp(s, "pwd", 3) == 0)
	{
		ft_pwd();
		return (1);
	}
	return (0);
}

int	ft_comprobar_echo(char *s)
{
	if (ft_strncmp(s, "echo", 4) == 0)
	{
		ft_echo();
		return (1);
	}
	return (0);
}

int	ft_comprobar_comando(char *s)
{
	int x;

	x = 0;
	x += ft_comprobar_pwd(s);
	x += ft_comprobar_cd(s);
	x += ft_comprobar_echo(s);

	return (x);
}