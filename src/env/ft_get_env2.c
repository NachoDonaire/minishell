/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:19:40 by sasalama          #+#    #+#             */
/*   Updated: 2022/11/17 21:21:25 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**check_env(char **env, char **envp)
{
	char	*buf;

	if (envp[0])
		return (env);
	ft_free_arg(env);
	env = malloc(sizeof(char *) * 5);
	buf = getcwd(0, 0);
	env[0] = ft_strjoin("PWD=", buf);
	free(buf);
	env[1] = ft_substr("SHLVL=1", 0, 8);
	env[2] = ft_substr("_=./minishell", 0, 14);
	env[3] = ft_substr("?=", 0, 3);
	env[4] = 0;
	return (env);
}

void	ft_envs(t_general_data	*gen_data, char **env)
{
	gen_data->env = get_env(env);
	gen_data->env = check_env(gen_data->env, env);
	gen_data->s_env = get_env(env);
	gen_data->s_env = check_env(gen_data->s_env, env);
	ft_check_secret_env(gen_data);
}
