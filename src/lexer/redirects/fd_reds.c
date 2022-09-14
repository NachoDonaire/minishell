/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/14 11:24:53 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	fd_reds_out_b(t_general_data *gen_data)
{
	int		i;
	int		y;
	int		z;
	char	*s;

	y = 0;
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
		i++;
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
	{
		s = gen_data->blt[gen_data->n_built].out[i++];
		z = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		gen_data->blt[gen_data->n_built].fd_out[y] = z;
		if (gen_data->blt[gen_data->n_built].fd_out[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->blt[gen_data->n_built].fd_out[y] = -1;
}

void	fd_reds_in_b(t_general_data *gen_data)
{
	int		i;
	int		y;
	int		z;
	char	*s;

	y = 0;
	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
		i++;
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
	{
		s = gen_data->blt[gen_data->n_built].in[i++];
		z = open(s, O_RDONLY);
		gen_data->blt[gen_data->n_built].fd_in[y] = z;
		if (gen_data->blt[gen_data->n_built].fd_in[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->blt[gen_data->n_built].fd_in[y] = -1;
}

void	fd_reds_out(t_general_data *gen_data, int z)
{
	int		i;
	int		y;
	int		a;
	char	*s;

	y = 0;
	i = 0;
	while (gen_data->cmd[z].out[i])
		i++;
	gen_data->cmd[z].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].out[i])
	{
		s = gen_data->cmd[z].out[i++];
		a = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		gen_data->cmd[z].fd_out[y] = a;
		if (gen_data->cmd[z].fd_out[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->cmd[z].fd_out[y] = -1;
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
		gen_data->cmd[z].fd_in[y] = open(gen_data->cmd[z].in[i++], O_RDONLY);
		if (gen_data->cmd[z].fd_in[y] < 0)
			write(2, "error\n", 7);
		y++;
	}
	gen_data->cmd[z].fd_in[y] = -1;
}
