/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:50:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 14:17:16 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	fill_table(int *t, int ref)
{
	if (ref == 0)
	{
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
	}
	else
	{
		t[0]++;
		t[1] = 0;
		t[2] = 0;
	}
}

void	ft_declare_table(int *table)
{
	table[0] = 0;
	table[1] = 0;
	table[2] = 0;
}

void	tacataca2(char *s, int *table)
{
	while (s[table[2]])
		table[2]++;
}

int	tacataca(char *s)
{
	int	table[3];

	ft_declare_table(table);
	if (s[table[2]] == '<')
	{
		while (s[table[2]] == '<' && s[table[2]++])
		{
			table[0]++;
			table[1]++;
		}
		if (table[1] != 2)
			return (2);
		if (table[1] == 2)
		{
			while (s[table[2]] == ' ' && s[table[2]++])
				table[0]++;
			tacataca2(s, table);
			if (table[0] == table[2])
				return (2);
			return (1);
		}
	}
	else if (s[table[2]] == '>')
		return (3);
	return (2);
}

int	check_tukle(char *s)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s[i] == ' ' && s[i++])
		y++;
	if (s[i] == '<' || s[i] == '>')
		return (tacataca(&s[i]));
	return (0);
}
