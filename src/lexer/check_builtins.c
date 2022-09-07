/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:49 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 18:02:28 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	paste_in_built(t_general_data *gen_data, char *s)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	while (s[i])
		i++;
	gen_data->blt[gen_data->n_built].blt = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] == ' ')
		i++;
	while (s[i])
		gen_data->blt[gen_data->n_built].blt[z++] = s[i++];
	gen_data->blt[gen_data->n_built].blt[z] = '\0';
}

void	ft_reset_cmd(t_general_data *gen_data, int y)
{
	gen_data->cmd[y].cmd = malloc(1);
	gen_data->cmd[y].args = malloc(1);
	gen_data->cmd[y].args[0] = malloc(1);
	gen_data->cmd[y].args[0] = 0;
	gen_data->cmd[y].out = malloc(1);
	gen_data->cmd[y].in = malloc(1);
	gen_data->cmd[y].out[0] = malloc(1);
	gen_data->cmd[y].out[0] = 0;
	gen_data->cmd[y].in[0] = malloc(1);
	gen_data->cmd[y].in[0] = 0;
}

void	check_builtins(char *s, t_general_data *gen_data, int y)
{
	char	**tmp;
	char	*cp;

	if (extreme_finder(s, "echo") == 1 || extreme_finder(s, "pwd") == 1
		|| extreme_finder(s, "cd") == 1 || extreme_finder(s, "export") == 1
		|| extreme_finder(s, "unset") == 1 || extreme_finder(s, "env") == 1)
	{
		tmp = ft_split(s, ' ');
		paste_in_built(gen_data, tmp[0]);
		cp = ft_substr(s, ft_strlen(gen_data->blt[gen_data->n_built].blt),
				ft_strlen(s));
		gen_data->blt[gen_data->n_built].args = ft_split(cp, ' ');
		free(cp);
		ft_reset_cmd(gen_data, y);
		gen_data->built = 1;
		gen_data->n_built++;
	}
}
