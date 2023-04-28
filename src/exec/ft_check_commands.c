/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_commands.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:03 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 16:36:43 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_env(t_general_data *gen_data, int x)
{
	if (gen_data->blt[x].blt)
	{
		if (ft_strncmp(gen_data->blt[x].blt, "env", 4) == 0)
		{
			ft_env(gen_data);
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

int	galois_blt(t_general_data *gen_data, int n_blt)
{
	int	piddy;
	int	pipedo[2];

	pipe(pipedo);
	if (gen_data->blt[n_blt].can_exec == 0)
		return (1);
	piddy = fork();
	if (piddy == 0)
	{
		ft_dup_in_reds_blt(gen_data, n_blt, pipedo);
		exit (0);
	}
	else
	{
		wait(NULL);
		ft_built(gen_data, n_blt);
		n_blt++;
	}
	return (0);
}

void	ft_check_comand(t_general_data *gen_data)
{
	int	n_blt;
	int	n_cmd;
	int	galois;

	n_cmd = 0;
	n_blt = 0;
	galois = 0;
	if (gen_data->n_pipes == 0 && gen_data->built != 0)
	{
		galois = galois_blt(gen_data, n_blt);
		if (galois == 1)
			return ;
	}
	else
	{
		n_cmd = ft_exec(gen_data, n_cmd, n_blt);
		ft_check_status(gen_data, gen_data->n_cmd - 1);
	}
	gen_data->exec_pos++;
}
