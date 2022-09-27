/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:39 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 12:47:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_n(char *argument)
{
	int	x;

	x = 1;
	while (argument[x])
	{
		if (argument[x] != 'n')
			return (1);
		x++;
	}
	return (0);
}

int	ft_dollar(char *argument)
{
	int	x;

	x = 0;
	while (argument[x])
	{
		if (argument[x] != '$')
			return (1);
		x++;
	}
	return (0);
}

int	ft_nb_arguments(char **nb_arguments)
{
	int	x;

	x = 0;
	while (nb_arguments[x])
		x++;
	return (x);
}

void	ft_print_fdout(t_general_data *gen_data, char s)
{
	int	a;

	a = 0;
	while (gen_data->blt->fd_out[a])
		ft_putchar_fd(s, gen_data->blt->fd_out[a++]);
}

void	ft_print_fdout2(t_general_data *gen_data, char *s)
{
	int	a;

	a = 0;
	while (gen_data->blt->fd_out[a])
		ft_putstr_fd(s, gen_data->blt->fd_out[a++]);
}
