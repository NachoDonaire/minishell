/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:58:03 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 18:40:33 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_pwd(t_general_data *gen_data)
{
	char	*buf;
	int		x;

	x = 0;
	if (gen_data->blt->args[2])
	{
		printf("pwd: too many arguments\n");
		ft_change_bad_status(gen_data->env, gen_data);
		return ;
	}
	buf = getcwd(NULL, 0);
	while (gen_data->blt->fd_out[x])
		ft_putstr_fd(buf, gen_data->blt->fd_out[x++]);
	printf("\n");
	ft_change_good_status(gen_data->env, gen_data);
	free(buf);
}
