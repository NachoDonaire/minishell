/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:50:34 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 10:19:16 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	find_double_red(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '>' && s[i + 1] == '>' && s[i + 2] != '>')
			return (1);
		i++;
	}
	return (0);
}

void	ft_ref_zero(t_general_data *gen_data, char *s, int y, int ref)
{
	if (find_red(s) == 2)
	{
		gen_data->cmd[y].dred = 0;
		gest_reds(gen_data, s, y, ref);
		fd_reds_out(gen_data, y);
	}
	else if (find_red(s) == 1)
	{
		gen_data->cmd[y].dred = 1;
		gest_reds(gen_data, s, y, ref);
		fd_reds_out(gen_data, y);
	}
	else
	{
		gen_data->cmd[y].dred = 0;
		gen_data->cmd[y].out = malloc(sizeof(char *) * 1);
		gen_data->cmd[y].out[0] = malloc(1);
		gen_data->cmd[y].out[0] = NULL;
		gen_data->cmd[y].fd_out = malloc(sizeof(int) * 2);
		gen_data->cmd[y].fd_out[0] = 1;
		gen_data->cmd[y].fd_out[1] = -1;
	}
}

void	ft_ref_one(t_general_data *gen_data, char *s, int y, int ref)
{
	if (find_red(s) == 2)
	{
		gen_data->blt[gen_data->n_built].dred = 0;
		gest_reds(gen_data, s, y, ref);
		fd_reds_out_b(gen_data);
	}
	else if (find_red(s) == 1)
	{
		gen_data->blt[gen_data->n_built].dred = 1;
		gest_reds(gen_data, s, y, ref);
		fd_reds_out_b(gen_data);
	}
	else
	{
		gen_data->blt[gen_data->n_built].dred = 0;
		gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
		gen_data->blt[gen_data->n_built].out[0] = malloc(1);
		gen_data->blt[gen_data->n_built].out[0] = NULL;
		gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 2);
		gen_data->blt[gen_data->n_built].fd_out[0] = 1;
		gen_data->blt[gen_data->n_built].fd_out[1] = -1;
	}
}

int	find_red(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '>')
		{
			if (s[i + 1] == '>')
				return (1);
			else
				return (2);
		}
		i++;
	}
	return (0);
}

void	no_red_out(t_general_data *gen_data, int y)
{
	gen_data->blt[gen_data->n_built].dred = 0;
	gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].out[0] = malloc(1);
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 1);
	gen_data->cmd[y].dred = 0;
	gen_data->cmd[y].out = malloc(sizeof(char *) * 1);
	gen_data->cmd[y].out[0] = malloc(1);
	gen_data->cmd[y].fd_out = malloc(sizeof(int) * 1);
}
