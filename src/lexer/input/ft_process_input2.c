/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 16:30:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 09:05:42 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_reset_blt(t_general_data *gen_data)
{
	gen_data->blt[gen_data->n_built].blt = malloc(sizeof(char) * 1);
	gen_data->blt[gen_data->n_built].blt[0] = '\0';
	gen_data->blt[gen_data->n_built].args = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].args[0] = NULL;
	gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].out[0] = NULL;
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 2);
	gen_data->blt[gen_data->n_built].fd_out[0] = 1;
	gen_data->blt[gen_data->n_built].fd_out[1] = -1;
	gen_data->blt[gen_data->n_built].dred = malloc(sizeof(int) * 1);
	gen_data->blt[gen_data->n_built].in = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].in[0] = NULL;
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 1);
	gen_data->blt[gen_data->n_built].fd_in[0] = -1;
}

int	oficial_tukle(char *s, t_general_data *gen_data, int y)
{
	if (check_tukle(s) == 1)
	{
		gen_data->cmd[y].can_exec = 0;
		gen_data->cmd[y].syn_er = 23;
		gen_data->n_cmd--;
		return (1);
	}
	gen_data->cmd[y].syn_er = 0;
	return (0);
}
