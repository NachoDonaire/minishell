/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:57:39 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/06 12:01:31 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

int	ft_c_s(char *argument)
{
	int	x;

	x = 0;
	while (argument[x])
	{
		if (argument[x] == 39)
		{
			while (argument[x])
			{
				if (argument[x] == 34)
					return (0);
				x++;
			}
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_c_d(char *argument)
{
	int	x;

	x = 0;
	while (argument[x])
	{
		if (argument[x] == 34)
		{
			while (argument[x])
			{
				if (argument[x] == 39)
					return (0);
				x++;
			}
			return (1);
		}
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
