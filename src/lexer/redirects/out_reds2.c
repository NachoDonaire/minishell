/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:50:34 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:54:20 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	find_red2(t_general_data *gen_data, int ref, int z, int pos)
{
	if (ref == 0)
		gen_data->cmd[pos].dred[z] = -1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[z] = -1;
	if (z == 0)
		return (0);
	return (1);
}

void	find_red_one(t_general_data *gen_data, int ref, int pos, int *table)
{
	if (ref == 0)
		gen_data->cmd[pos].dred[table[0]++] = 0;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[table[0]++] = 0;
}

void	find_red_two(t_general_data *gen_data, int ref, int pos, int *table)
{
	if (ref == 0)
		gen_data->cmd[pos].dred[table[0]++] = 1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[table[0]++] = 1;
}

void	ft_reset_table4(int *table)
{
	table[0] = 0;
	table[1] = 0;
	table[2] = 0;
}

int	find_red(t_general_data *gen_data, char *s, int pos, int ref)
{
	int	table[3];

	ft_reset_table4(table);
	memory_dred(gen_data, s, pos, ref);
	if (ref == 0)
		gen_data->cmd[pos].dred[table[0]] = -1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[table[0]] = -1;
	while (s[table[2]])
	{
		find_red2_quote(s, table);
		while (s[table[2]] == '>' && s[table[2]])
		{
			table[2]++;
			table[1]++;
		}
		if (table[1] == 1)
			find_red_one(gen_data, ref, pos, table);
		else if (table[1] == 2)
			find_red_two(gen_data, ref, pos, table);
		if (table[1] == 0)
			table[2]++;
		table[1] = 0;
	}
	return (find_red2(gen_data, ref, table[0], pos));
}
