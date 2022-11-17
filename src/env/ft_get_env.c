/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:13 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 21:19:55 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_shlvl(char *s)
{
	int	x;

	x = ft_strlen(s);
	while (x >= 0)
	{
		if (s[x] >= '0' && s[x] <= '8')
		{
			s[x]++;
			break ;
		}
		if (s[x] == '9')
			s[x] = '0';
		x--;
	}
}

int	ft_size_env(char **envp)
{
	int	x;

	x = 0;
	while (envp[x])
		x++;
	return (x);
}

char	**get_env(char **envp)
{
	int		x;
	int		y;
	int		a;
	char	**env;

	y = 0;
	a = ft_size_env(envp);
	env = malloc(sizeof(char *) * (a + 2));
	x = -1;
	while (envp[++x])
	{
		env[x] = malloc(sizeof(char) * ft_strlen(envp[x]) + 1);
		y = -1;
		while (envp[x][++y])
			env[x][y] = envp[x][y];
		env[x][y] = '\0';
		if (ft_strncmp(env[x], "SHLVL=", 6) == 0)
			ft_shlvl(env[x]);
	}
	env[x] = ft_substr("?=0", 0, 3);
	env[x + 1] = NULL;
	return (env);
}

void	ft_env(t_general_data *gen_data)
{
	int		x;
	int		y;

	x = 0;
	while (gen_data->env[x])
	{
		if (ft_strncmp(gen_data->env[x], "?=", 2) != 0)
		{
			if (ft_equal(gen_data->env[x]) != 0)
			{
				y = 0;
				while (gen_data->blt->fd_out[y])
				{
					ft_putstr_fd(gen_data->env[x], gen_data->blt->fd_out[y]);
					ft_putstr_fd("\n", gen_data->blt->fd_out[y]);
					y++;
				}
			}
		}
		x++;
	}
}

void	ft_check_secret_env(t_general_data *gen_data)
{
	int		x;
	char	*s;

	x = 0;
	gen_data->path = 1;
	while (gen_data->s_env[x])
	{
		if (ft_strncmp(gen_data->s_env[x], "PATH=", 5) == 0)
		{
			gen_data->path = 0;
			return ;
		}
		x++;
	}
	s = ft_substr("PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.", 0, 48);
	gen_data->s_env[x] = s;
	x++;
	gen_data->s_env[x] = 0;
}
