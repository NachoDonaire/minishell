/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/10 18:38:36 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_pwd(t_general_data *gen_data)
{
	char	*buf;
	int		x;

	x = 0;
	if (gen_data->blt[gen_data->exec_pos].args[1])
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		ft_change_bad_status(gen_data->env, gen_data);
		return ;
	}
	buf = getcwd(NULL, 0);
	while (gen_data->blt->fd_out[x])
	{
		ft_putstr_fd(buf, gen_data->blt->fd_out[x]);
		ft_putstr_fd("\n", gen_data->blt->fd_out[x]);
		x++;
	}
	ft_change_good_status(gen_data->env, gen_data);
	free(buf);
}
