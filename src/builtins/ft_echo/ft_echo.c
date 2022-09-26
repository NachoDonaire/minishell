/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:31 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 10:33:59 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_print_v(char **arg, int x, int y, t_general_data *gen_data)
{
	char	*copy;
	char	*tmp;
	int		z;
	int		a;

	a = 0;
	z = -1;
	copy = ft_substr(arg[x], y + 1, ft_strlen(arg[x]));
	tmp = ft_strjoin(copy, "=");
	free(copy);
	while (gen_data->env[++z])
	{
		y = ft_strlen(tmp);
		if (ft_strncmp(gen_data->env[z], tmp, y) == 0)
		{
			free(tmp);
			copy = ft_strchr(gen_data->env[z], '=');
			tmp = ft_substr(copy, 1, ft_strlen(copy));
			while (gen_data->blt->fd_out[a])
				ft_putstr_fd(tmp, gen_data->blt->fd_out[a++]);
			free(tmp);
			break ;
		}
	}
}

int	ft_check_nl(t_general_data *gen_data, int position)
{
	int	x;
	int	z;
	int	new_line;

	x = 0;
	new_line = 1;
	while (gen_data->blt[position].args[x])
	{
		z = ft_n(gen_data->blt[position].args[x]);
		if (ft_strncmp(gen_data->blt[position].args[x], "-n", 2) == 0 && z == 0)
			new_line = 0;
		else
		{
			ft_print(x, gen_data, position);
			if (gen_data->blt[position].args[x + 1])
				ft_print_fdout(gen_data, ' ');
		}
		x++;
	}
	return (new_line);
}

void	ft_print(int x, t_general_data *gen_data, int position)
{
	int		a;
	char	**s;
	int		y;

	a = 0;
	s = gen_data->blt[position].args;
	if (ft_dollar(s[x]) == 0)
		ft_print_fdout2(gen_data, s[x]);
	else
	{
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
