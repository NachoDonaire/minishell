/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:46:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 15:11:01 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char *arguments, char **env) // NOT FUNCTIONAL (TEMPORARY)
{
	char	*path;
	int		process;
	char	**copy;

	if (arguments[0])
	{
		copy = ft_split(arguments, ' ');
		ft_path(copy[0], env, &path);
		process = execve(path, copy, env);
		if (process == -1)
		{
			//Program exec proof:
			path = "/Users/sasalama/Desktop/salus/minishell/";
			path = ft_strjoin(path, copy[0]);
			process = execve(path, copy, env);
			if (process == -1)
			{
				printf("Minishell: command not found: %s\n", copy[0]);
				ft_change_bad_status(env);
			}
		}
	}
}
