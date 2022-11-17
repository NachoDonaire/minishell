/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:38 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 20:35:24 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_arg(char **arguments)
{
	int	i;

	i = 0;
	while (arguments[i])
	{
		free(arguments[i]);
		i++;
	}
	free(arguments);
}

static char	*is_path(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5))
			return (envp[i]);
		i++;
	}
	return (NULL);
}

void	ft_path(char *command, char *envp[], char **fd_path)
{
	char	**paths;
	char	*path;
	char	*commands_path;
	int		i;

	i = -1;
	path = NULL;
	paths = ft_split(ft_strchr(is_path(envp), '/'), ':');
	*fd_path = NULL;
	if (!paths)
		return ;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		commands_path = ft_strjoin(path, command);
		free(path);
		if (access(commands_path, 0) == 0)
		{
			*fd_path = commands_path;
			ft_free_arg(paths);
			return ;
		}
		free(commands_path);
	}
	ft_free_arg(paths);
}

char	**separate_arguments(char *argv)
{
	char	**arguments;

	arguments = ft_split(argv, ' ');
	return (arguments);
}
