/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:18:47 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/08 12:14:24 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_programm(t_general_data *gen_data, char	**com, int y, char *s)
{
	if (check_cmllas(com[0]) == 1)
		com[0] = gest_cmllas(com[0]);
	gen_data->cmd[y].cmd = com[0];
	process_args(s, gen_data, y);
}

void	ft_not_built(char *s, t_general_data *gen_data, char *env[], int y)
{
	char	**com;
	int		i;

	gen_data->sort[0] = '1';
	com = ft_split(s, ' ');
	if (finder(com[0], "./") == 1)
	{
		ft_programm(gen_data, com, y, s);
		return ;
	}
	i = -1;
	while (com[++i])
	{
		if (check_cmllas(com[i]) == 1)
			com[i] = gest_cmllas(com[i]);
	}
	gen_data->cmd[y].cmd = check_cmd(com[0], env);
	process_args(s, gen_data, y);
	ft_free_arg(com);
}

void	process_string(char *s, t_general_data *gen_data, char *env[], int y)
{
	process_sing_red(gen_data, s, y, 0);
	process_in_red(gen_data, s, y, 0);
	gen_data->built = 0;
	check_builtins(s, gen_data, y);
	gen_data->sort[0] = '0';
	if (gen_data->built == 0)
		ft_not_built(s, gen_data, env, y);
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
	if (finder(s, "|") == 1 || finder(s, "&") == 1)
		process_string_w_pipes(gen_data, s, env);
	else
		process_string(s, gen_data, env, 0);
	while (aux[i])
		free(aux[i++]);
	free(aux);
}
