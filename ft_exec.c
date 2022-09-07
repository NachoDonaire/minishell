/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:56:52 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 13:59:58 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(t_general_data *gen_data, int position) // ! NOT FUNCTIONAL (TEMPORARY)
{
	char	*path;
	int		process;
	char	**copy;
	char	*tmp;

	if (gen_data->cmd[position].args[0])
	{
		copy = gen_data->cmd[position].args;
		ft_path(copy[0], gen_data->env, &path);
		process = execve(path, copy, gen_data->env);
		if (process == -1)
		{
			// * Program exec proof:
			path = getcwd(NULL, 0);
			tmp = ft_strjoin(path, "/");
			free(path);
			path = ft_strjoin(tmp, copy[0]);
			free(tmp);
			process = execve(path, copy, gen_data->env);
			if (process == -1)
			{
				printf("Minishell: command not found: %s\n", copy[0]);
				ft_change_bad_status(gen_data->env);
				return ;
			}
		}
		ft_change_good_status(gen_data->env);
	}
}
