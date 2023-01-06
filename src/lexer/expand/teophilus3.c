/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teophilus3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:40:54 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/22 11:07:05 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	char_size(t_general_data *gen_data, int i)
{
	int	y;

	y = 0;
	while (gen_data->env[i][y])
	{
		if (gen_data->env[i][y] == '=')
			break ;
		y++;
	}
	return (y);
}

char	*variable(t_general_data *gen_data, char *t)
{
	int		i;
	int		y;
	int		z;
	char	*jutels;
	char	*c;

	y = 0;
	i = 0;
	c = ft_strjoin(t, "=");
	i = variable_size(gen_data, c);
	if (!gen_data->env[i])
		return (not_variable(gen_data, c));
	free(c);
	y = char_size(gen_data, i);
	z = y;
	y++;
	while (gen_data->env[i][z])
		z++;
	jutels = malloc(sizeof(char ) * ((z - y) + 1));
	z = 0;
	while (gen_data->env[i][y])
		jutels[z++] = gen_data->env[i][y++];
	jutels[z] = '\0';
	return (jutels);
}

char	*copy_var(char *s)
{
	int		i;
	char	*jefferson;

	i = 0;
	while (s[i] != ' ' && s[i] != '"' && s[i] != '='
		&& s[i] != 39 && s[i] != '/' && s[i] != '$' && s[i] != '|')
		i++;
	jefferson = malloc(sizeof(char ) * (i + 1));
	i = 0;
	if (s[i] >= '0' && s[i] <= '9')
	{
		jefferson[i] = s[i];
		i++;
		jefferson[i] = '\0';
		return (jefferson);
	}
	while (s[i] != ' ' && s[i] != '"' && s[i] != 39
		&& s[i] != '/' && s[i] != '=' && s[i] != '$' && s[i] != '|')
	{
		jefferson[i] = s[i];
		i++;
	}
	jefferson[i] = '\0';
	return (jefferson);
}

int	comillas_dobles_i(char *s, int i)
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

int	comillas_dobles(char *s, t_general_data *data, int f, t_teo teophi)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '"')
	{
		if (s[i] == 39)
			teophi.w = comillas_simples(&s[i], data, f, teophi);
		else if (s[i] == '$')
		{
			teophi.w = dollar(&s[i], data, f, teophi);
			i = comillas_dobles_i(s, i);
			if (s[i] == '"')
			{
				teophi.of[teophi.w++] = s[i];
				return (teophi.w);
			}
		}
		teophi.of[teophi.w++] = s[i++];
	}
	if (i == 0 && f == 1)
		return (teophi.w);
	teophi.of[teophi.w++] = s[i++];
	return (teophi.w);
}
