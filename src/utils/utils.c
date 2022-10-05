/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:54:59 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/04 19:54:08 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "../../includes/minishell.h"

int	lens(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	checkin_path(char *s, char *find)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == find[y])
		{
			i++;
			y++;
			if (find[y] == '\0')
				return (1);
		}
		y = 0;
		i++;
	}
	return (0);
}

char	*find_path(char *const env[])
{
	int		i;
	int		check;

	i = 0;
	check = checkin_path(env[i], "PATH");
	while (check == 0)
	{
		i++;
		check = checkin_path(env[i], "PATH");
	}
	return (env[i]);
}

char	*pseudo_join(char *path, char *com)
{
	char	*sol;
	int		i;
	int		y;

	y = 0;
	i = 0;
	if (!path)
		return (com);
	sol = malloc(sizeof(char) * (lens(path) + lens(com) + 2));
	while (path[i])
	{
		sol[i] = path[i];
		i++;
	}
	sol[i++] = '/';
	while (com[y])
	{
		sol[i++] = com[y++];
	}
	sol[i] = '\0';
	return (sol);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
