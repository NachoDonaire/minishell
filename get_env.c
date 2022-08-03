/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:16:04 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/03 18:25:32 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

	x = 0;
	y = 0;
	while (envp[x])
		x++;
	env = malloc(sizeof(char*) * x);
	x = -1;
	while (envp[++x])
	{
		y = 0;
		while (envp[x][y])
			y++;
		env[x] = malloc(sizeof(char) * y);
		y = -1;
		while (envp[x][++y])
			env[x][y] = envp[x][y];
		env[x][y] = '\0';
		if (ft_strncmp(env[x], "SHLVL=", 6) == 0)
			ft_shlvl(env[x]);
	}
	env[x] = NULL;
	return (env);
}

void	ft_env(char **env)
{
	int		x;
	int		z;

	x = -1;
	while (env[++x])
	{
		z = ft_strlen(env[x]);
		if (env[x][z - 1] != '=')
			printf("%s\n", env[x]);
	}
}

// TODO Implementar libreria libft en Mafefile para no añadir los archivos a mano
