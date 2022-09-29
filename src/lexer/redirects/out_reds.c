/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/29 12:27:23 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	memory_for_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int		i;
	int		z;
	int		w;
	int		x;
	int		q;
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
				gen_data->cmd[y].out[w] = malloc(sizeof(char) * (q + 1));
			else if (ref == 1)
				gen_data->blt[x].out[w] = malloc(sizeof(char) * (q + 1));
			q = 0;
			i++;
			w++;
		}
		i = 0;
		z++;
		q = 0;
	}
}

/*	int	i;
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
	}*/

void	ft_reset_table(int *t, t_general_data *gen_data)
{
	t[0] = 0;
	t[1] = 1;
	t[2] = 0;
	t[3] = 0;
	t[4] = gen_data->n_built;
}

void	ft_modify_table(int *t)
{
	t[2] = 0;
	t[0] = 0;
	t[1]++;
	t[3]++;
}

void	paste_tmp_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int		t[5];
	char	**wallace;
	int		i;
	int		w;

	i = 0;
	w = 0;
	ft_reset_table(t, gen_data);
	while (tmp[t[1]])
	{
		wallace = dr_comillas(tmp[t[1]]);
		while (wallace[i])
		{
			while (wallace[i][w])
			{
				if (ref == 0)
					gen_data->cmd[y].out[t[3]][t[0]++] = wallace[i][w];
				else if (ref == 1)
					gen_data->blt[t[4]].out[t[3]][t[0]++] = wallace[i][w];
				w++;
			}
			if (ref == 0)
				gen_data->cmd[y].out[t[3]][t[0]] = '\0';
			else if (ref == 1)
				gen_data->blt[t[4]].out[t[3]][t[0]++] = '\0';
			i++;
			w = 0;
			t[3]++;
			t[0] = 0;
		}
		w = 0;
		i = 0;
		t[1]++;
		ft_free_arg(wallace);
//		ft_modify_table(t);
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
