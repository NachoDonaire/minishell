/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:08:11 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/19 18:56:13 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	finder(char *s, char *find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] == find[y])
		{
			y++;
			i++;
			if (find[y] == '\0')
				return (1);
		}
		y = 0;
		i++;
	}
	return (0);
}

int	extreme_finder(char *s, char *find)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (!s)
		return (0);
	while (s[i] == ' ')
		i++;
	while (s[i] == find[y])
	{
		y++;
		i++;
		if (find[y] == '\0')
			return (1);
	}
	return (0);
}

void	ft_change_bad_status(char **env, t_general_data *gen_data)
{
	int		x;
	char	*y;

	gen_data->good_status = 127;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			y = ft_itoa(gen_data->good_status);
			env[x] = ft_strjoin("?=", y);
			free(y);
		}
		x++;
	}
}

void	ft_change_permission_status(char **env, t_general_data *gen_data)
{
	int		x;
	char	*y;

	gen_data->good_status = 1;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			y = ft_itoa(gen_data->good_status);
			env[x] = ft_strjoin("?=", y);
			free(y);
		}
		x++;
	}
}

void	ft_change_good_status(char **env, t_general_data *gen_data)
{
	int		x;
	char	*y;

	gen_data->good_status = 0;
	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "?=", 2) == 0)
		{
			free(env[x]);
			y = ft_itoa(gen_data->good_status);
			env[x] = ft_strjoin("?=", y);
			free(y);
		}
		x++;
	}
}
