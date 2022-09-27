/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 10:23:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 13:28:43 by ndonaire         ###   ########.fr       */
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
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
		i++;
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
	{
		s = gen_data->blt[gen_data->n_built].out[i];
		if (gen_data->blt[gen_data->n_built].dred[w] == 1)
			z = open(s, O_WRONLY | O_CREAT | O_APPEND, 0644);
		else if (gen_data->blt[gen_data->n_built].dred[w] == 0)
			z = open(s, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		gen_data->blt[gen_data->n_built].fd_out[y] = z;
		if (gen_data->blt[gen_data->n_built].fd_out[y] < 0)
			write(2, "error\n", 7);
		y++;
		i++;
		w++;
	}
	if (i == 0)
		gen_data->blt[gen_data->n_built].fd_out[y] = 1;
	else
		gen_data->blt[gen_data->n_built].fd_out[y] = -1;
}

void	fd_reds_in_b(t_general_data *gen_data)
{
	int		i;
	int		y;
	int		z;
	int		w;
	char	*s;

	y = 0;
	w = 0;
	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
		i++;
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
	int		i;
	int		y;
	int		a;
	int		w;
	char	*s;

	y = 0;
	w = 0;
	i = 0;
	while (gen_data->cmd[z].out[i])
		i++;
	gen_data->cmd[z].fd_out = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].out[i])
	{
		s = gen_data->cmd[z].out[i++];
		if (gen_data->cmd[z].dred[w++] == 1)
			a = open(s, O_RDWR | O_CREAT | O_APPEND, 0644);
		else
			a = open(s, O_RDWR | O_CREAT | O_TRUNC, 0644);
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
	int	w;

	w = 0;
	y = 0;
	i = 0;
	while (gen_data->cmd[z].in[i])
		i++;
	gen_data->cmd[z].fd_in = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (gen_data->cmd[z].in[i])
	{
		printf("//%d//!", gen_data->cmd[z].in_dred[w]);
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
