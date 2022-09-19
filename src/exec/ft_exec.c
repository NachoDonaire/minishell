/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/19 10:18:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec(t_general_data *gen_data, int position)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (gen_data->cmd[position].cmd)
	{
		if (gen_data->sort[gen_data->exec_pos] == '1'
			&& gen_data->sort[gen_data->exec_pos])
		{
			if (gen_data->sort[gen_data->exec_pos + 1] == '1'
				|| gen_data->n_pipes == 1)
			{
				if (pipe(gen_data->pipe[position]) < 0)
					write(1, "error\n", 6);
			}
			ft_exec2(gen_data, position);
		}
	}
	return (position);
}
