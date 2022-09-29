/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:09 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/28 19:41:21 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	memory_for_in_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int	i;
	int	z;
	int	w;
	int	x;
	int	q;
	char	**wallace;

	i = 0;
	q = 0;
	z = 1;
	w = 0;
	x = gen_data->n_built;
	while (tmp[z])
	{
		wallace = dr_comillas(tmp[z]);
		while (wallace[i])
		{
			while (wallace[i][q])
				q++;
			if (ref == 0)
				gen_data->cmd[y].in[w] = malloc(sizeof(char) * (q + 1));
			else if (ref == 1)
				gen_data->blt[x].in[w] = malloc(sizeof(char) * (q + 1));
			q = 0;
			i++;
			w++;
		}
		i = 0;
		z++;
		q = 0;
	//	w++;
	}
}

void	ft_reset_table2(int *table, t_general_data *gen_data)
{
	table[0] = 0;
	table[1] = 1;
	table[2] = 0;
	table[3] = 0;
	table[4] = gen_data->n_built;
}

void	paste_tmp_in_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int	t[5];
	char	**wallace;
	int	i;
	int	w;

	i = 0;
	w = 0;
	ft_reset_table2(t, gen_data);
	while (tmp[t[1]])
	{
		wallace = dr_comillas(tmp[t[1]]);
		while (wallace[i])
		{
			while (wallace[i][w])
			{
				if (ref == 0)
					gen_data->cmd[y].in[t[3]][t[0]++] = wallace[i][w];
				if (ref == 1)
					gen_data->blt[t[4]].in[t[3]][t[0]++] = wallace[i][w];
				w++;
			}
			if (ref == 0)
				gen_data->cmd[y].in[t[3]][t[0]] = '\0';
			else if (ref == 1)
				gen_data->blt[t[4]].in[t[3]][t[0]] = '\0';
			i++;
			w = 0;
			t[3]++;
			t[0] = 0;
		}
		w = 0;
		i = 0;
		t[1]++;
		ft_free_arg(wallace);
	}
	if (ref == 0)
		gen_data->cmd[y].in[t[3]] = NULL;
	else if (ref == 0)
		gen_data->blt[gen_data->n_built].in[t[3]] = NULL;
}

void	gest_in_reds(t_general_data *gen_data, char *s, int y, int ref)
{
	char	**tmp;
	int		i;
	int		w;

	w = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '<')
			w++;
		i++;
	}
	tmp = ft_split(s, '<');
	if (ref == 0)
		gen_data->cmd[y].in = malloc(sizeof(char *) * (w + 1));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].in = malloc(sizeof(char *) * (w + 1));
	memory_for_in_red(gen_data, tmp, y, ref);
	paste_tmp_in_red(gen_data, tmp, y, ref);
	ft_free_arg(tmp);
}

void	no_red_in(t_general_data *gen_data, int y)
{
	gen_data->blt[gen_data->n_built].in = malloc(sizeof(char) * 1);
	gen_data->blt[gen_data->n_built].in[0] = malloc(1);
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 1);
	gen_data->cmd[y].in = malloc(sizeof(char) * 1);
	gen_data->cmd[y].in[0] = malloc(1);
	gen_data->cmd[y].fd_in = malloc(sizeof(int) * 1);
}
