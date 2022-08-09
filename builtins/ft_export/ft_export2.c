/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:47 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 17:18:57 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_variables(char *v)
{
	int		x;
	int		y;
	char	*copia;

	x = 0;
	y = 0;
	if (ft_strncmp(v, "=", ft_strlen(v) - 1) == 0)
		return (v);
	while (v[x])
	{
		if (v[x] == '=')
		{
			copia = malloc(sizeof(char) * ft_strlen(v));
			while (y <= x)
			{
				copia[y] = v[y];
				y++;
			}
			copia[y] = '\0';
			return (copia);
		}
		x++;
	}
	return (v);
}

char	*ft_value(char *v)
{
	int	x;

	x = 0;
	while (v[x])
	{
		if (v[x] == '=' && v[x + 1])
		{
			x++;
			return (&v[x]);
		}
		x++;
	}
	return (NULL);
}

int	ft_find_variable(char *v, char **env)
{
	int		x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(v, env[x], ft_strlen(v) - 1) == 0)
			return (1);
		x++;
	}
	return (0);
}

void	ft_create_variable(char *variable, char *value, char **env)
{
	int		x;
	char	*copy;
	char	*tmp;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "_=", 2) == 0)
		{
			if (value)
				copy = ft_strjoin(variable, value);
			else
				copy = ft_substr(variable, 0, ft_strlen(variable));
			tmp = ft_substr(env[x], 0, ft_strlen(env[x]));
			free(env[x]);
			env[x] = copy;
			x++;
			free(env[x]);
			env[x] = tmp;
			x++;
			env[x] = NULL;
			break ;
		}
		x++;
	}
}

void	ft_replace_variable(char *variable, char *value, char **env)
{
	int		x;
	char	*copy;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], variable, ft_strlen(variable) - 1) == 0)
		{
			if (!value)
				break ;
			copy = ft_strjoin(variable, value);
			free(env[x]);
			env[x] = copy;
			break ;
		}
		x++;
	}
}
