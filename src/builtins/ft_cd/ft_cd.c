/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 21:03:30 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_reset_pwd_3(t_general_data *gen_data, char *buf)
{
	int	y;

	y = -1;
	while (gen_data->s_env[++y])
	{
		if (ft_strncmp(gen_data->s_env[y], "PWD=", 4) == 0)
		{
			free(gen_data->s_env[y]);
			gen_data->s_env[y] = ft_strjoin("PWD=", buf);
			break ;
		}
	}
	if (y == ft_nb_arguments(gen_data->s_env))
	{
		gen_data->s_env[y++] = ft_strjoin("PWD=", buf);
		gen_data->s_env[y] = 0;
	}
	free(buf);
}

void	ft_reset_pwd(t_general_data *gen_data)
{
	int		y;
	char	*buf;

	y = -1;
	buf = getcwd(NULL, 0);
	while (gen_data->env[++y])
	{
		if (ft_strncmp(gen_data->env[y], "PWD=", 4) == 0)
		{
			free(gen_data->env[y]);
			gen_data->env[y] = ft_strjoin("PWD=", buf);
			break ;
		}
	}
	ft_reset_pwd_2(gen_data, buf, y);
	ft_reset_pwd_3(gen_data, buf);
}

void	ft_cd(t_general_data *gen_data, int p)
{
	char	*tmp;

	if (!gen_data->blt[p].args[1])
	{
		tmp = getcwd(NULL, 0);
		if (chdir(getenv("HOME")) != 0)
		{
			ft_putstr_fd("minishell : cd: HOME not set\n", 2);
			ft_change_permission_status(gen_data->env, gen_data);
		}
		else
			ft_change_oldpwd(tmp, gen_data);
		free(tmp);
	}
	else
	{
		tmp = getcwd(NULL, 0);
		if (chdir(gen_data->blt[p].args[1]) != 0)
			ft_error_cd(gen_data->blt[p].args[1], gen_data->env, gen_data);
		else
			ft_change_oldpwd(tmp, gen_data);
		free(tmp);
	}
	ft_reset_pwd(gen_data);
}
