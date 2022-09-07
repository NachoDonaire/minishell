/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:08:11 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 18:10:36 by sasalama         ###   ########.fr       */
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
