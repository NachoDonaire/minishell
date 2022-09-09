/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/09 18:18:18 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_child(t_general_data *gen_data, int position)
{
	char	*path;
	int		process;
	char	**copy;
	char	*tmp;

	copy = gen_data->cmd[position].args;
	if (ft_strncmp(copy[0], "./", 2) == 0)
	{
		path = getcwd(NULL, 0);
		tmp = ft_strjoin(path, "/");
		free(path);
		path = ft_strjoin(tmp, copy[0]);
		free(tmp);
		process = execve(path, copy, gen_data->env);
	}
	ft_path(copy[0], gen_data->env, &path);
	process = execve(path, copy, gen_data->env);
	if (process == -1)
	{
		printf("Minishell: command not found: %s\n", copy[0]);
		ft_change_bad_status(gen_data->env);
		exit (0);
	}
}

void	ft_exec(t_general_data *gen_data, int position)
{
	int		pid;
	int		i;

	i = 0;
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	if (gen_data->cmd[position].args[0])
	{
		while (i <= gen_data->n_pipes)
		{
			pid = fork();
			if (pid == 0)
				ft_child(gen_data, position);
			else
				wait(NULL);
			i++;
			position++;
		}
		ft_change_good_status(gen_data->env);
	}
}
