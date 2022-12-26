/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_reds2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 10:24:51 by sasalama          #+#    #+#             */
/*   Updated: 2022/12/26 13:48:47 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	find_in_red_one(t_general_data *gen_data, int pos, int ref, int *table)
{
	if (ref == 0)
		gen_data->cmd[pos].in_dred[table[2]++] = 0;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].in_dred[table[2]++] = 0;
}

void	find_in_red_two(t_general_data *gen_data, int pos, int ref, int *table)
{
	if (ref == 0)
		gen_data->cmd[pos].in_dred[table[2]++] = 1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].in_dred[table[2]++] = 1;
}

int	find_in_red2(t_general_data *gen_data, int pos, int ref, int *table)
{
	if (ref == 0)
		gen_data->cmd[pos].in_dred[table[2]] = -1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].in_dred[table[2]] = -1;
	if (table[2] == 0)
		return (0);
	return (1);
}

void	ft_reset_table(int *table)
{
	table[2] = 0;
	table[1] = 0;
	table[0] = 0;
}

int	find_in_red(t_general_data *gen_data, char *s, int pos, int ref)
{
	int	table[3];

	ft_reset_table(table);
	memory_indred(gen_data, s, pos, ref);
	if (ref == 0)
		gen_data->cmd[pos].in_dred[table[2]] = -1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].in_dred[table[2]] = -1;
	while (s[table[0]])
	{
		find_in_red_quote(s, table);
		while (s[table[0]] == '<')
		{
			table[0]++;
			table[1]++;
		}
		if (table[1] == 1)
			find_in_red_one(gen_data, pos, ref, table);
		else if (table[1] == 2)
			find_in_red_two(gen_data, pos, ref, table);
		if (table[1] == 0)
			table[0]++;
		table[1] = 0;
	}
	return (find_in_red2(gen_data, pos, ref, table));
}
