/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:10:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/09 10:04:53 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	no_red_out(t_general_data *gen_data, int y)
{
	gen_data->blt[gen_data->n_built].dred = 0;
	gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 1);
	gen_data->cmd[y].dred = 0;
	gen_data->cmd[y].out = malloc(sizeof(char *) * 1);
	gen_data->cmd[y].fd_out = malloc(sizeof(int) * 1);
}

void	paste_tmp_in_red_null(t_general_data *gen_data, int y, int ref, int *t)
{
	if (ref == 0)
		gen_data->cmd[y].out[t[3]][t[0]] = '\0';
	else if (ref == 1)
		gen_data->blt[t[4]].out[t[3]][t[0]++] = '\0';
}

void	paste_tmp_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int		t[7];
	char	**w;

	ft_reset_table_5(t, gen_data);
	while (tmp[t[1]])
	{
		w = dr_comillas(tmp[t[1]]);
		while (w[t[6]])
		{
			while (w[t[6]][t[5]])
			{
				if (ref == 0)
					gen_data->cmd[y].out[t[3]][t[0]++] = w[t[6]][t[5]];
				else if (ref == 1)
					gen_data->blt[t[4]].out[t[3]][t[0]++] = w[t[6]][t[5]];
				t[5]++;
			}
			paste_tmp_in_red_null(gen_data, y, ref, t);
			ft_modify_table_2(t);
		}
		ft_modify_table_3(t);
		ft_free_arg(w);
	}
	paste_tmp_red_ref(gen_data, y, ref, t);
}

void	process_sing_red(t_general_data *gen_data, char *s, int y, int ref)
{
	if (ref == 0)
		ft_ref_zero(gen_data, s, y, ref);
	else if (ref == 1)
		ft_ref_one(gen_data, s, y, ref);
}

void	ft_modify_table_3(int *t)
{
	t[5] = 0;
	t[6] = 0;
	t[1]++;
}
