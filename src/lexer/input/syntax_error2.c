/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:27:12 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/12 14:33:37 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	double_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '"')
		i++;
	return (i);
}

int	single_quotes(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != 39)
		i++;
	return (i);
}

int	check_millas(char *s)
{
	int	i;
	int	quote;

	i = 0;
	quote = 0;
	while (s[i])
	{
		if (quote == 0 && s[i] == '\"')
			quote = 1;
		else if (quote == 0 && s[i] == 39)
			quote = 2;
		else if (quote == 2 && s[i] == 39)
			quote = 0;
		else if (quote == 1 && s[i] == '\"')
			quote = 0;
		i++;
	}
	if (quote == 0)
		return (0);
	return (1);
}

int	check_pipes(char *s)
{
	int	t[2];

	reset_table_pipes(t);
	while (s[t[0]])
	{
		if (s[t[0]] == '|')
		{
			t[0]++;
			if (!s[t[0]])
				return (1);
			while (s[t[0]] && s[t[0]] != '|')
			{
				if (s[t[0]] != ' ' && s[t[0]] != '|')
					t[1]++;
				t[0]++;
			}
			if (t[1] == 0)
				return (1);
		}
		if (t[1] != 0)
			t[1] = 0;
		else
			t[0]++;
	}
	return (0);
}

int	pipes_count(char *s)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] == '|')
			y++;
		i++;
	}
	return (y);
}
