/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:18:47 by sasalama          #+#    #+#             */
/*   Updated: 2022/10/01 21:30:58 by sasalama         ###   ########.fr       */
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

void	ft_reset_blt(t_general_data *gen_data)
{
	gen_data->blt[gen_data->n_built].blt = malloc(1);
	gen_data->blt[gen_data->n_built].args = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].args[0] = malloc(1);
	gen_data->blt[gen_data->n_built].args[0] = NULL;
	gen_data->blt[gen_data->n_built].out = malloc(sizeof(char *) * 1);
	gen_data->blt[gen_data->n_built].out[0] = malloc(1);
	gen_data->blt[gen_data->n_built].out[0] = NULL;
	gen_data->blt[gen_data->n_built].fd_out = malloc(sizeof(int) * 2);
	gen_data->blt[gen_data->n_built].fd_out[0] = 1;
	gen_data->blt[gen_data->n_built].fd_out[1] = -1;
	gen_data->blt[gen_data->n_built].dred = malloc(1);
	gen_data->blt[gen_data->n_built].in = malloc(sizeof(char) * 1);
	gen_data->blt[gen_data->n_built].in[0] = malloc(1);
	gen_data->blt[gen_data->n_built].in[0] = NULL;
	gen_data->blt[gen_data->n_built].fd_in = malloc(sizeof(int) * 1);
	gen_data->blt[gen_data->n_built].fd_in[0] = -1;

}


void	ft_not_built(char *s, t_general_data *gen_data, char *env[], int y)
{
	char	**com;
	int		i;

	com = dr_comillas(s);
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
	process_args(s, gen_data, y, 0);
	ft_free_arg(com);
	if (gen_data->n_pipes == 0)
	{
		gen_data->sort[0] = '1';
		gen_data->sort[1] = '\0';
		ft_reset_blt(gen_data);
	}
}

void	process_string(char *s, t_general_data *gen_data, char *env[], int y)
{
	process_sing_red(gen_data, s, y, 0);
	process_in_red(gen_data, s, y, 0);
	gen_data->built = 0;
	if (gen_data->n_pipes == 0)
	{
		check_builtins(s, gen_data, y);
	}
	if (gen_data->built == 0)
		ft_not_built(s, gen_data, env, y);
}

void	process_args(char *s, t_general_data *gen_data, int y, int ref)
{
	char	**wallace;
	char	**anthony;

	wallace = dr_comillas(s);
	if (finder(s, ">") == 1)
	{
		anthony = ft_split(s, '>');
		wallace = dr_comillas(anthony[0]);
	}
	else if (finder(s, "<") == 1)
	{
		anthony = ft_split(s, '<');
		wallace = dr_comillas(anthony[0]);
	}
	if (ref == 0)
		gen_data->cmd[y].args = wallace;
	else if (ref == 1)
		gen_data->blt[gen_data->n_built].args = wallace;
}

void	process_input(char *s, t_general_data *gen_data, char *env[])
{
	if (finder(s, "|") == 1 || finder(s, "&") == 1)
		process_string_w_pipes(gen_data, s, env);
	else
	{
		process_string(s, gen_data, env, 0);
		if (gen_data->built == 1)
			gen_data->sort[0] = '0';
		else if (gen_data->built == 0)
			gen_data->sort[0] = '1';
	}
	if (gen_data->built == 1 && gen_data->n_pipes == 0)
	{
		ft_reset_cmd(gen_data, 0);
	}
}
