/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 11:16:23 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_quotation(t_general_data *gen_data, int x, int z, int position)
{
	int		a;
	char	b;
	char	*s;
	char	*s2;

	b = gen_data->blt[position].args[0][0];
	s = gen_data->blt[position].args[gen_data->blt[position].nb_arguments];
	s2 = gen_data->blt[position].args[x];
	a = 0;
	if (s2[0] == '\"' && s2[z] == '\"' && gen_data->blt[position].args[x + 1]
		&& b != 39 && b == 34 && s[ft_strlen(s) - 1] != 34)
	{
		while (gen_data->blt->fd_out[a])
			ft_putchar_fd('\"', gen_data->blt->fd_out[a++]);
	}
}

void	ft_print_fdout(t_general_data *gen_data, char s)
{
	int	a;

	a = 0;
	while (gen_data->blt->fd_out[a])
		ft_putchar_fd(s, gen_data->blt->fd_out[a++]);
}

void	ft_print2(int x, int z, t_general_data *gen_data, int position)
{
	int		y;
	char	**s;

	s = gen_data->blt[position].args;
	y = 0;
	ft_quotation(gen_data, x, z, position);
	while (s[x][y])
	{
		if (s[x][y] != '$' && s[x][y] != 39 && s[x][y] != 34)
			ft_print_fdout(gen_data, s[x][y]);
		else if (s[x][y] == '$' && ft_c_s(s[x]) == 0 && ft_c_d(s[x]) == 0)
		{
			ft_print_v(s, x, y, gen_data);
			break ;
		}
		else if (s[x][y] != 39 && s[x][y] != 34)
			ft_print_fdout(gen_data, s[x][y]);
		y++;
	}
	ft_quotation(gen_data, x, z, position);
}

void	ft_print(int x, int z, t_general_data *gen_data, int position)
{
	int		a;
	char	**s;

	a = 0;
	s = gen_data->blt[position].args;
	if (ft_dollar(s[x]) == 0)
	{
		while (gen_data->blt->fd_out[a])
			ft_putstr_fd(s[x], gen_data->blt->fd_out[a++]);
	}
	else
		ft_print2(x, z, gen_data, position);
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
