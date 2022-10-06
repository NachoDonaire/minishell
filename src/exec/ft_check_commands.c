/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/06 13:03:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_env(t_general_data *gen_data, int x)
{
	if (gen_data->blt[x].blt)
	{
		if (ft_strncmp(gen_data->blt[x].blt, "env", 4) == 0)
		{
			ft_env(gen_data->env);
			return (1);
		}
	}
	return (0);
}

void	ft_built(t_general_data *gen_data, int x)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	ft_check_pwd(gen_data, x);
	ft_check_cd(gen_data, x);
	ft_check_echo(gen_data, x);
	ft_check_export(gen_data, x);
	ft_check_unset(gen_data, x);
	ft_check_env(gen_data, x);
}

int	ft_last_built(char *s)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s[x])
	{
		if (s[x] == '0')
			y = x;
		x++;
	}
	return (y);
}

void	ft_check_comand(t_general_data *gen_data)
{
	int	n_blt;
	int	n_cmd;

	n_cmd = 0;
	n_blt = 0;
	if (gen_data->n_pipes == 0 && gen_data->built != 0)
	{
		ft_built(gen_data, n_blt);
		n_blt++;
	}
	else
	{
		n_cmd = ft_exec(gen_data, n_cmd, n_blt);
		ft_check_status(gen_data, n_cmd);
	}
	gen_data->exec_pos++;
}
