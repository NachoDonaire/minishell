/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/06 11:20:08 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_cd(t_general_data *gen_data)
{
	if (ft_strncmp(gen_data->blt.blt, "cd", 3) == 0)
	{
		ft_cd(gen_data);
		return (1);
	}
	return (0);
}

int	ft_check_pwd(t_general_data *gen_data)
{
	if (ft_strncmp(gen_data->blt.blt, "pwd", 4) == 0)
	{
		ft_pwd(gen_data->env);
		return (1);
	}
	return (0);
}

int	ft_check_echo(t_general_data *gen_data)
{
	if (ft_strncmp(gen_data->blt.blt, "echo", 5) == 0)
	{
		ft_echo(gen_data->env);
		return (1);
	}
	return (0);
}

int	ft_check_export(t_general_data *gen_data)
{
	if (ft_strncmp(gen_data->blt.blt, "export", 7) == 0)
	{
		ft_export(gen_data->env);
		return (1);
	}
	return (0);
}

int	ft_check_unset(t_general_data *gen_data)
{
	if (ft_strncmp(gen_data->blt.blt, "unset", 6) == 0)
	{
		ft_unset(gen_data->env);
		return (1);
	}
	return (0);
}
