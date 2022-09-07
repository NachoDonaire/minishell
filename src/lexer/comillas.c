/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comillas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:04 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:23:05 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*en el propio comando*/
int	check_cmllas(char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (s[i] == '"' && lens(s) > 1)
	{
		while (s[i] != ' ' && s[i])
		{
			i++;
			if (s[i] == '"')
				return (1);
			/*if ((s[i] == '\0' || s[i] == ' ') && s[i - 1] == '"')
			   return (1);*/
		}
	}
	return (0);
}

char	*gest_cmllas(char *s)
{
	char	*sol;
	int		i;
	int		y;

	i = 1;
	y = 0;
	sol = malloc(sizeof(char) * lens(s));
	while (s[i] != '"')
	{
		sol[y++] = s[i++];
	}
	sol[y] = '\0';
	return (sol);
}
/*mas alla del comando*/
