/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:51 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 14:37:51 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

static void	ft_print_quote(char *env, t_general_data *gen_data)
{
	int	x;
	int	y;

	x = -1;
	while (env[++x])
	{
		y = 0;
		while (gen_data->blt->fd_out[y])
			ft_putchar_fd(env[x], gen_data->blt->fd_out[y++]);
		if (env[x] == '=')
		{
			y = 0;
			while (gen_data->blt->fd_out[y])
				ft_putstr_fd("\"", gen_data->blt->fd_out[y++]);
		}
	}
	if (ft_equal(env) == 0)
	{
		y = 0;
		while (gen_data->blt->fd_out[y])
			ft_putstr_fd("=\"", gen_data->blt->fd_out[y++]);
	}
	y = 0;
	while (gen_data->blt->fd_out[y])
		ft_putstr_fd("\"", gen_data->blt->fd_out[y++]);
}

static void	ft_order(char **copy)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	while (copy[x + 1])
	{
		y = x + 1;
		while (copy[y])
		{
			if (ft_strcmp(copy[x], copy[y]) > 0)
			{
				tmp = copy[x];
				copy[x] = copy[y];
				copy[y] = tmp;
			}
			y++;
		}
		x++;
	}
}

static void	ft_print_export(t_general_data *gen_data)
{
	int		x;
	int		y;
	char	**copy;

	x = -1;
	copy = malloc(1024);
	while (gen_data->env[++x])
		copy[x] = ft_substr(gen_data->env[x], 0, ft_strlen(gen_data->env[x]));
	copy[x] = NULL;
	ft_order(copy);
	x = -1;
	while (copy[++x])
	{
		y = 0;
		if (ft_strncmp(copy[x], "?=", 2) != 0)
		{
			while (gen_data->blt->fd_out[y])
				ft_putstr_fd("declare -x ", gen_data->blt->fd_out[y++]);
			y = 0;
			ft_print_quote(copy[x], gen_data);
			while (gen_data->blt->fd_out[y])
				ft_putstr_fd("\n", gen_data->blt->fd_out[y++]);
		}
	}
	ft_free_arg(copy);
}

static void	ft_export_arguments(t_general_data *gen_data, int position)
{
	char	*variable;
	char	*value;
	int		x;

	x = 0;
	while (gen_data->blt[position].args[++x])
	{
		variable = ft_variables(gen_data->blt[position].args[x]);
		value = ft_value(gen_data->blt[position].args[x]);
		if (ft_find_variable(variable, gen_data->env) == 0)
			ft_create_variable(variable, value, gen_data->env);
		else
			ft_replace_v2(variable, value, gen_data);
		if (value)
		{
			free(value);
			free(variable);
		}
	}
}

void	ft_export(t_general_data *gen_data, int position)
{
	if (gen_data->blt[position].args[1])
		ft_export_arguments(gen_data, position);
	else
		ft_print_export(gen_data);
	ft_change_good_status(gen_data->env, gen_data);
}
