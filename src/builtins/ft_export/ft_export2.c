/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:57 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:44:38 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

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
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	y = 0;
	while (v[x])
	{
		if (v[x] == '=' && v[x + 1])
		{
			x++;
			y = x;
			while (v[y])
				y++;
			tmp = malloc(y + 1);
			y = 0;
			while (v[x])
				tmp[y++] = v[x++];
			tmp[y] = '\0';
			return (tmp);
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
			free(env[x + 1]);
			env[x] = copy;
			env[x + 1] = tmp;
			env[x + 2] = NULL;
			break ;
		}
		x++;
	}
}

void	ft_replace_v2(char *variable, char *value, t_general_data *gen_data)
{
	int		x;
	int		y;
	char	*copy;

	x = 0;
	while (gen_data->env[x])
	{
		y = ft_strlen(variable) - 1;
		if (ft_strncmp(gen_data->env[x], variable, y) == 0)
		{
			if (!value)
				break ;
			copy = ft_strjoin(variable, value);
			free(gen_data->env[x]);
			gen_data->env[x] = copy;
			if (ft_strncmp(copy, "PWD", 3) == 0)
			{
				free(gen_data->s_env[x]);
				gen_data->s_env[x] = copy;
			}
			break ;
		}
		x++;
	}
}
