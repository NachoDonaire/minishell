/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 15:46:57 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_comillas_simples2(char *argumento)
{
	int	x;

	x = ft_strlen(argumento);
	while (x > 0)
	{
		if (argumento[x] == 39)
			return (0);
		x--;
	}
	return (1);
}

int	ft_comillas_dobles2(char *argumento)
{
	int	x;

	x = ft_strlen(argumento);
	while (x > 0)
	{
		if (argumento[x] == 34)
			return (0);
		x--;
	}
	return (1);
}

void	ft_imprimir_variable(char **nb_argumentos, int x, int y, char **env)
{
	int		z;
	char	*tmp;

	z = ft_strlen(nb_argumentos[x]);
	tmp = ft_substr(nb_argumentos[x], y + 1, z);
	while (ft_comillas_dobles2(tmp) == 0)
		tmp[ft_strlen(tmp) - 1] = '\0';
	while (ft_comillas_simples2(tmp) == 0)
		tmp[ft_strlen(tmp) - 1] = '\0';
	tmp = ft_strjoin(tmp, "=");
	z = -1;
	while (env[++z])
	{
		y = ft_strlen(tmp);
		if (ft_strncmp(env[z], tmp, y) == 0)
		{
			tmp = ft_strchr(env[z], '=');
			tmp = ft_substr(tmp, 1, ft_strlen(tmp));
			printf("%s", tmp);
			break ;
		}
	}
}

int	ft_imprimir_comilla_doble(char *argumento)
{
	int	x;
	int	z;

	x = 0;
	z = ft_strlen(argumento) - 1;
	while (argumento[x])
	{
		if (argumento[x] == 39)
		{
			if (argumento[x + 1] == 34 && argumento[z] != 34)
				return (0);
			return (1);
		}
		x++;
	}
	return (1);
}

int	ft_imprimir_comilla_simple(char *argumento)
{
	int	x;
	int	z;

	x = 0;
	z = ft_strlen(argumento) - 1;
	while (argumento[x])
	{
		if (argumento[x] == 34)
		{
			if (argumento[x + 1] == 39 && argumento[z] != 39)
				return (0);
			return (1);
		}
		x++;
	}
	return (1);
}
