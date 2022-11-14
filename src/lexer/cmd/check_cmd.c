/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/14 13:19:55 by ndonaire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*obtain_cmd(char **tmp, int i)
{
	int		y;
	int		z;
	char	*cmd;

	z = 0;
	y = 0;
	cmd = malloc(sizeof(char) * (lens(tmp[i]) + 1));
	while (tmp[i][y] == ' ')
		y++;
	while (tmp[i][y] != ' ' && tmp[i][y])
		cmd[z++] = tmp[i][y++];
	cmd[z] = '\0';
	return (cmd);
}

char	*free_for_checkin_cmd(char **sol, char *k, int y, char *cmd)
{
	if (!sol[y])
	{
		k = malloc(sizeof(char) * (lens(cmd) + 1));
		k = ft_substr(cmd, 0, lens(cmd));
		ft_free_arg(sol);
		return (k);
	}
	if (!k)
		return (cmd);
	ft_free_arg(sol);
	return (k);
}

char	*check_cmd(char *cmd, char *env[])
{
	char	*path;
	char	*k;
	char	**sol;
	int		i;
	int		x;

	x = 0;
	path = NULL;
	while (env[x])
	{
		if (ft_strncmp(env[x], "PATH=", 5) == 0)
			path = ft_substr(env[x], 0, ft_strlen(env[x]));
		x++;
	}
	i = 0;
	if (path)
	{
		sol = ft_split(&path[5], ':');
	}
	else
	{
		k = ft_substr(cmd, 0, ft_strlen(cmd));
		return (k);
	}
	k = pseudo_join(sol[i], cmd);
	while (sol[i] && access(k, F_OK) < 0)
	{
		free(k);
		i++;
		if (sol[i])
			k = pseudo_join(sol[i], cmd);
	}
	free(path);
	return (free_for_checkin_cmd(sol, k, i, cmd));
}	
