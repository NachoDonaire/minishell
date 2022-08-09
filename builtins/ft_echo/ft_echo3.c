/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:46:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 16:06:37 by sasalama         ###   ########.fr       */
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
	char	*copia;
	char	*tmp;

	copia = ft_substr(nb_argumentos[x], y + 1, ft_strlen(nb_argumentos[x]));
	while (ft_comillas_dobles2(copia) == 0)
		copia[ft_strlen(copia) - 1] = '\0';
	while (ft_comillas_simples2(copia) == 0)
		copia[ft_strlen(copia) - 1] = '\0';
	tmp = ft_strjoin(copia, "=");
	free(copia);
	z = -1;
	while (env[++z])
	{
		y = ft_strlen(tmp);
		if (ft_strncmp(env[z], tmp, y) == 0)
		{
			free(tmp);
			copia = ft_strchr(env[z], '=');
			tmp = ft_substr(copia, 1, ft_strlen(copia));
			printf("%s", tmp);
			free(tmp);
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
