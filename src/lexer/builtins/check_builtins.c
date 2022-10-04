/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:49 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/04 21:03:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	check_builtins(char *s, t_general_data *gen_data, int y)
{
	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
		|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
		|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		check_builtins2(s, gen_data, y);
	}
}

void	ft_reset_cmd(t_general_data *gen_data, int y)
{
	gen_data->cmd[y].cmd = malloc(1);
	gen_data->cmd[y].args = malloc(sizeof(char *) * 1);
	gen_data->cmd[y].args[0] = malloc(1);
	gen_data->cmd[y].args[0] = 0;
}
