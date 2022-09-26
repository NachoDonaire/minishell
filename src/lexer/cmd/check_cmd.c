/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/26 13:28:49 by ndonaire         ###   ########.fr       */
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
	int		i;
	char	*tmp;

	i = 0;
	if (!sol[y])
	{
		while (sol[i])
			free(sol[i++]);
		k = 0;
	}
	if (!k)
	{
		free(k);
		tmp = ft_substr(cmd, 0, ft_strlen(cmd));
		//free(tmp);
		return (tmp);
	}
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
	while (env[x])
	{
		if (ft_strncmp(env[x], "PATH=", 5) == 0)
			path = ft_substr(env[x], 0, ft_strlen(env[x]));
		x++;
	}
	i = 0;
	sol = ft_split(&path[5], ':');
	k = pseudo_join(sol[i], cmd);
	while (sol[i] && access(k, F_OK) < 0)
	{
		free(k);
		i++;
		if (sol[i])
			k = pseudo_join(sol[i], cmd);
	}
	return (free_for_checkin_cmd(sol, k, i, cmd));
}	
