/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/19 20:18:03 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_fdout(t_general_data *gen_data, char s)
{
	int	a;

	a = 0;
	while (gen_data->blt->fd_out[a])
		ft_putchar_fd(s, gen_data->blt->fd_out[a++]);
}

void	ft_print2(int x, t_general_data *gen_data, int position)
{
	int		y;
	char	**s;

	s = gen_data->blt[position].args;
	y = 0;
	while (s[x][y])
	{
		if (s[x][y] != '$')
			ft_print_fdout(gen_data, s[x][y]);
		else if (s[x][y] == '$')
		{
			ft_print_v(s, x, y, gen_data);
			break ;
		}
		y++;
	}
}

void	ft_print(int x, t_general_data *gen_data, int position)
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
		ft_print2(x, gen_data, position);
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
