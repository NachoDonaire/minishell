/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dr_comillas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:00:01 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/16 20:33:51 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**fill_wallace(char **wallace, char *s)
{
	int	i;
	int	y;
	int	z;

	z = 0;
	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == ' ' )
			y++;
		if (s[i] == '"' || s[i] == 39)
		{
			z++;
		}
		i++;
	}
	wallace = malloc(sizeof(char *) * (y + 2 + (z / 2)));
	return (wallace);
}

int	memory_for_wallace(char *s, char **wallace, int i, int w, int y)
{
	if (s[i] == 39)
	{
		i++;
		while (s[i] != 39 && s[i])
		{
			y++;
			i++;
		}
		i++;
		if (s[i] == 39)
			memory_for_wallace(s, wallace, i, w, y);
	}
	else if (s[i] == '"')
	{
		i++;
		while (s[i] != '"' && s[i])
		{
			y++;
			i++;
		}
		i++;
		if (s[i] == '"')
			memory_for_wallace(s, wallace, i, w, y);
	}
	else
	{
		while (s[i] != ' ' && s[i] != '<' && s[i] != '>'
			&& s[i] != 39 && s[i] != '"' && s[i])
		{
			i++;
			y++;
		}
	}
	wallace[w] = malloc(sizeof(char ) * (y + 1));
	return (i);
}

int	gest_comillas(char *s, char **wallace, int i, int w, int y)
{
	if (y == 0)
		memory_for_wallace(s, wallace, i, w, y);
	if (s[i] == 39)
	{
		i++;
		while (s[i] != 39 && s[i])
			wallace[w][y++] = s[i++];
		wallace[w][y] = '\0';
		i++;
		if (s[i] == 39)
			return (gest_comillas(s, wallace, i, w, y));
	}
	if (s[i] == '"')
	{
		i++;
		while (s[i] != '"' && s[i])
			wallace[w][y++] = s[i++];
		wallace[w][y] = '\0';
		i++;
		if (s[i] == '"')
			return (gest_comillas(s, wallace, i, w, y));
	}
	return (i);
}

int	dr_no_comillas(char *s, char **wallace, int i, int w, int y)
{
	memory_for_wallace(s, wallace, i, w, y);
	while (s[i] != ' ' && s[i] != '"' && s[i] != '<'
		&& s[i] != '>' && s[i] != 39 && s[i])
	{
		wallace[w][y++] = s[i++];
	}
	wallace[w][y] = '\0';
	return (i);
}

char	**dr_comillas(char *s)
{
	char	**wallace;
	int		i;
	int		w;

	w = 0;
	i = 0;
	wallace = NULL;
	wallace = fill_wallace(wallace, s);
	while (s[i] && s[i] != '<' && s[i] != '>')
	{
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] == '"' || s[i] == 39)
		{
			i = gest_comillas(s, wallace, i, w, 0);
			w++;
		}
		else
		{
			i = dr_no_comillas(s, wallace, i, w, 0);
			w++;
		}
		while (s[i] == ' ' && s[i])
			i++;
		if (s[i] == '\0')
			break ;
	}
	wallace[w] = NULL;
	return (wallace);
}
