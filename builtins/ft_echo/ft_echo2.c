/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:47:02 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/09 17:14:27 by sasalama         ###   ########.fr       */
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

	x = 1;
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
					return (1);
				x++;
			}
			return (0);
		}
		x++;
	}
	return (1);
}
