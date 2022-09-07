/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_reds.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:23:16 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

void	gest_reds(t_general_data *gen_data, char *s, int y, int ref)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, '>');
	i = 0;
	while (tmp[i])
		i++;
	if (ref == 0)
		gen_data->cmd[y].out = malloc(sizeof(char *) * (i + 1));
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * (i + 1));
	memory_for_red(gen_data, tmp, y, ref);
	paste_tmp_red(gen_data, tmp, y, ref);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

void	memory_for_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int	i;
	int	z;
	int	w;

	i = 0;
	z = 1;
	w = 0;
	while (tmp[z])
	{
		while (tmp[z][i])
			i++;
		if (ref == 0)
			gen_data->cmd[y].out[w] = malloc(sizeof(char) * (i + 1));
		else if (ref == 1)
			gen_data->blt[gen_data->n_built].out[w] = malloc(sizeof(char) * (i + 1));
		z++;
		w++;
		i = 0;
	}
}

void	paste_tmp_red(t_general_data *gen_data, char **tmp, int y, int ref)
{
	int	z;
	int	i;
	int	w;
	int	k;

	k = 0;
	z = 1;
	i = 0;
	w = 0;
	while (tmp[z])
	{
		while (tmp[z][i])
		{
			if (tmp[z][i] == ' ')
				i++;
			if (ref == 0)
				gen_data->cmd[y].out[w][k++] = tmp[z][i];
			else if (ref == 1)
				gen_data->blt[gen_data->n_built].out[w][k++] = tmp[z][i];
			i++;
		}
		if (ref == 0)
			gen_data->cmd[y].out[w][k] = '\0';
		else if (ref == 1)
				gen_data->blt[gen_data->n_built].out[w][k++] = '\0';
		i = 0;
		k = 0;
		z++;
		w++;
	}
}

void	process_sing_red(t_general_data *gen_data, char *s, int y, int ref)
{
	if (ref == 0)
	{
		if (find_red(s) == 2)
		{
			gen_data->cmd[y].dred = 0;
			gest_reds(gen_data, s, y, ref);
		}
		else if (find_red(s) == 1)
		{
			gen_data->cmd[y].dred = 1;
			gest_reds(gen_data, s, y, ref);
		}
		else
		{
			gen_data->cmd[y].dred = 0;
			gen_data->cmd[y].out = malloc(sizeof(char *) * 1);
			gen_data->cmd[y].out[0] = malloc(1); 
		}
	}
	else if (ref == 1)
	{
		if (find_red(s) == 2)
		{
			gen_data->blt[gen_data->n_built].dred = 0;
			gest_reds(gen_data, s, y, ref);
		}
		else if (find_red(s) == 1)
		{
			gen_data->blt[gen_data->n_built].dred = 1;
			gest_reds(gen_data, s, y, ref);
		}
		else
		{
			gen_data->blt[gen_data->n_built].dred = 0;
			gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
			gen_data->blt[gen_data->n_built].out[0] = malloc(1); 
		}
	}	
}

