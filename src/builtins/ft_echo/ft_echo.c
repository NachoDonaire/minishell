/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 15:27:09 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_quotation(t_general_data *gen_data, int x, int z, int position)
{
	int	a;

	a = 0;
	if (gen_data->blt[position].args[x][0] == '\"' && gen_data->blt[position].args[x][z] == '\"' && gen_data->blt[position].args[x + 1] && gen_data->blt[position].args[0][0] != 39 &&
		gen_data->blt[position].args[0][0] == 34 && gen_data->blt[position].args[gen_data->blt[position].nb_arguments][ft_strlen(gen_data->blt[position].args[gen_data->blt[position].nb_arguments]) - 1] != 34)
	{
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\"', gen_data->blt->fd_out[a++]);
	}
}

static void	ft_print(int x, int z, t_general_data *gen_data, int position)
{
	int		y;
	int		a;
	char	**s;

	a = 0;
	s = gen_data->blt[position].args;
	y = 0;
	if (ft_dollar(s[x]) == 0)
	{
		while (gen_data->blt->fd_out[a])
			ft_putstr_fd(s[x], gen_data->blt->fd_out[a++]);
	}
	else
	{
		ft_quotation(gen_data, x, z, position);
		while (s[x][y])
		{
			a = 0;
			if (s[x][y] != '$' && s[x][y] != 39 && s[x][y] != 34)
			{
				while (gen_data->blt->fd_out[a])
					ft_putchar_fd(s[x][y], gen_data->blt->fd_out[a++]);
			}
			else if (s[x][y] == '$' && ft_c_s(s[x]) == 0 && ft_c_d(s[x]) == 0)
			{
				ft_print_variable(s, x, y, gen_data);
				break ;
			}
			else if (s[x][y] != 39 && s[x][y] != 34)
			{
				while (gen_data->blt->fd_out[a])
					ft_putchar_fd(s[x][y], gen_data->blt->fd_out[a++]);
			}
			y++;
		}
		ft_quotation(gen_data, x, z, position);
	}
}

static	void	ft_print_q(int *c, t_general_data *gen_data, int x, int p)
{
	int	z;
	int	a;

	a = 0;
	z = ft_strlen(gen_data->blt[p].args[x]) - 1;
	if (ft_print_quotation_s(gen_data->blt[p].args[x]) == 0
		&& gen_data->blt->args[x][z] != 34)
	{
		c[0] = 1;
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\'', gen_data->blt->fd_out[a++]);
		a = 0;
	}
	if (ft_print_quotation_d(gen_data->blt[p].args[x]) == 0
		&& gen_data->blt[p].args[x][z] != 39)
	{
		c[1] = 1;
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\"', gen_data->blt->fd_out[a++]);
		a = 0;
	}
	ft_print(x, z, gen_data, p);
	if (gen_data->blt[p].args[x + 1])
	{
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd(' ', gen_data->blt->fd_out[a++]);
		a = 0;
	}
}

static int	ft_check_nl(t_general_data *gen_data, int position)
{
	int	z;
	int	x;
	int	new_line;
	int	quotation[2];
	int	a;

	x = 0;
	a = 0;
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
	{
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\'', gen_data->blt->fd_out[a++]);
	}
	if (quotation[1] == 1)
	{
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\"', gen_data->blt->fd_out[a++]);
	}
	return (new_line);
}

void	ft_echo(t_general_data *gen_data, int p)
{
	int		new_line;
	int		a;

	a = 0;
	new_line = 1;
	gen_data->blt[p].nb_arguments = ft_nb_arguments(gen_data->blt[p].args);
	if (gen_data->blt[p].args[0])
		new_line = ft_check_nl(gen_data, p);
	if (new_line == 1)
	{
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\n', gen_data->blt->fd_out[a++]);
	}
	ft_change_good_status(gen_data->env, gen_data);
}
