/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:18:47 by sasalama          #+#    #+#             */
/*   Updated: 2023/01/04 11:43:12 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	ft_programm(t_general_data *gen_data, char	**com, int y, char *s)
{
	if (check_cmllas(com[0]) == 1)
		com[0] = gest_cmllas(com[0]);
	gen_data->cmd[y].cmd = ft_substr(com[0], 0, ft_strlen(com[0]));
	ft_free_arg(com);
	process_args(s, gen_data, y, 0);
}

void	ft_not_built(char *s, t_general_data *gen_data, int y)
{
	char	**com;
	int		x;

	gen_data->cmd[y].can_exec = 1;
	x = oficial_tukle(s, gen_data, y);
	if (x == 1 || x == 2)
		return ;
	if (gen_data->n_pipes == 0)
	{
		process_sing_red(gen_data, s, y, 0);
		process_in_red(gen_data, s, y, 0);
	}
	com = dr_comillas(s);
	if (finder(com[0], "./") == 1)
	{
		ft_programm(gen_data, com, y, s);
		return ;
	}
	gen_data->cmd[y].cmd = check_cmd(com[0], gen_data);
	process_args(s, gen_data, y, 0);
	ft_free_arg(com);
	gen_data->n_cmd++;
	ft_not_built2(gen_data);
}

void	process_string(char *s, t_general_data *gen_data, int y)
{
	if (gen_data->n_pipes > 0)
	{
		gen_data->cmd[y].can_exec = 1;
		if (oficial_tukle(s, gen_data, y) == 1)
			return ;
		else if (oficial_tukle(s, gen_data, y) == 2)
			return ;
		process_sing_red(gen_data, s, y, 0);
		process_in_red(gen_data, s, y, 0);
	}
	gen_data->built = 0;
	if (gen_data->n_pipes == 0)
		check_builtins(s, gen_data, y);
	if (gen_data->built == 0)
		ft_not_built(s, gen_data, y);
}

void	process_args(char *s, t_general_data *gen_data, int y, int ref)
{
	char	**wallace;
	char	**anthony;

	wallace = dr_comillas(s);
	if (finder(s, ">") == 1)
	{
		anthony = ft_split(s, '>');
		ft_free_arg(wallace);
		wallace = dr_comillas(anthony[0]);
		ft_free_arg(anthony);
	}
	else if (finder(s, "<") == 1)
	{
		anthony = ft_split(s, '<');
		ft_free_arg(wallace);
		wallace = dr_comillas(anthony[0]);
		ft_free_arg(anthony);
	}
	if (ref == 0)
		gen_data->cmd[y].args = wallace;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].args = wallace;
}

void	process_input(char *s, t_general_data *gen_data, char *env[])
{
	if (gen_data->n_pipes > 0)
		process_string_w_pipes(gen_data, s, env);
	else
	{
		process_string(s, gen_data, 0);
		if (gen_data->built == 1)
			gen_data->sort[0] = '0';
		else if (gen_data->built == 0)
			gen_data->sort[0] = '1';
	}
}
