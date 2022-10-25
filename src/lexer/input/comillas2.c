/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comillas2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:00:02 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/07 00:23:33 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_modify_table_9(int *t)
{
	t[2] = 0;
	t[1] = 0;
	t[5] = 0;
	t[0] = 0;
	t[4]--;
}

void	ft_nb_malloc(char *s, int *t)
{
	while (s[++t[3]])
	{
		if (s[t[3]] == ' ')
			t[5]++;
	}
}

void	ft_nb_dq(char *s, int *t)
{
	t[3] = -1;
	while (s[++t[3]])
	{
		if (s[t[3]] == '"' || s[t[3]] == 39)
			t[4]++;
	}
}

void	dr_comillas_red(char *s, int *t)
{
	while (s[t[3]])
	{
		while ((s[t[3]] == ' ' || s[t[3]] == '>') && s[t[3]])
		{
			t[0]++;
			t[3]++;
		}
		if ((s[t[3]] == '"' || s[t[3]] == 39 || s[t[3]] == '\0') && s[t[3] + 1] != '"')
			break ;
		else if ((s[t[3]] == '"' && s[t[3] + 1] == '"') || (s[t[3]] == 39 && s[t[3] + 1] == 39))
			t[3] += 2;
		t[2]++;
		t[3]++;
	}
}

char	**dr_comillas(char *s)
{
	int		t[7];
	char	**wallace;

	ft_reset_table_6(t);
	ft_nb_malloc(s, t);
	wallace = malloc(sizeof(char *) * (t[5] + 1));
	ft_nb_dq(s, t);
	t[3] = 0;
	t[5] = 0;
	while (s[t[3]])
	{
		dr_comillas_red(s, t);
		if (t[2] != 0)
			dr_comillas_aviso(s, wallace, t);
		else if (t[2] == 0)
			dr_comillas_not_aviso(s, wallace, t);
		while (s[t[3]] == ' ')
			t[3]++;
		ft_modify_table_9(t);
	}
	wallace[t[6]] = malloc(1);
	wallace[t[6]] = 0;
	return (wallace);
}
/*
void	lexy_memory(char **lexy, char **wallace)
{
	int	i;

	i = 0;
	while (wallace[i])
		i++;
	lexy = malloc(sizeof(char *) * (i + 1));
}


char	**lexy_wallace(char *s, char **wallace)
{
	char	**lexy;
	int		i;
	int		y;
	int		we;

	i = 0;
	we = 0;
	y = 0;
	lexy_memory(lexy, wallace);
	while (s[i])
	{
		if (s[i] == '"')
		{
			if (i != 0)
				lexy[y++] = wallace[we++];
			while (s[i] != '"')
				i++;
			i++;
			if (s[i] == '"')
			{
				lexy[y++] = ft_strjoin(wallace[we], wallace[we + 1]);
				we++;
			}
			else
				lexy[y++] = wallace[we++];
		}
		i++;
	}
	
*/










