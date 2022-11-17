/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:05:08 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 08:48:40 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	gest_reds(t_general_data *gen_data, char *s, int y, int ref)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s, '>');
	i = -1;
	while (s[++i])
	{
		if (s[i] == '>')
			z++;
	}
	if (ref == 0)
	{
		gen_data->cmd[y].out = malloc(sizeof(char *) * (z + 1));
		gen_data->cmd[y].out[z] = 0;
	}
	else if (ref == 1)
	{
		gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * (z + 1));
		gen_data->blt[gen_data->n_built].out[z] = 0;
	}
	memory_for_red(gen_data, tmp, y, ref);
	paste_tmp_red(gen_data, tmp, y, ref);
	ft_free_arg(tmp);
}

void	ft_ref_zero(t_general_data *gen_data, char *s, int y, int ref)
{
	if (find_red(gen_data, s, y, ref) == 1)
	{
		gest_reds(gen_data, s, y, ref);
		fd_reds_out(gen_data, y);
	}
	else
	{
		gen_data->cmd[y].out = malloc(sizeof(char *) * 1);
		gen_data->cmd[y].out[0] = NULL;
		gen_data->cmd[y].fd_out = malloc(sizeof(int) * 2);
		gen_data->cmd[y].fd_out[0] = 1;
		gen_data->cmd[y].fd_out[1] = -1;
	}
}

void	ft_ref_one(t_general_data *gen_data, char *s, int y, int ref)
{
	if (find_red(gen_data, s, y, ref) == 1)
	{
		gest_reds(gen_data, s, y, ref);
		fd_reds_out_b(gen_data);
	}
	else
	{
		gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
		gen_data->blt[gen_data->n_built].out[0] = NULL;
		gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 3);
		gen_data->blt[gen_data->n_built].fd_out[0] = 1;
		gen_data->blt[gen_data->n_built].fd_out[1] = -1;
		gen_data->blt[gen_data->n_built].fd_out[2] = 0;
	}
}

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

void	memory_dred(t_general_data *gen_data, char *s, int pos, int ref)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '>')
			y++;
		i++;
	}
	if (ref == 0)
		gen_data->cmd[pos].dred = malloc(sizeof(int) * (y + 1));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].dred = malloc(sizeof(int) * (y + 1));
}
