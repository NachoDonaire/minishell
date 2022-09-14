/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:07:33 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 11:16:11 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_print_quotation_d(char *argument)
{
	int	x;
	int	z;

	x = 0;
	z = ft_strlen(argument) - 1;
	while (argument[x])
	{
		if (argument[x] == 39)
		{
			if (argument[x + 1] == 34 && argument[z] != 34)
				return (0);
			return (1);
		}
		x++;
	}
	return (1);
}

int	ft_print_quotation_s(char *argument)
{
	int	x;
	int	z;

	x = 0;
	z = ft_strlen(argument) - 1;
	while (argument[x])
	{
		if (argument[x] == 34)
		{
			if (argument[x + 1] == 39 && argument[z] != 39)
				return (0);
			return (1);
		}
		x++;
	}
	return (1);
}

void	ft_print_q(int *c, t_general_data *gen_data, int x, int p)
{
	int	z;

	z = ft_strlen(gen_data->blt[p].args[x]) - 1;
	if (ft_print_quotation_s(gen_data->blt[p].args[x]) == 0
		&& gen_data->blt->args[x][z] != 34)
	{
		c[0] = 1;
		ft_print_fdout(gen_data, '\'');
	}
	if (ft_print_quotation_d(gen_data->blt[p].args[x]) == 0
		&& gen_data->blt[p].args[x][z] != 39)
	{
		c[1] = 1;
		ft_print_fdout(gen_data, '\"');
	}
	ft_print(x, z, gen_data, p);
	if (gen_data->blt[p].args[x + 1])
		ft_print_fdout(gen_data, ' ');
}

int	ft_check_nl2(t_general_data *gen_data, int position, int *quotation)
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
			ft_print_q(quotation, gen_data, x, position);
		x++;
	}
	return (new_line);
}

int	ft_check_nl(t_general_data *gen_data, int position)
{
	int	new_line;
	int	quotation[2];
	int	a;

	a = 0;
	quotation[0] = 0;
	quotation[1] = 0;
	new_line = ft_check_nl2(gen_data, position, quotation);
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
