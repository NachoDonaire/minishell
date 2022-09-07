/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 12:16:27 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_quotation(char **s, int x, int z, int nb_argument)
{
	if (s[x][0] == '\"' && s[x][z] == '\"' && s[x + 1] && s[0][0] != 39 &&
		s[0][0] == 34 && s[nb_argument][ft_strlen(s[nb_argument]) - 1] != 34)
		printf("\"");
}

static void	ft_print(int x, int z, t_general_data *gen_data)
{
	int		y;
	char	**s;

	s = gen_data->blt->args;
	y = 0;
	if (ft_dollar(s[x]) == 0)
		printf("%s", s[x]);
	else
	{
		ft_quotation(s, x, z, gen_data->blt->nb_arguments);
		while (s[x][y])
		{
			if (s[x][y] != '$' && s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]);
			else if (s[x][y] == '$' && ft_c_s(s[x]) == 0 && ft_c_d(s[x]) == 0)
			{
				ft_print_variable(s, x, y, gen_data->env);
				break ;
			}
			else if (s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]);
			y++;
		}
		ft_quotation(s, x, z, gen_data->blt->nb_arguments);
	}
}

static	void	ft_print_quotation(int *c, t_general_data *gen_data, int x)
{
	int	z;

z = ft_strlen(gen_data->blt->args[x]) - 1;
	if (ft_print_quotation_s(gen_data->blt->args[x]) == 0 && gen_data->blt->args[x][z] != 34)
	{
		c[0] = 1;
		printf("'");
	}
	if (ft_print_quotation_d(gen_data->blt->args[x]) == 0 && gen_data->blt->args[x][z] != 39)
	{
		c[1] = 1;
		printf("\"");
	}
	ft_print(x, z, gen_data);
	if (gen_data->blt->args[x + 1])
		printf(" ");
}

static int	ft_check_nl(t_general_data *gen_data)
{
	int	z;
	int	x;
	int	new_line;
	int	quotation[2];

	x = 0;
	quotation[0] = 0;
	quotation[1] = 0;
	new_line = 1;
	while (gen_data->blt->args[x])
	{
		z = ft_n(gen_data->blt->args[x]);
		if (ft_strncmp(gen_data->blt->args[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
			ft_print_quotation(quotation, gen_data, x);
		x++;
	}
	if (quotation[0] == 1)
		printf("'");
	if (quotation[1] == 1)
		printf("\"");
	return (new_line);
}

void	ft_echo(t_general_data *gen_data)
{
	int		new_line;

	new_line = 1;
	gen_data->blt->nb_arguments = ft_nb_arguments(gen_data->blt->args);
	if (gen_data->blt->args[0])
		new_line = ft_check_nl(gen_data);
	if (new_line == 1)
		printf("\n");
	ft_change_good_status(gen_data->env);
}
