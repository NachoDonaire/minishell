/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/05 10:03:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_quotation(char **s, int x, int z, int nb_argument)
{
	if (s[x][0] == '\"' && s[x][z] == '\"' && s[x + 1] && s[0][0] != 39 &&
		s[0][0] == 34 && s[nb_argument][ft_strlen(s[nb_argument]) - 1] != 34)
		printf("\"");
}

static void	ft_print(char **s, int x, char **env, int z, int nb_argument)
{
	int		y;

	y = 0;
	if (ft_dollar(s[x]) == 0)
		printf("%s", s[x]);
	else
	{
		ft_quotation(s, x, z, nb_argument);
		while (s[x][y])
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
			y++;
		}
		ft_quotation(s, x, z, nb_argument);
	}
}

static	void	ft_print_quotation(char **array, int x, char **e, int *c, int nb_argument)
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
	ft_print(array, x, e, z, nb_argument);
	if (array[x + 1])
		printf(" ");
}

static int	ft_check_nl(char **nb_arguments, int x, char **env, int nb_argument)
{
	int	z;
	int	new_line;
	int	quotation[2];

	quotation[0] = 0;//* simple
	quotation[1] = 0;//* doble
	new_line = 1;
	while (nb_arguments[x])
	{
		z = ft_n(nb_arguments[x]);
		if (ft_strncmp(nb_arguments[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
			ft_print_quotation(nb_arguments, x, env, quotation, nb_argument);
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
	int		y;
	int		new_line;
	char	**nb_arguments; // ? Provisional, this is given by the structure

	x = 0;
	new_line = 1;
	nb_arguments = ft_split("\"hola $TERM \"", ' ');
	y = ft_nb_arguments(nb_arguments);
	if (nb_arguments)
	{
		new_line = ft_check_nl(nb_arguments, x, env, y);
		ft_free_arg(nb_arguments);
	}
	if (new_line == 1)
		printf("\n");
	ft_change_good_status(env);
}
