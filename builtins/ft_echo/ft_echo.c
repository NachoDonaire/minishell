/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:10:10 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 17:36:26 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_quotation(char **s, int x, int z)
{
	if (s[x][0] == '\"' && s[x][z] == '\"' && s[x + 1] && s[0][0] != 39 &&
		s[0][0] == 34 && s[2][ft_strlen(s[2]) - 1] != 34) // 2 is the number of arguments
		printf("\"");
}

static void	ft_print(char **s, int x, char **env, int z)
{
	int		y;

	y = -1;
	if (ft_dollar(s[x]) == 0)
		printf("%s", s[x]);
	else
	{
		ft_quotation(s, x, z);
		while (s[x][++y])
		{
			if (s[x][y] != '$' && s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]);
			else if (s[x][y] == '$' && ft_c_s(s[x]) == 0 && ft_c_d(s[x]) == 0)
			{
				ft_print_variable(s, x, y, env);
				break ;
			}
			else if (s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]);
		}
		ft_quotation(s, x, z);
	}
}

static	void	ft_print_quotation(char **array, int x, char **e, int *c)
{
	int	z;

	z = ft_strlen(array[x]) - 1;
	if (ft_print_quotation_s(array[x]) == 0 && array[x][z] != 34)
	{
		c[0] = 1;
		printf("'");
	}
	if (ft_print_quotation_d(array[x]) == 0 && array[x][z] != 39)
	{
		c[1] = 1;
		printf("\"");
	}
	ft_print(array, x, e, z);
	if (array[x + 1])
		printf(" ");
}

static int	ft_check_nl(char **nb_arguments, int x, char **env)
{
	int	z;
	int	new_line;
	int	quotation[2];

	quotation[0] = 0;//simple
	quotation[1] = 0;//doble
	new_line = 1;
	while (nb_arguments[x])
	{
		z = ft_n(nb_arguments[x]);
		if (ft_strncmp(nb_arguments[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
			ft_print_quotation(nb_arguments, x, env, quotation);
		x++;
	}
	if (quotation[0] == 1)
		printf("'");
	if (quotation[1] == 1)
		printf("\"");
	return (new_line);
}

void	ft_echo(char **env)
{
	int		x;
	int		new_line;
	char	**nb_arguments; // ? Provisional, this is given by the structure

	x = 0;
	new_line = 1;
	nb_arguments = ft_split("\"\"-nnnnnn t -nnnnn$TERM\"\"", ' ');
	if (nb_arguments)
	{
		new_line = ft_check_nl(nb_arguments, x, env);
		x = 0;
		while (nb_arguments[x])
			free(nb_arguments[x++]);
		free(nb_arguments);
	}
	if (new_line == 1)
		printf("\n");
}
