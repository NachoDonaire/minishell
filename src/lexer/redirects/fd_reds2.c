/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_reds2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:00:54 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/02 16:29:20 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_count_blt_out(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->blt[gen_data->n_built].out[i])
		i++;
	return (i);
}

int	ft_count_cmd_in(t_general_data *gen_data)
{
	int	i;

	i = 0;
	while (gen_data->blt[gen_data->n_built].in[i])
		i++;
	return (i);
}

void	ft_reset_table_7(int *t, t_general_data *gen_data)
{
	t[0] = 0;
	t[1] = 0;
	t[2] = ft_count_blt_out(gen_data);
}
