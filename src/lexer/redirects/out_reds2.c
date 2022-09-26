/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:50:34 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 09:14:19 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	memory_dred(t_general_data *gen_data, char *s, int pos, int ref)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '>' && s[i + 1] != '>')
			y++;
		i++;
	}
	if (ref == 0)
		gen_data->cmd[pos].dred = malloc(sizeof(int) * (y + 1));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred = malloc(sizeof(int) * (y + 1));
}

int	find_red2(t_general_data *gen_data, int pos, int ref, int z)
{
	if (ref == 0)
		gen_data->cmd[pos].dred[z] = -1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[z++] = -1;
	if (z == 0)
		return (0);
	return (1);
}

void	find_red_one(t_general_data *gen_data, int pos, int ref, int z)
{
	if (ref == 0)
		gen_data->cmd[pos].dred[z++] = 0;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[z++] = 0;
}

void	find_red_two(t_general_data *gen_data, int pos, int ref, int z)
{
	if (ref == 0)
		gen_data->cmd[pos].dred[z++] = 1;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred[z++] = 1;
}

int	find_red(t_general_data *gen_data, char *s, int pos, int ref)
{
	int	i;
	int	y;
	int	z;

	z = 0;
	y = 0;
	i = 0;
	memory_dred(gen_data, s, pos, ref);
	gen_data->cmd[pos].dred[z] = -1;
	while (s[i])
	{
		while (s[i] == '>')
		{
			i++;
			y++;
		}
		if (y == 1)
			find_red_one(gen_data, pos, ref, z);
		else if (y == 2)
			find_red_two(gen_data, pos, ref, z);
		if (y == 0)
			i++;
		y = 0;
	}
	return (find_red2(gen_data, pos, ref, z));
}
