/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:18:47 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/28 19:43:17 by sasalama         ###   ########.fr       */
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

void	ft_not_built(char *s, t_general_data *gen_data, char *env[], int y)
{
	char	**com;
	int		i;

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
	process_args(s, gen_data, y, 0);
	ft_free_arg(com);
	if (gen_data->n_pipes == 0)
	{
		gen_data->sort[0] = '1';
		gen_data->sort[1] = '\0';
	}
}

void	process_string(char *s, t_general_data *gen_data, char *env[], int y)
{
	process_sing_red(gen_data, s, y, 0);
	process_in_red(gen_data, s, y, 0);
	gen_data->built = 0;
	if (gen_data->n_pipes == 0)
		check_builtins(s, gen_data, y);
	if (gen_data->built == 0)
		ft_not_built(s, gen_data, env, y);
}

/*void	process_args(char *s, t_general_data *gen_data, int y)
{
	char	*cp;
	int		i;
	int		z;

	i = 0;
	while (s[i])
		i++;
	cp = malloc(sizeof(char) * (i + 1));
	i = 0;
	z = 0;
	while (s[i])
	{
		if (s[i] == '>' || s[i] == '<')
			break ;
		cp[z++] = s[i++];
	}
	cp[z] = '\0';
	gen_data->cmd[y].args = ft_split(cp, ' ');
	free(cp);
	z = 0;
	while (gen_data->cmd[y].args[z])
	{
		if (check_cmllas(gen_data->cmd[y].args[z]) == 1)
			gen_data->cmd[y].args[z] = gest_cmllas(gen_data->cmd[y].args[z]);
		z++;
	}
	if (!gen_data->cmd[y].args[0])
	{
		gen_data->cmd[y].args = malloc(sizeof(char *) * 1);
		gen_data->cmd[y].args[0] = malloc(sizeof(char ) * 1);
		gen_data->cmd[y].args[0] = NULL;
	}
}
*/

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
}
