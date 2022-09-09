/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:09 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 12:25:04 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	memory_for_in_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int	i;
	int	z;
	int	w;
	int	x;

	i = 0;
	z = 1;
	w = 0;
	x = gen_data->n_built;
	while (tmp[z])
	{
		while (tmp[z][i])
			i++;
		if (ref == 0)
			gen_data->cmd[y].in[w] = malloc(sizeof(char) * (i + 1));
		else if (ref == 1)
			gen_data->blt[x].in[w] = malloc(sizeof(char) * (i + 1));
		z++;
		w++;
		i = 0;
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

	ft_reset_table2(t, gen_data);
	while (tmp[t[1]])
	{
		while (tmp[t[1]][t[2]])
		{
			if (tmp[t[1]][t[2]] == ' ')
				t[2]++;
			if (ref == 0)
				gen_data->cmd[y].in[t[3]][t[0]++] = tmp[t[1]][t[2]];
			if (ref == 1)
				gen_data->blt[t[4]].in[t[3]][t[0]++] = tmp[t[1]][t[2]];
			t[2]++;
		}
		if (ref == 0)
			gen_data->cmd[y].in[t[3]][t[0]] = '\0';
		else if (ref == 1)
			gen_data->blt[t[4]].in[t[3]][t[0]] = '\0';
		t[2] = 0;
		t[0] = 0;
		t[1]++;
		t[3]++;
	}
}

void	gest_in_reds(t_general_data *gen_data, char *s, int y, int ref)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, '<');
	i = 0;
	while (tmp[i])
		i++;
	if (ref == 0)
		gen_data->cmd[y].in = malloc(sizeof(char *) * (i + 1));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].in = malloc(sizeof(char *) * (i + 1));
	memory_for_in_red(gen_data, tmp, y, ref);
	paste_tmp_in_red(gen_data, tmp, y, ref);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	process_in_red(t_general_data *gen_data, char *s, int y, int ref)
{
	if (ref == 0)
	{
		if (find_in_red(s) == 1)
		{
			gest_in_reds(gen_data, s, y, ref);
			fd_reds_in(gen_data, y);
		}
		else
		{
			gen_data->cmd[y].in = malloc(sizeof(char *) * 1);
			gen_data->cmd[y].in[0] = malloc(sizeof(char) * 1);
			gen_data->cmd[y].fd_in = malloc(sizeof(int) * 1);
		}
	}
	else if (ref == 1)
	{
		if (find_in_red(s) == 1)
		{
			gest_in_reds(gen_data, s, y, ref);
			fd_reds_in_b(gen_data);
		}
		else
		{
			gen_data->blt[gen_data->n_built].in = malloc(sizeof(char) * 1);
			gen_data->blt[gen_data->n_built].in[0] = malloc(1);
			gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 1);

		}
	}
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

