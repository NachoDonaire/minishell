/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/06 11:18:47 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_check_env(t_general_data *gen_data)
{
	if (ft_strncmp(gen_data->blt.blt, "env", 4) == 0)
	{
		ft_env(gen_data->env);
		return (1);
	}
	return (0);
}

void	ft_check_comand(t_general_data *gen_data)
{
	int	x;

	x = 0;
	x += ft_check_pwd(gen_data);
	x += ft_check_cd(gen_data);
	x += ft_check_echo(gen_data);
	x += ft_check_export(gen_data);
	x += ft_check_unset(gen_data);
	x += ft_check_env(gen_data);
	//if (x == 0)
		//ft_exec(gen_data->cmd, gen_data->env); // ! NOT FUNCTIONAL (TEMPORARY)
}
