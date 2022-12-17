/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   el_dr2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:01:25 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/22 10:16:24 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	gest_comillas_34(char *s, t_dr dr_comillas, int y)
{
	dr_comillas.wallace[dr_comillas.w][y] = '\0';
	if (s[++dr_comillas.i] != ' ' && s[dr_comillas.i])
		return (gest_comillas(s, dr_comillas, y));
	return (dr_comillas.i);
}

int	gest_comillas_39(char *s, t_dr dr_comillas, int y)
{
	dr_comillas.wallace[dr_comillas.w][y] = '\0';
	if (s[++dr_comillas.i] != ' ' && s[dr_comillas.i])
		return (gest_comillas(s, dr_comillas, y));
	return (dr_comillas.i);
}

int	gest_comillas(char *s, t_dr dr_comillas, int y)
{
	gest_comillas_not_y(s, dr_comillas, y);
	if (s[dr_comillas.i] == 39)
	{
		while (s[++dr_comillas.i] != 39 && s[dr_comillas.i])
			dr_comillas.wallace[dr_comillas.w][y++] = s[dr_comillas.i];
		return (gest_comillas_39(s, dr_comillas, y));
	}
	else if (s[dr_comillas.i] == '"')
	{
		while (s[++dr_comillas.i] != '"' && s[dr_comillas.i])
			dr_comillas.wallace[dr_comillas.w][y++] = s[dr_comillas.i];
		return (gest_comillas_34(s, dr_comillas, y));
	}
	else if (s[dr_comillas.i] != ' ' && s[dr_comillas.i])
	{
		while (s[dr_comillas.i] != ' ' && s[dr_comillas.i])
		{
			if (s[dr_comillas.i] == '"' || s[dr_comillas.i] == 39)
				return (gest_comillas(s, dr_comillas, y));
			dr_comillas.wallace[dr_comillas.w][y++] = s[dr_comillas.i++];
		}
		gest_comillas_not_s(s, dr_comillas, y);
	}
	return (dr_comillas.i);
}

int	dr_no_comillas(char *s, t_dr dr_comillas, int y)
{
	memory_for_wallace(s, dr_comillas, y);
	while (s[dr_comillas.i] != ' ' && s[dr_comillas.i] != '<'
		&& s[dr_comillas.i] != '>' && s[dr_comillas.i])
	{
		if (s[dr_comillas.i] == '"')
			return (gest_comillas(s, dr_comillas, y));
		else if (s[dr_comillas.i] == 39)
			return (gest_comillas(s, dr_comillas, y));
		dr_comillas.wallace[dr_comillas.w][y++] = s[dr_comillas.i++];
	}
	dr_comillas.wallace[dr_comillas.w][y] = '\0';
	return (dr_comillas.i);
}
