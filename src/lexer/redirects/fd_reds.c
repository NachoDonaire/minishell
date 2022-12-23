/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 08:53:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	fd_reds_out_ref(t_general_data *gen_data, int *t)
{
	if (t[2] == 0)
	{
		gen_data->blt[gen_data->n_built].fd_out[t[0]] = 1;
		gen_data->blt[gen_data->n_built].fd_out[t[0] + 1] = -2;
	}
	else
		gen_data->blt[gen_data->n_built].fd_out[t[0]] = -2;
}

void	fd_reds_out_b(t_general_data *gen_data)
{
	int		t[4];
	char	*s;

	ft_reset_table_7(t, gen_data);
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * (t[2] + 2));
	gen_data->blt[gen_data->n_built].fd_out[t[2] + 1] = 0;
	t[2] = 0;
	while (gen_data->blt[gen_data->n_built].out[t[2]])
	{
		s = gen_data->blt[gen_data->n_built].out[t[2]++];
		if (gen_data->blt[gen_data->n_built].dred[t[1]] == 1)
			t[3] = open(s, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (gen_data->blt[gen_data->n_built].dred[t[1]] == 0)
			t[3] = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		gen_data->blt[gen_data->n_built].fd_out[t[0]] = t[3];
		if (gen_data->blt[gen_data->n_built].fd_out[t[0]] < 0)
		{
			gen_data->blt[gen_data->n_built].can_exec = 0;
			perror("file not found");
		}
		t[0]++;
		t[1]++;
	}
	fd_reds_out_ref(gen_data, t);
}

void	fd_reds_in_b(t_general_data *gen_data)
{
	int		t[4];
	char	*s;

	t[0] = 0;
	t[1] = 0;
	t[2] = ft_count_cmd_in(gen_data);
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * (t[2] + 1));
	t[2] = 0;
	while (gen_data->blt[gen_data->n_built].in[t[2]])
	{
		s = gen_data->blt[gen_data->n_built].in[t[2]++];
		if (gen_data->blt[gen_data->n_built].in_dred[t[0]++] == 0)
		{
			t[3] = open(s, O_RDWR);
			gen_data->blt[gen_data->n_built].fd_in[t[0]] = t[3];
			if (gen_data->blt[gen_data->n_built].fd_in[t[0]] < 0)
			{
				gen_data->blt[gen_data->n_built].can_exec = 0;
				perror("file not found");
			}
		}
		if (gen_data->blt[gen_data->n_built].in_dred[t[0]] < 0)
			break ;
	}
	gen_data->blt[gen_data->n_built].fd_in[t[0]] = -2;
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
			so_f_tired(gen_data, z);
		table[0]++;
	}
	gen_data->cmd[z].fd_out[table[0]] = -2;
}

void	fd_reds_in(t_general_data *gen_data, int z)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (gen_data->cmd[z].in[i])
		i++;
	gen_data->cmd[z].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].in[i])
	{
		if (gen_data->cmd[z].in_dred[i] == 0)
			gen_data->cmd[z].fd_in[y] = open(gen_data->cmd[z].in[i], O_RDONLY);
		else if (gen_data->cmd[z].in_dred[i] == 1)
			gen_data->taker = 2333;
		if (gen_data->cmd[z].fd_in[y] < 0 && gen_data->cmd[z].in_dred[i] == 0)
		{
			gen_data->cmd[z].can_exec = 0;
			perror("file not found");
		}
		y++;
		i++;
	}
	gen_data->cmd[z].fd_in[y] = -2;
}
