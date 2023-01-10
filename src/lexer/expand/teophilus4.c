/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:41:44 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/10 21:37:04 by sasalama         ###   ########.fr       */
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

int	comillas_simples(char *s, t_general_data *data, int f, t_teo teophi)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 39)
	{
		if (s[i] == '"')
			teophi.w = comillas_dobles(&s[i], data, f, teophi);
		else if (s[i] == '$')
		{
			teophi.w = dollar(&s[i], data, f, teophi);
			i = comillas_simples_i(s, i);
			if (s[i] == 39)
			{
				teophi.of[teophi.w++] = s[i++];
				return (teophi.w);
			}
		}
		teophi.of[teophi.w++] = s[i++];
	}
	if (i == 0 && f == 0)
		return (teophi.w);
	teophi.of[teophi.w++] = s[i++];
	return (teophi.w);
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
	ft_free_c(c);
	return (w);
}
