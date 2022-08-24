/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/24 10:56:57 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char *arguments, char **env) // ! NOT FUNCTIONAL (TEMPORARY)
{
	char	*path;
	int		process;
	char	**copy;
	char	*tmp;

	if (arguments[0])
	{
		copy = ft_split(arguments, ' ');
		ft_path(copy[0], env, &path);
		process = execve(path, copy, env);
		if (process == -1)
		{
			// * Program exec proof:
			path = getcwd(NULL, 0);
			tmp = ft_strjoin(path, "/");
			free(path);
			path = ft_strjoin(tmp, copy[0]);
			free(tmp);
			process = execve(path, copy, env);
			if (process == -1)
			{
				printf("Minishell: command not found: %s\n", copy[0]);
				ft_change_bad_status(env);
				return ;
			}
		}
		ft_free_arg(copy);
		ft_change_good_status(env);
	}
}
