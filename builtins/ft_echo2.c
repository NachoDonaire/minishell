/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salustianosalamanca <salustianosalamanc    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:44:56 by salustianos       #+#    #+#             */
/*   Updated: 2022/08/04 12:47:18 by salustianos      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_n(char *argumento)
{
	int	x;

	x = 1;
	while (argumento[x])
	{
		if (argumento[x] != 'n')
			return (1);
		x++;
	}
	return (0);
}

int	ft_dollar(char *argumento)
{
	int	x;

	x = 1;
	while (argumento[x])
	{
		if (argumento[x] != '$')
			return (1);
		x++;
	}
	return (0);
}

int	ft_comillas_simples(char *argumento)
{
	int	x;

	x = 0;
	while (argumento[x])
	{
		if (argumento[x] == 39)
		{
			while (argumento[x])
			{
				if (argumento[x] == 34)
					return (0);
				x++;
			}
			return (1);
		}
		x++;
	}
	return (0);
}

int	ft_comillas_dobles(char *argumento)
{
	int	x;

	x = 0;
	while (argumento[x])
	{
		if (argumento[x] == 34)
		{
			while (argumento[x])
			{
				if (argumento[x] == 39)
					return (1);
				x++;
			}
			return (0);
		}
		x++;
	}
	return (1);
}
