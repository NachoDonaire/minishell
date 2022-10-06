/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comillas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:04 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/07 00:23:34 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

/*en el propio comando*/
int	check_cmllas(char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if ((s[i] == '"' || s[i] == 39) && lens(s) > 1)
	{
		while (s[i] != ' ' && s[i])
		{
			i++;
			if (s[i] == '"' || s[i] == 39)
				return (1);
		}
	}
	return (0);
}

char	*gest_cmllas(char *s)
{
	char	*sol;
	int		i;
	int		y;

	i = 0;
	y = 0;
	sol = malloc(sizeof(char) * lens(s));
	while (s[i] != '"' && s[i] != 39)
		i++;
	i++;
	while (s[i] != '"' && s[i] != 39)
	{
		sol[y++] = s[i++];
	}
	sol[y] = '\0';
	return (sol);
}
/*mas alla del comando*/

void	ft_reset_table_6(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = -1;
	t[4] = 0;
	t[5] = 1;
	t[6] = 0;
}

void	dr_comillas_aviso(char *s, char **wallace, int *t)
{
	wallace[t[6]] = malloc(sizeof(char) * (t[3] + 1));
	t[3] = t[3] - t[2] - t[0];
	while (s[t[3]] == ' ' || s[t[3]] == '>')
		t[3]++;
	while (t[5] < t[2] || s[t[3]] == ' ' || s[t[3]] == '>')
	{
		if ((s[t[3]] == ' ' && t[3] != 0) || s[t[3]] == '>' )
		{
			while (s[t[3]] == ' ' || s[t[3]] == '>')
				t[3]++;
			if ((s[t[3]] == '"' || s[t[3]] == '\0') && s[t[3] + 1] != '"')
				break ;
			else if (s[t[3]] == '"' && s[t[3] + 1] == '"')
				t[3] += 2;
			else
			{
				wallace[t[6]][t[1]] = '\0';
				t[6]++;
				wallace[t[6]] = malloc(sizeof(char ) * (t[2] - t[5] + 1));
				t[1] = 0;
			}
		}
		t[5]++;
		wallace[t[6]][t[1]++] = s[t[3]++];
	}
	wallace[t[6]][t[1]] = '\0';
	t[6]++;
}

void	dr_comillas_not_aviso(char *s, char **wallace, int *t)
{
	t[3]++;
	while (s[t[3]])
	{
		if (s[t[3]] == '"')
			break ;
		t[3]++;
		t[5]++;
	}
	wallace[t[6]] = malloc(sizeof(char ) * (t[5] + 1));
	t[3] = t[3] - t[5];
	while (s[t[3]])
	{
		if (s[t[3]] == '"' && s[t[3] + 1] != '"')
		{
			t[3]++;
			break ;
		}
		else if (s[t[3]] == '"' && s[t[3] + 1] == '"')
			t[3] += 2;
		wallace[t[6]][t[1]++] = s[t[3]++];
	}
	wallace[t[6]][t[1]] = '\0';
	t[6]++;
	t[5] = 0;
}
