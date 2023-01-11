/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   el_dr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:00:01 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/11 10:43:21 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	**fill_wallace(char *s)
{
	int		i;
	int		y;
	int		z;
	char	**wallace;

	z = 0;
	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == ' ' )
			y++;
		if (s[i] == '"' || s[i] == 39)
			z++;
		i++;
	}
	wallace = malloc(sizeof(char *) * (y + 2 + (z)));
	return (wallace);
}

int	memory_for_wallace(char *s, t_dr dr_comillas, int y)
{
	if (s[dr_comillas.i] == 39)
	{
		while (s[++dr_comillas.i] != 39 && s[dr_comillas.i])
			y++;
		if (s[++dr_comillas.i] != ' ')
			return (memory_for_wallace(s, dr_comillas, y));
	}
	else if (s[dr_comillas.i] == '"')
	{
		while (s[++dr_comillas.i] != '"' && s[dr_comillas.i])
			y++;
		if (s[++dr_comillas.i] != ' ')
			return (memory_for_wallace(s, dr_comillas, y));
	}
	else
	{
		while (s[dr_comillas.i] != ' ' && s[dr_comillas.i] != '<'
			&& s[dr_comillas.i] != '>' && s[dr_comillas.i])
		{
			dr_comillas.i++;
			y++;
		}
	}
	dr_comillas.wallace[dr_comillas.w] = malloc(sizeof(char ) * 1024);
	return (dr_comillas.i);
}

void	gest_comillas_not_s(char *s, t_dr dr_comillas, int y)
{
	if (!s[dr_comillas.i])
		dr_comillas.wallace[dr_comillas.w][y] = '\0';
}

void	gest_comillas_not_y(char *s, t_dr dr_comillas, int y)
{
	if (y == 0)
		memory_for_wallace(s, dr_comillas, y);
}

char	**dr_comillas(char *s)
{
	t_dr	dr_comillas;

	dr_comillas.w = 0;
	dr_comillas.i = 0;
	dr_comillas.wallace = fill_wallace(s);
	while (s[dr_comillas.i] && s[dr_comillas.i] != '<'
		&& s[dr_comillas.i] != '>')
	{
		while (s[dr_comillas.i] == ' ' && s[dr_comillas.i])
			dr_comillas.i++;
		if (s[dr_comillas.i] == '"' || s[dr_comillas.i] == 39)
			dr_comillas.i = gest_comillas(s, dr_comillas, 0);
		else
			dr_comillas.i = dr_no_comillas(s, dr_comillas, 0);
		dr_comillas.w++;
		while (s[dr_comillas.i] == ' ' && s[dr_comillas.i])
			dr_comillas.i++;
		if (s[dr_comillas.i] == '\0')
			break ;
	}
	dr_comillas.wallace[dr_comillas.w] = 0;
	return (dr_comillas.wallace);
}
