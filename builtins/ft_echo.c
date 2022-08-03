/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:10 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/03 18:29:55 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_n(char *argumento)
{
	int	x;

	x = 1;
	while (argumento[x])
	{
		if (argumento[x] != 'n')
			return (1);
		x++;
	}
	return (0);
}

static int	ft_dollar(char *argumento)
{
	int	x;

	x = 1;
	while (argumento[x])
	{
		if (argumento[x] != '$')
			return (1);
		x++;
	}
	return (0);
}

static void	ft_imprimir_variable(char **nb_argumentos, int x, int y, char **env)
{
	int		z;
	char	*tmp;

	z = ft_strlen(nb_argumentos[x]);
	tmp = ft_substr(nb_argumentos[x], y + 1, z);
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

static void	ft_imprimir(char **nb_argumentos, int x, char **env)
{
	int		y;

	if (ft_dollar(nb_argumentos[x]) == 0)
		printf("%s", nb_argumentos[x]);
	else
	{
		y = -1;
		while (nb_argumentos[x][++y])
		{
			if (nb_argumentos[x][y] != '$')
				printf("%c", nb_argumentos[x][y]);
			else if (nb_argumentos[x][y] == '$')
			{
				ft_imprimir_variable(nb_argumentos, x, y, env);
				break ;
			}
		}
	}
}

static int	ft_comprobar_saltos(char **nb_argumentos, int x, char **env)
{
	int	z;
	int	new_line;

	new_line = 1;
	while (nb_argumentos[++x])
	{
		z = ft_n(nb_argumentos[x]);
		if (ft_strncmp(nb_argumentos[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
		{
			ft_imprimir(nb_argumentos, x, env);
			if (nb_argumentos[x + 1])
				printf(" ");
		}
	}
	return (new_line);
}

void	ft_echo(char **env) // *! MODIFICAR para comillas simples
{
	int		x;
	int		new_line;
	char	**nb_argumentos; // ? Provisional, esto lo da la estructura

	x = -1;
	new_line = 1;
	nb_argumentos = ft_split("-nnnnnn t -nnnnn$TERM", ' ');
	if (nb_argumentos)
	{
		new_line = ft_comprobar_saltos(nb_argumentos, x, env);
		x = 0;
		while (nb_argumentos[x])
			free(nb_argumentos[x++]);
		free(nb_argumentos);
	}
	if (new_line == 0)
		printf("%%");
	printf("\n");
}
