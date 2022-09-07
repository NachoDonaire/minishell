/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 15:06:38 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_change_bad_status(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_substr("?=127", 0, 6);
		}
		x++;
	}
}

void	ft_change_permission_status(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_substr("?=1", 0, 4);
		}
		x++;
	}
}

void	ft_change_good_status(char **env)
{
	int	x;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_substr("?=0", 0, 4);
		}
		x++;
	}
}
