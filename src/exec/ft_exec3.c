/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:40:22 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 20:40:42 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_status_error(t_general_data *gen_data, int position, int n_built)
{
	if (gen_data->sort[gen_data->exec_pos] == '1')
	{
		ft_putstr_fd("Minishell: command not found: ", 2);
		ft_putstr_fd(gen_data->cmd[position].cmd, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (gen_data->sort[gen_data->exec_pos] == '0')
	{
		ft_putstr_fd("Minishell: command not found: ", 2);
		ft_putstr_fd(gen_data->blt[n_built].blt, 2);
		ft_putstr_fd("\n", 2);
	}
}
