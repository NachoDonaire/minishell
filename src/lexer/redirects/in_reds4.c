/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_reds4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:21:10 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:48:56 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	paste_tmp_in_red2(t_general_data *gen_data, int y, int ref, int *t)
{
	if (ref == 0)
		gen_data->cmd[y].in[t[3]] = 0;
	else if (ref == 0)
		gen_data->blt[gen_data->n_built].in[t[3]] = 0;
}

void	ft_paste_tmp_in_ref(t_general_data *gen_data, int y, int ref, int *t)
{
	if (ref == 0)
		gen_data->cmd[y].in[t[3]][t[0]] = '\0';
	else if (ref == 1)
		gen_data->blt[t[4]].in[t[3]][t[0]] = '\0';
}

void	paste_tmp_in_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int		t[6];
	char	**wallace;

	ft_reset_table2(t, gen_data);
	while (tmp[t[1]])
	{
		wallace = dr_comillas(tmp[t[1]]);
		while (wallace[t[5]])
		{
			while (wallace[t[5]][t[2]])
			{
				if (ref == 0)
					gen_data->cmd[y].in[t[3]][t[0]++] = wallace[t[5]][t[2]];
				if (ref == 1)
					gen_data->blt[t[4]].in[t[3]][t[0]++] = wallace[t[5]][t[2]];
				t[2]++;
			}
			ft_paste_tmp_in_ref(gen_data, y, ref, t);
			ft_modify_table(t);
		}
		ft_modify_table2(t);
		ft_free_arg(wallace);
	}
	paste_tmp_in_red2(gen_data, y, ref, t);
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

void	find_in_red_quote(char *s, int *table)
{
	if (s[table[0]] == '"')
	{
		table[0]++;
		while (s[table[0]] != '"' && s[table[0]])
			table[0]++;
	}
	else if (s[table[0]] == 39)
	{
		table[0]++;
		while (s[table[0]] != 39 && s[table[0]])
			table[0]++;
	}
}
