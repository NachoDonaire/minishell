/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:46 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 15:27:58 by sasalama         ###   ########.fr       */
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

int	ft_equal(char *s)
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

static void	ft_find_env(char *argument, char **env)
{
	int	tmp;
	int	y;

	y = -1;
	while (env[++y])
	{
		tmp = ft_strlen(argument);
		if (ft_strncmp(argument, env[y], tmp) == 0)
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
	char	**arguments;

	x = -1;
	arguments = ft_split("señor= adios", ' '); // ? Provisional, this is given by the structure
	while (arguments[++x])
	{
		z = ft_strlen(arguments[x]) - 1;
		tmp = ft_equal(arguments[x]);
		if (arguments[x][z] != '=' && arguments[x][z + 1] == '\0' && tmp == 0)
		{
			arguments[x] = ft_strjoin(arguments[x], "=");
			z++;
		}
		if (arguments[x][z] == '=' && arguments[x][z + 1] == '\0')
			ft_find_env(arguments[x], env);
		else
		{
			printf("unset: %s: invalid parameter name\n", arguments[x]);
			break ;
		}
	}
	ft_free_arg(arguments);
	ft_change_good_status(env);
}
