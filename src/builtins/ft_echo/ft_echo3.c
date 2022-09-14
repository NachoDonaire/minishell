/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:45 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 11:07:51 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_print_quotation_s2(char *argument)
{
	int	x;

	x = ft_strlen(argument);
	while (x > 0)
	{
		if (argument[x] == 39)
			return (0);
		x--;
	}
	return (1);
}

int	ft_print_quotation_d2(char *argument)
{
	int	x;

	x = ft_strlen(argument);
	while (x > 0)
	{
		if (argument[x] == 34)
			return (0);
		x--;
	}
	return (1);
}

void	ft_print_v2(int y, t_general_data *gen_data, char *copy, char *tmp)
{
	int	z;
	int	a;

	a = 0;
	z = -1;
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

void	ft_print_v(char **arg, int x, int y, t_general_data *gen_data)
{
	char	*copy;
	char	*tmp;
	int		a;

	a = 0;
	copy = ft_substr(arg[x], y + 1, ft_strlen(arg[x]));
	while (ft_print_quotation_d2(copy) == 0)
		copy[ft_strlen(copy) - 1] = '\0';
	while (ft_print_quotation_s2(copy) == 0)
		copy[ft_strlen(copy) - 1] = '\0';
	tmp = ft_strjoin(copy, "=");
	free(copy);
	ft_print_v2(y, gen_data, copy, tmp);
}
