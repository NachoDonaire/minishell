/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comillas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:04 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/29 12:26:25 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*en el propio comando*/
int	check_cmllas(char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if ((s[i] == '"' || s[i] == 39) && lens(s) > 1)
	{
		while (s[i] != ' ' && s[i])
		{
			i++;
			if (s[i] == '"' || s[i] == 39)
				return (1);
		}
	}
	return (0);
}

char	*gest_cmllas(char *s)
{
	char	*sol;
	int		i;
	int		y;

	i = 0;
	y = 0;
	sol = malloc(sizeof(char) * lens(s));
	while (s[i] != '"' && s[i] != 39)
		i++;
	i++;
	while (s[i] != '"' && s[i] != 39)
	{
		sol[y++] = s[i++];
	}
	sol[y] = '\0';
	return (sol);
}
/*mas alla del comando*/

char	**dr_comillas(char *s)
{
	int		i;
	int		y;
	int		z;
	int		spaces;
	int		w;
	int		cmllas;
	int		aviso;
	char	**wallace;

	spaces = 0;
	w = 0;
	aviso = 0;
	i = 0;
	cmllas = 0;
	y = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			y++;
		i++;
	}
	wallace = malloc(sizeof(char *) * (y + 1));
	i = 0;
	while (s[i])
	{
		if (s[i] == '"')
			cmllas++;
		i++;
	}
	i = 0;
	y = 0;

	while (s[i])
	{
		while (s[i])
		{
			while ((s[i] == ' ' || s[i] == '>') && s[i])
			{
				spaces++;
				i++;
			}
			if (s[i] == '"' || s[i] == '\0')
				break ;
			aviso++;
			i++;
		}

		if (aviso != 0)
		{
			wallace[z] = malloc(sizeof(char) * (i + 1));
			i = i - aviso - spaces;
			while (s[i] == ' ' || s[i] == '>')
				i++;
			while (y < aviso || s[i] == ' ' || s[i] == '>')
			{
				if ((s[i] == ' ' && i != 0) || s[i] == '>' )
				{
					while (s[i] == ' ' || s[i] == '>')
						i++;
					if (s[i] == '"' || s[i] == '\0')
						break ;
					else
					{
						wallace[z][w] = '\0';
						z++;
						wallace[z] = malloc(sizeof(char ) * (aviso - y + 1));
						w = 0;
					}
				}
				y++;
				wallace[z][w++] = s[i++];
			}
			wallace[z][w] = '\0';
			z++;
		}
		else if (aviso == 0)
		{
			i++;
			while (s[i])
			{
				if (s[i] == '"')
					break ;
				i++;
				y++;
			}
			wallace[z] = malloc(sizeof(char ) * (y + 1));
			i = i - y;
			while (s[i])
			{
				if (s[i] == '"')
				{
					i++;
					break ;
				}
				wallace[z][w++] = s[i++];
			}
			wallace[z][w] = '\0';
			z++;
			y = 0;
		}
		while (s[i] == ' ')
			i++;
		aviso = 0;
		w = 0;
		y = 0;
		spaces = 0;
		cmllas--;
	}
	wallace[z] = NULL;
	return (wallace);
}
