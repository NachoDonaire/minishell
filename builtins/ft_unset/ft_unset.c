/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:46 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/04 14:21:41 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_eliminate(char **env, int position)
{
	int	x;

	x = position;
	while (env[x + 1])
	{
		env[x] = env[x + 1];
		x++;
	}
	env[x] = NULL;
}

static int	ft_igual(char *s)
{
	int	x;

	x = 0;
	while (s[x])
	{
		if (s[x] == '=')
			return (1);
		x++;
	}
	return (0);
}

static void	ft_find_env(char *argumento, char **env)
{
	int	tmp;
	int	y;

	y = -1;
	while (env[++y])
	{
		tmp = ft_strlen(argumento);
		if (ft_strncmp(argumento, env[y], tmp) == 0)
		{
			ft_eliminate(env, y);
			break ;
		}
	}
}

void	ft_unset(char **env)
{
	int		x;
	int		z;
	int		tmp;
	char	**argumentos;

	x = -1;
	argumentos = ft_split("TERM= OLDPWD SHLVL=4", ' '); // ? Provisional, esto lo da la estructura
	while (argumentos[++x])
	{
		z = ft_strlen(argumentos[x]) - 1;
		tmp = ft_igual(argumentos[x]);
		if (argumentos[x][z] != '=' && argumentos[x][z + 1] == '\0' && tmp == 0)
		{
			argumentos[x] = ft_strjoin(argumentos[x], "=");
			z++;
		}
		if (argumentos[x][z] == '=' && argumentos[x][z + 1] == '\0')
			ft_find_env(argumentos[x], env);
		else
		{
			printf("unset: %s: invalid parameter name\n", argumentos[x]);
			break ;
		}
	}
}
