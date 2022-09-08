/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:13 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 10:56:01 by sasalama         ###   ########.fr       */
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

char	**get_env(char **envp)
{
	int		x;
	int		y;
	char	**env;

	y = 0;
	env = malloc(sizeof(char *) * 1024);
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
	env[x] = ft_substr("?=0", 0, 4);
	env[x + 1] = NULL;
	return (env);
}

void	ft_env(char **env)
{
	int		x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) != 0)
			if (ft_equal(env[x]) != 0)
				printf("%s\n", env[x]);
		x++;
	}
}
