/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_status.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:43:23 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 18:34:35 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_change_bad_status(char **env, t_general_data *gen_data)
{
	int	x;

	gen_data->good_status = 127;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("?=", ft_itoa(gen_data->good_status));
		}
		x++;
	}
}

void	ft_change_permission_status(char **env, t_general_data *gen_data)
{
	int	x;

	gen_data->good_status = 1;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("?=", ft_itoa(gen_data->good_status));
		}
		x++;
	}
}

void	ft_change_good_status(char **env, t_general_data *gen_data)
{
	int	x;

	gen_data->good_status = 0;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			env[x] = ft_strjoin("?=", ft_itoa(gen_data->good_status));
		}
		x++;
	}
}
