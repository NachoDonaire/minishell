/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_red2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:48:47 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 09:48:58 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_count_dr_cmd(t_general_data *gen_data, int position)
{
	int	i;

	i = 0;
	while (gen_data->cmd[position].fd_out[i] > 0)
		i++;
	i--;
	return (i);
}

int	ft_count_dr_blt(t_general_data *gen_data, int n_built)
{
	int	i;

	i = 0;
	while (gen_data->blt[n_built].fd_out[i] > 0)
		i++;
	i--;
	return (i);
}
