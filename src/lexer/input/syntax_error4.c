/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:50:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/19 09:50:57 by sasalama         ###   ########.fr       */
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

int	tacataca(char *s)
{
	int	i;
	int	y;
	int	z;

	z = 0;
	y = 0;
	i = 0;
	if (s[i] == '<')
	{
		while (s[i] == '<' && s[i])
		{
			i++;
			z++;
			y++;
		}
		if (y != 2)
			return (2);
		if (y == 2)
		{
			while (s[i] == ' ' && s[i++])
				z++;
			while (s[i])
				i++;
			//if (!s[i])
			//	return (2);
			if (z == i)
				return (2);
			return (1);
		}
	}
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
		/*if (s[i] == '"')
		{
			i++;
			while (s[i] != '"' && s[i])
				i++;
		}
		else if (s[i] == 39)
		{
			i++;
			while (s[i] != 39 && s[i])
				i++;
		}
		else if (s[i] == '<' || s[i] == '>')
*/
	/*
	int		t[3];
	char	**tmp;

	fill_table(t, 0);
	tmp = ft_split(s, '|');
	while (tmp[t[0]])
	{
		while (tmp[t[0]][t[1]] == ' ' && tmp[t[0]][t[1]++])
			t[2]++;
		while (tmp[t[0]][t[1]])
		{
			if (tmp[t[0]][t[1]] == '>' || tmp[t[0]][t[1]] == '<')
			{
				if (t[1] == t[2])
				{
					ft_free_arg(tmp);
					return (1);
				}
			}
			t[1]++;
		}
		fill_table(t, 420);
	}
	ft_free_arg(tmp);
	return (0);
}*/
