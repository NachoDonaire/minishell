/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sasalama < sasalama@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:22:59 by sasalama          #+#    #+#             */
/*   Updated: 2022/09/07 17:23:01 by sasalama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_cmd_pipes(t_general_data *gen_data, char *s, char *env[])
{
	int		i;
	char	**tmp;
	int		y;
	int		z;

	z = 0;
	tmp = ft_split(s, '|');
	i = 0;
	y = 0;
	while (tmp[i])
	{
		if (finder(tmp[i], "&") == 1)
			y = gest_ampersand(tmp[i], gen_data, env, y);
		else
		{
			gen_data->built = 0;
			check_builtins(tmp[i], gen_data, y);
			if (check_cmllas(tmp[i]) == 1)
				tmp[i] = gest_cmllas(tmp[i]);
			if (gen_data->built != 1)
			{
				gen_data->sort[z] = '1';
				process_string(tmp[i], gen_data, env, y);
			}
			else if (gen_data->built == 1)
				gen_data->sort[z] = '0';
			z++;
			y++;
		}
		i++;
	}
	gen_data->sort[z] = '\0';
	gen_data->n_cmd = y;
	free_tmp(tmp);
}

int	gest_ampersand(char *s, t_general_data *gen_data, char *env[], int y)
{
	char	**tmp;
	int		i;

	tmp = ft_split(s, '&');
	i = 0;
	while (tmp[i])
	{
		gen_data->built = 0;
		check_builtins(tmp[i], gen_data, y);
		if (check_cmllas(tmp[i]) == 1)
			tmp[i] = gest_cmllas(tmp[i]);
		if (gen_data->built != 1)
			process_string(tmp[i], gen_data, env, y);
		i++;
		y++;
	}
	free_tmp(tmp);
	return (y);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
}

char	*handle_cont_pipe(char *join)
{
	int	i;

	i = 0;
	if (finder(join, "|") == 1)
	{
		while (join[i] != '|')
			i++;
		join[i] = '\0';
	}
	return (join);
}

void	process_string_w_pipes(t_general_data *gen_data, char *s, char *env[])
{
	handle_cmd_pipes(gen_data, s, env);
}
