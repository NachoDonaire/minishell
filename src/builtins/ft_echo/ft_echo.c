/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 12:20:58 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_quotation(char **s, int x, int z, int nb_argument)
{
	if (s[x][0] == '\"' && s[x][z] == '\"' && s[x + 1] && s[0][0] != 39 &&
		s[0][0] == 34 && s[nb_argument][ft_strlen(s[nb_argument]) - 1] != 34)
		printf("\""); //change to write
}

static void	ft_print(int x, int z, t_general_data *gen_data, int position)
{
	int		y;
	char	**s;

	s = gen_data->blt[position].args;
	y = 0;
	if (ft_dollar(s[x]) == 0)
		printf("%s", s[x]); //change to write
	else
	{
		ft_quotation(s, x, z, gen_data->blt[position].nb_arguments);
		while (s[x][y])
		{
			if (s[x][y] != '$' && s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]); //change to write
			else if (s[x][y] == '$' && ft_c_s(s[x]) == 0 && ft_c_d(s[x]) == 0)
			{
				ft_print_variable(s, x, y, gen_data->env);
				break ;
			}
			else if (s[x][y] != 39 && s[x][y] != 34)
				printf("%c", s[x][y]); //change to write
			y++;
		}
		ft_quotation(s, x, z, gen_data->blt[position].nb_arguments);
	}
}

static	void	ft_print_q(int *c, t_general_data *gen_data, int x, int p)
{
	int	z;

z = ft_strlen(gen_data->blt[p].args[x]) - 1;
	if (ft_print_quotation_s(gen_data->blt[p].args[x]) == 0
		&& gen_data->blt->args[x][z] != 34)
	{
		c[0] = 1;
		printf("'"); //change to write
	}
	if (ft_print_quotation_d(gen_data->blt[p].args[x]) == 0
		&& gen_data->blt[p].args[x][z] != 39)
	{
		c[1] = 1;
		printf("\""); //change to write
	}
	ft_print(x, z, gen_data, p);
	if (gen_data->blt[p].args[x + 1])
		printf(" "); //change to write
}

static int	ft_check_nl(t_general_data *gen_data, int position)
{
	int	z;
	int	x;
	int	new_line;
	int	quotation[2];

	x = 0;
	quotation[0] = 0;
	quotation[1] = 0;
	new_line = 1;
	while (gen_data->blt[position].args[x])
	{
		z = ft_n(gen_data->blt[position].args[x]);
		if (ft_strncmp(gen_data->blt[position].args[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
			ft_print_q(quotation, gen_data, x, position);
		x++;
	}
	if (quotation[0] == 1)
		printf("'"); //change to write
	if (quotation[1] == 1)
		printf("\""); //change to write
	return (new_line);
}

void	ft_echo(t_general_data *gen_data, int p)
{
	int		new_line;

	new_line = 1;
	gen_data->blt[p].nb_arguments = ft_nb_arguments(gen_data->blt[p].args);
	if (gen_data->blt[p].args[0])
		new_line = ft_check_nl(gen_data, p);
	if (new_line == 1)
		printf("\n"); //change to write
	ft_change_good_status(gen_data->env);
}
