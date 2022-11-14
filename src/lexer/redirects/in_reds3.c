/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_reds3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:06:16 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 10:09:16 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_process_in_ref0(t_general_data *gen_data, char *s, int y, int ref)
{
	if (find_in_red(gen_data, s, y, ref) == 1)
	{
		gest_in_reds(gen_data, s, y, ref);
		fd_reds_in(gen_data, y);
	}
	else
	{
		gen_data->cmd[y].in = malloc(sizeof(char *) * 1);
		gen_data->cmd[y].in[0] = NULL;
		gen_data->cmd[y].fd_in = malloc(sizeof(int) * 2);
		gen_data->cmd[y].fd_in[0] = -1;
		gen_data->cmd[y].fd_in[1] = 0;
	}
}

void	ft_process_in_ref1(t_general_data *gen_data, char *s, int y, int ref)
{
	if (find_in_red(gen_data, s, y, ref) == 1)
	{
		gest_in_reds(gen_data, s, y, ref);
		fd_reds_in_b(gen_data);
	}
	else
	{
		gen_data->blt[gen_data->n_built].in = malloc(sizeof(char *) * 1);
		gen_data->blt[gen_data->n_built].in[0] = NULL;
		gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 2);
		gen_data->blt[gen_data->n_built].fd_in[0] = -1;
		gen_data->blt[gen_data->n_built].fd_in[0] = 0;
	}
}

void	process_in_red(t_general_data *gen_data, char *s, int y, int ref)
{
	if (ref == 0)
		ft_process_in_ref0(gen_data, s, y, ref);
	else if (ref == 1)
		ft_process_in_ref1(gen_data, s, y, ref);
}

void	memory_indred(t_general_data *gen_data, char *s, int pos, int ref)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
			y++;
		i++;
	}
	if (ref == 0)
		gen_data->cmd[pos].in_dred = malloc(sizeof(int) * (y + 1));
	else if (ref == 1)
	{
		i = gen_data->n_built;
		gen_data->blt[i].in_dred = malloc(sizeof(int) * (y + 1));
	}
}

void	no_red_in(t_general_data *gen_data, int y)
{
	gen_data->blt[gen_data->n_built].in = malloc(sizeof(char) * 1);
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 1);
	gen_data->cmd[y].in = malloc(sizeof(char) * 1);
	gen_data->cmd[y].fd_in = malloc(sizeof(int) * 1);
}
