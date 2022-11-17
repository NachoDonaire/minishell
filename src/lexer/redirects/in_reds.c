/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:09 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 08:51:03 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_reset_table3(int *t)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = 0;
	t[3] = 0;
}

void	memory_for_in_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int		t[4];
	int		x;
	char	**wallace;

	ft_reset_table3(t);
	x = gen_data->n_built;
	while (tmp[++t[2]])
	{
		wallace = dr_comillas(tmp[t[2]]);
		while (wallace[t[0]])
		{
			while (wallace[t[0]][t[1]])
				t[1]++;
			if (ref == 0)
				gen_data->cmd[y].in[t[3]] = malloc(sizeof(char) * (t[1] + 1));
			else if (ref == 1)
				gen_data->blt[x].in[t[3]] = malloc(sizeof(char) * (t[1] + 1));
			t[1] = 0;
			t[0]++;
			t[3]++;
		}
		ft_free_arg(wallace);
		t[0] = 0;
		t[1] = 0;
	}
}

void	ft_reset_table2(int *table, t_general_data *gen_data)
{
	table[0] = 0;
	table[1] = 1;
	table[2] = 0;
	table[3] = 0;
	table[4] = gen_data->n_built;
	table[5] = 0;
}

void	ft_modify_table(int *t)
{
	t[5]++;
	t[2] = 0;
	t[3]++;
	t[0] = 0;
}

void	ft_modify_table2(int *t)
{
	t[2] = 0;
	t[5] = 0;
	t[1]++;
}
