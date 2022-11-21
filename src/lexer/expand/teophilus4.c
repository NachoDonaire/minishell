/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:41:44 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/21 10:52:19 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	comillas_simples_i(char *s, int i)
{
	while (s[i] != ' ' && s[i] != '"'
		&& s[i] != 39 && s[i] != '/' && s[i] != '=')
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

int	comillas_simples(char *s, char *o, t_general_data *data, int f, int w)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 39)
	{
		if (s[i] == '"')
			w = comillas_dobles(&s[i], o, data, f, w);
		else if (s[i] == '$')
		{
			w = dollar(&s[i], o, data, f, w);
			i = comillas_simples_i(s, i);
			if (s[i] == 39)
			{
				o[w++] = s[i++];
				return (w);
			}
		}
		o[w++] = s[i++];
	}
	if (i == 0 && f == 0)
		return (w);
	o[w++] = s[i++];
	return (w);
}

int	dollar_ref_0_i(char *s, int i)
{
	while (s[i] != ' ' && s[i] != 39 && s[i] != '"'
		&& s[i] && s[i] != '/' && s[i] != '=' && s[i] != '$')
		i++;
	return (i);
}

int	not_dollar(char *s, int w, int i, char *of)
{
	while (s[i] == '$' && s[i])
		of[w++] = s[i++];
	return (w);
}

int	dollar_ref_0_w(char *c, char *of, int w)
{
	int	y;

	y = 0;
	while (c[y])
		of[w++] = c[y++];
	return (w);
}
