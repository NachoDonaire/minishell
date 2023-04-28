/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 17:04:50 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_reset_table_9(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
}

void	memory_for_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int		t[4];
	int		x;
	char	**wallace;

	ft_reset_table_9(t);
	x = gen_data->n_built;
	while (tmp[++t[2]])
	{
		wallace = dr_comillas(tmp[t[2]]);
		while (wallace[t[0]])
		{
			while (wallace[t[0]][t[1]])
				t[1]++;
			if (ref == 0)
				gen_data->cmd[y].out[t[3]] = malloc(sizeof(char) * (t[1] + 1));
			else if (ref == 1)
				gen_data->blt[x].out[t[3]] = malloc(sizeof(char) * (t[1] + 1));
			t[1] = 0;
			t[0]++;
			t[3]++;
		}
		ft_free_arg(wallace);
		t[0] = 0;
		t[1] = 0;
	}
}

void	ft_reset_table_5(int *t, t_general_data *gen_data)
{
	t[0] = 0;
	t[1] = 1;
	t[2] = 0;
	t[3] = 0;
	t[4] = gen_data->n_built;
	t[5] = 0;
	t[6] = 0;
}

void	ft_modify_table_2(int *t)
{
	t[6]++;
	t[5] = 0;
	t[3]++;
	t[0] = 0;
}

void	paste_tmp_red_ref(t_general_data *gen_data, int y, int ref, int *t)
{
	if (ref == 0)
		gen_data->cmd[y].out[t[3]] = NULL;
	else if (ref == 1)
		gen_data->blt[t[4]].out[t[3]] = NULL;
}
