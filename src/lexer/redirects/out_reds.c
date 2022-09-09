/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 12:55:19 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	gest_reds(t_general_data *gen_data, char *s, int y, int ref)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, '>');
	i = 0;
	while (tmp[i])
		i++;
	if (ref == 0)
		gen_data->cmd[y].out = malloc(sizeof(char *) * (i));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * (i));
	memory_for_red(gen_data, tmp, y, ref);
	paste_tmp_red(gen_data, tmp, y, ref);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	memory_for_red(t_general_data *gen_data, char **tmp, int y, int ref)
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
			gen_data->cmd[y].out[w] = malloc(sizeof(char) * (i + 1));
		else if (ref == 1)
			gen_data->blt[x].out[w] = malloc(sizeof(char) * (i + 1));
		z++;
		w++;
		i = 0;
	}
}

void	ft_reset_table(int *t, t_general_data *gen_data)
{
	t[0] = 0;
	t[1] = 1;
	t[2] = 0;
	t[3] = 0;
	t[4] = gen_data->n_built;
}

void	paste_tmp_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int	t[5];

	ft_reset_table(t, gen_data);
	while (tmp[t[1]])
	{
		while (tmp[t[1]][t[2]])
		{
			if (tmp[t[1]][t[2]] == ' ')
				t[2]++;
			if (ref == 0)
				gen_data->cmd[y].out[t[3]][t[0]++] = tmp[t[1]][t[2]];
			else if (ref == 1)
				gen_data->blt[t[4]].out[t[3]][t[0]++] = tmp[t[1]][t[2]];
			t[2]++;
		}
		if (ref == 0)
			gen_data->cmd[y].out[t[3]][t[0]] = '\0';
		else if (ref == 1)
				gen_data->blt[t[4]].out[t[3]][t[0]++] = '\0';
		t[2] = 0;
		t[0] = 0;
		t[1]++;
		t[3]++;
	}
	if (ref == 0)
		gen_data->cmd[y].out[t[3]] = NULL;
	else if (ref == 0)
		gen_data->blt[t[4]].out[t[3]] = NULL;
}

void	process_sing_red(t_general_data *gen_data, char *s, int y, int ref)
{
	if (ref == 0)
		ft_ref_zero(gen_data, s, y, ref);
	else if (ref == 1)
		ft_ref_one(gen_data, s, y, ref);
}

