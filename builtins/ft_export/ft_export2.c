/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:49:45 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/05 12:50:14 by salustianos      ###   ########.fr       */
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

char	*ft_valor(char *v)
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

int	ft_buscar_variable(char *v, char **env)
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

void	ft_crear_variable(char *variable, char *valor, char **env)
{
	int		x;
	char	*copia;
	char	*tmp;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "_=", 2) == 0)
		{
			if (valor)
				copia = ft_strjoin(variable, valor);
			else
				copia = ft_substr(variable, 0, ft_strlen(variable));
			tmp = ft_substr(env[x], 0, ft_strlen(env[x]));
			env[x] = copia;
			x++;
			env[x] = tmp;
			x++;
			env[x] = NULL;
			break ;
		}
		x++;
	}
}

void	ft_sustituir_variable(char *variable, char *valor, char **env)
{
	int		x;
	char	*copia;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], variable, ft_strlen(variable) - 1) == 0)
		{
			if (!valor)
				break ;
			copia = ft_strjoin(variable, valor);
			env[x] = copia;
			break ;
		}
		x++;
	}
}