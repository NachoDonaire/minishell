/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reds2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 09:21:57 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 09:22:33 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_count_out_blt(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
		i++;
	return (i);
}

int	ft_count_out_cmd(t_general_data *gen_data, int z)
{
	int	i;

	i = 0;
	while (gen_data->cmd[z].out[i])
		i++;
	return (i);
}
