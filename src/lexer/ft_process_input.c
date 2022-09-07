/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:18:47 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:19:21 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	process_string(char *s, t_general_data *gen_data, char *env[], int y)
{
	char	**com;
	int		i;

	i = 0;
	process_sing_red(gen_data, s, y, 0);
	process_in_red(gen_data, s, y, 0);
	gen_data->built = 0;
	check_builtins(s, gen_data, y);
	gen_data->sort[0] = '0';
	if (gen_data->built == 0)
	{
		gen_data->sort[0] = '1';
		com = ft_split(s, ' ');
		if (finder(com[0], "./") == 1)
		{
			if (check_cmllas(com[0]) == 1)
				com[0] = gest_cmllas(com[i]);
			gen_data->cmd[y].cmd = com[0];
			process_args(s, gen_data, y);
			return ;
		}
		while (com[i])
		{
			if (check_cmllas(com[i]) == 1)
				com[i] = gest_cmllas(com[i]);
			i++;
		}
		gen_data->cmd[y].cmd = check_cmd(com[0], env);
		i = 0;
		process_args(s, gen_data, y);
		while (com[i])
			free(com[i++]);
	}
}

void	process_args(char *s, t_general_data *gen_data, int y)
{
	char	**com;
	int		i;

	i = 0;
	com = ft_split(s, ' ');
	while (com[i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
		i++;
	}
	gen_data->cmd[y].args = com;
}

void	process_input(char *s, t_general_data *gen_data, char *env[])
{
	char	**aux;
	int		i;

	i = 0;
	aux = ft_split(s, ' ');
//	check_builtins(s, gen_data, 0);
//	if (gen_data->built == 1)
//		return ;
	if (finder(s, "|") == 1 || finder(s, "&") == 1)
		process_string_w_pipes(gen_data, s, env);
	else
		process_string(s, gen_data, env, 0);
	while (aux[i])
		free(aux[i++]);
	free(aux);
}
