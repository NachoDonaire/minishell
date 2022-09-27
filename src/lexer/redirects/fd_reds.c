/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/27 13:32:25 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	fd_reds_out_b(t_general_data *gen_data)
{
	int		i;
	int		y;
	int		z;
	char	*s;
	int		w;

	y = 0;
	w = 0;
	i = ft_count_blt_out(gen_data);
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
	{
		s = gen_data->blt[gen_data->n_built].out[i++];
		if (gen_data->blt[gen_data->n_built].dred[w] == 1)
			z = open(s, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (gen_data->blt[gen_data->n_built].dred[w] == 0)
			z = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		gen_data->blt[gen_data->n_built].fd_out[y] = z;
		if (gen_data->blt[gen_data->n_built].fd_out[y] < 0)
			write(2, "error\n", 7);
		y++;
		w++;
	}
	if (i == 0)
	{
		gen_data->blt[gen_data->n_built].fd_out[y] = 1;
		gen_data->blt[gen_data->n_built].fd_out[y + 1] = -1;
	}
	else
		gen_data->blt[gen_data->n_built].fd_out[y] = -1;
}

void	fd_reds_in_b(t_general_data *gen_data)
{
	int		i;
	int		y;
	int		z;
	char	*s;
	int		w;

	y = 0;
	w = 0;
	i = ft_count_cmd_in(gen_data);
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
	{
		s = gen_data->blt[gen_data->n_built].in[i++];
		if (gen_data->blt[gen_data->n_built].in_dred[w++] == 0)
		{
			z = open(s, O_RDWR);
			gen_data->blt[gen_data->n_built].fd_in[y] = z;
			if (gen_data->blt[gen_data->n_built].fd_in[y] < 0)
				write(2, "error\n", 7);
			y++;
		}
		if (gen_data->blt[gen_data->n_built].in_dred[z] < 0)
			break ;
	}
	gen_data->blt[gen_data->n_built].fd_in[y] = -1;
}

void	fd_reds_out(t_general_data *gen_data, int z)
{
	int		table[3];
	int		a;
	char	*s;

	table[0] = 0;
	table[1] = 0;
	table[2] = 0;
	while (gen_data->cmd[z].out[table[2]])
		table[2]++;
	gen_data->cmd[z].fd_out = malloc(sizeof(int) * (table[2] + 1));
	table[2] = 0;
	while (gen_data->cmd[z].out[table[2]])
	{
		s = gen_data->cmd[z].out[table[2]++];
		if (gen_data->cmd[z].dred[table[1]++] == 1)
			a = open(s, O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			a = open(s, O_RDWR | O_CREAT | O_TRUNC, 0644);
		gen_data->cmd[z].fd_out[table[0]] = a;
		if (gen_data->cmd[z].fd_out[table[0]] < 0)
			write(2, "error\n", 7);
		table[0]++;
	}
	gen_data->cmd[z].fd_out[table[0]] = -1;
}

void	fd_reds_in(t_general_data *gen_data, int z)
{
	int	i;
	int	y;
	int	w;

	y = 0;
	w = 0;
	i = 0;
	while (gen_data->cmd[z].in[i])
		i++;
	gen_data->cmd[z].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].in[i])
	{
		if (gen_data->cmd[z].in_dred[w++] == 0)
		{
			gen_data->cmd[z].fd_in[y] = open(gen_data->cmd[z].in[i++], O_RDONLY);
			if (gen_data->cmd[z].fd_in[y] < 0)
				write(2, "error\n", 7);
			y++;
		}
		if (gen_data->cmd[z].in_dred[w] == -1)
			break ;
	}
	gen_data->cmd[z].fd_in[y] = -1;
}
