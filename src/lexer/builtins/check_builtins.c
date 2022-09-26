/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:49 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 09:53:53 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	args_with_reds(char *copy)
{
	int		i;

	i = 0;
	while (copy[i])
	{
		if (copy[i] == '>' || copy[i] == '<')
			break ;
		i++;
	}
	return (i);
}

void	check_builtins(char *s, t_general_data *gen_data, int y)
{
	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
		|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
		|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		check_builtins2(s, gen_data, y);
	}
}
