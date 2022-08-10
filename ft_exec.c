/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama <sasalama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:46:14 by sasalama          #+#    #+#             */
/*   Updated: 2022/08/10 14:15:37 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char *arguments, char **env) // NOT FUNCTION (TEMPORARY)
{
	char	*path;
	int		process;
	char	**copy;

	ft_path(arguments, env, &path);
	copy = malloc(sizeof(char*));
	copy[0] = arguments;
	copy[1] = NULL;
	process = execve(path, copy, env);
	if (process == -1)
		ft_change_bad_status(env);
}
