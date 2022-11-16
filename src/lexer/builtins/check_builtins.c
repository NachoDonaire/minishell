/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:49 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/16 16:40:43 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	check_builtins(char *c, t_general_data *gen_data, int y)
{
	int		i;
	char	*s;

	s = ft_substr(c, 0, ft_strlen(c));
	i = 0;
	while (c[i])
	{
		if (c[i] >= 'A' && c[i] <= 'Z')
			s[i] = c[i] + 32;
		i++;
	}
	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
		|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
		|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		check_builtins2(s, gen_data, y);
	}
	free(s);
}

void	ft_reset_cmd(t_general_data *gen_data, int y)
{
	gen_data->cmd[y].args = malloc(sizeof(char *) * 1);
	gen_data->cmd[y].args[0] = NULL;
}
