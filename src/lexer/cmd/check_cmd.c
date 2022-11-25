/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:56 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/25 13:13:42 by sasalama         ###   ########.fr       */
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
		k = ft_substr(cmd, 0, lens(cmd));
		ft_free_arg(sol);
		return (k);
	}
	if (!k)
		return (cmd);
	ft_free_arg(sol);
	return (k);
}

void	check_cmd_no_path(t_general_data *gen_data, char *path)
{
	int	i;
	int	x;

	if (!path)
	{
		x = 0;
		while (gen_data->s_env[x])
		{
			if (ft_strncmp(gen_data->s_env[x], "PATH=", 5) == 0)
			{
				i = ft_strlen(gen_data->s_env[x]);
				path = ft_substr(gen_data->s_env[x], 0, i);
			}
			x++;
		}
	}
}

char	*check_cmd2(char *cmd, char **sol, char *path)
{
	int		i;
	char	*k;

	i = 0;
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

char	*check_cmd(char *cmd, t_general_data *gen_data)
{
	char		*path;
	char		*k;
	char		**sol;
	int			x;

	x = 0;
	path = NULL;
	while (gen_data->env[x])
	{
		if (ft_strncmp(gen_data->env[x], "PATH=", 5) == 0)
			path = ft_substr(gen_data->env[x], 0, ft_strlen(gen_data->env[x]));
		x++;
	}
	check_cmd_no_path(gen_data, path);
	if (path)
		sol = ft_split(&path[5], ':');
	else
	{
		k = ft_substr(cmd, 0, ft_strlen(cmd));
		return (k);
	}
	return (check_cmd2(cmd, sol, path));
}	
