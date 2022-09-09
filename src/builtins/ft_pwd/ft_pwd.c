/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 13:02:54 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_pwd(t_general_data *gen_data)
{
	char	*buf;
	int		x;

	x = 0;
	buf = getcwd(NULL, 0);
	while (gen_data->blt->fd_out[x])
		ft_putstr_fd(buf, gen_data->blt->fd_out[x++]);
	printf("\n");
	ft_change_good_status(gen_data->env);
	free(buf);
}
