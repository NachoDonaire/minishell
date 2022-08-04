/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:10 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/04 15:18:08 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_imprimir(char **s, int x, char **env, int z)
{
	int		y;
	int		a;
	int		b;
	int		c;

	c = ft_strlen(s[2]) - 1;
	if (ft_dollar(s[x]) == 0)
		printf("%s", s[x]);
	else
	{
		if (s[x][0] == '\"' && s[x][z] == '\"' && s[x + 1] && s[0][0] != 39 &&
			s[0][0] == 34 && s[2][c] != 34) // El 2 es el nº de argumentos
			printf("\"");
		y = -1;
		while (s[x][++y])
		{
			a = ft_comillas_simples(s[x]);
			b = ft_comillas_dobles(s[x]);
			if (s[x][y] != '$' && s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]);
			else if (s[x][y] == '$' && a == 0 && b == 0)
			{
				ft_imprimir_variable(s, x, y, env);
				break ;
			}
			else if (s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]);
		}
		if (s[x][0] == '\"' && s[x][z] == '\"' && s[x + 1] && s[0][0] != 39 &&
			s[0][0] == 34 && s[2][c] != 34) // El 2 es el nº de argumentos
			printf("\"");
	}
}

static	void	ft_imprimir_comillas(char **array, int x, char **e, int *c)
{
	int	z;

	z = ft_strlen(array[x]) - 1;
	if (ft_imprimir_comilla_simple(array[x]) == 0 && array[x][z] != 34)
	{
		c[0] = 1;
		printf("'");
	}
	if (ft_imprimir_comilla_doble(array[x]) == 0 && array[x][z] != 39)
	{
		c[1] = 1;
		printf("\"");
	}
	ft_imprimir(array, x, e, z);
	if (array[x + 1])
		printf(" ");
}

static int	ft_comprobar_saltos(char **nb_argumentos, int x, char **env)
{
	int	z;
	int	new_line;
	int	comillas[2];

	comillas[0] = 0;//simple
	comillas[1] = 0;//doble
	new_line = 1;
	while (nb_argumentos[x])
	{
		z = ft_n(nb_argumentos[x]);
		if (ft_strncmp(nb_argumentos[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
			ft_imprimir_comillas(nb_argumentos, x, env, comillas);
		x++;
	}
	if (comillas[0] == 1)
		printf("'");
	if (comillas[1] == 1)
		printf("\"");
	return (new_line);
}

void	ft_echo(char **env) // *! MODIFICAR para comillas simples
{
	int		x;
	int		new_line;
	char	**nb_argumentos; // ? Provisional, esto lo da la estructura

	x = 0;
	new_line = 1;
	nb_argumentos = ft_split("\"-nnnnnn \"t\" -nnnnn$TERM\"", ' ');
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
