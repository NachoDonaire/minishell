/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   el_dr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:01:25 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/21 11:02:00 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	gest_comillas_34(char *s, char **wallace, int i, int w, int y)
{
	wallace[w][y] = '\0';
	if (s[++i] != ' ' && s[i])
		return (gest_comillas(s, wallace, i, w, y));
	return (i);
}

int	gest_comillas_39(char *s, char **wallace, int i, int w, int y)
{
	wallace[w][y] = '\0';
	if (s[++i] != ' ' && s[i])
		return (gest_comillas(s, wallace, i, w, y));
	return (i);
}

int	gest_comillas(char *s, char **wallace, int i, int w, int y)
{
	gest_comillas_not_y(s, wallace, i, w, y);
	if (s[i] == 39)
	{
		while (s[++i] != 39 && s[i])
			wallace[w][y++] = s[i];
		return (gest_comillas_39(s, wallace, i, w, y));
	}
	else if (s[i] == '"')
	{
		while (s[++i] != '"' && s[i])
			wallace[w][y++] = s[i];
		return (gest_comillas_34(s, wallace, i, w, y));
	}
	else if (s[i] != ' ' && s[i])
	{
		while (s[i] != ' ' && s[i])
		{
			if (s[i] == '"' || s[i] == 39)
				return (gest_comillas(s, wallace, i, w, y));
			wallace[w][y++] = s[i++];
		}
		gest_comillas_not_s(s, wallace, i, w, y);
	}
	return (i);
}

int	dr_no_comillas(char *s, char **wallace, int i, int w, int y)
{
	memory_for_wallace(s, wallace, i, w, y);
	while (s[i] != ' ' && s[i] != '<'
		&& s[i] != '>' && s[i])
	{
		if (s[i] == '"')
			return (gest_comillas(s, wallace, i, w, y));
		else if (s[i] == 39)
			return (gest_comillas(s, wallace, i, w, y));
		wallace[w][y++] = s[i++];
	}
	wallace[w][y] = '\0';
	return (i);
}