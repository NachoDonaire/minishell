/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_pipes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:23:12 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:23:13 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
void	free_check_cmd_pipe(char *com, char **args)
{
	int	y;

	y = 0;
	while (args[y])
		free(args[y++]);
	free(args);
	free(com);
}

void	free_for_args(char **args, int i)
{
	while (args[i])
		free(args[i++]);
}

void	check_cmd_pipe(t_general_data *gen_data, char *s, char *const env[])
{
	int	i;
	int	y;
	char	**args;
	char	*com;

	i = 0;
	y = 0;
	args = ft_split(s, ' ');
	while (y < gen_data->n_pipes)
	{
		while (args[i][0] != '|')
			i++;
		free_for_args(args, i);
		process_string(env, args[0], gen_data);
		if (com)
		{
			gen_data->cmd->cmd[y] = com;
			gen_data->cmd->args = args;
		}
		else
		{
			gen_data->cmd->cmd[y] = NULL;
			gen_data->cmd->args = NULL;
		}
		free_check_cmd_pipe(com, args);
		y++;
		args = ft_split(s, ' ');
		i++;
	}
}

*/
void	n_pipes(t_general_data *gen_data, char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '|' || s[i] == '&')
			gen_data->n_pipes++;
		i++;
	}
}

