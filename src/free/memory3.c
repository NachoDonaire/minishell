/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:16:49 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/14 17:04:59 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	needed_free(t_general_data *gen_data, int y)
{
	(void)y;
	close_fds(gen_data);
	close(gen_data->std_in);
	close(gen_data->std_out);
	ft_free_built(gen_data);
	ft_free_cmd(gen_data, y);
	free(gen_data->blt);
	free(gen_data->cmd);
	free(gen_data->sort);
	if (gen_data->n_pipes > 0)
		ft_free_arg((char **)gen_data->pipe);
}
